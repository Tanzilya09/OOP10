#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileError {
public:
    string message;
    FileError(const string& msg) : message(msg) {}

    void showMessage() const {
        cout << "Ошибка: " << message << endl;
    }
};

class dofile {
private:
    fstream file;
public:
    dofile(const string& filename) {
        file.open(filename, ios::in | ios::out | ios::binary);
        if (!file) {
            throw FileError("Не удалось открыть файл: " + filename);
        }
    }
    string readFile() {
        if (!file) {
            throw FileError("Файл не открыт для чтения.");
        }
        string content;
        getline(file, content);
        return content;
    }

    void writeFile(const string& content) {
        if (!file) {
            throw FileError("Файл не открыт для записи.");
        }
        file << content << endl;
    }
    void resetPosition() {
        if (!file) {
            throw FileError("Ошибка при перемещении указателя в начало файла.");
        }
        file.seekg(0, ios::beg);
        file.seekp(0, ios::beg);
    }
    ~dofile() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    try {
        dofile fileHandler("example.txt");
        fileHandler.writeFile("Тестовой файл");
        fileHandler.resetPosition();
        string content = fileHandler.readFile();
        cout << "Содержимое файла: " << content << endl;

    }
    catch (FileError& e) {
        e.showMessage();
    }

    return 0;
}
