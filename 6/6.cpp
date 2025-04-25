#include <iostream>
using namespace std;


class IndexOutOfBounds {
private:
    int badIndex;
public:
    IndexOutOfBounds(int index) : badIndex(index) {}

    void message() const {
        cout << "Ошибка: индекс " << badIndex
            << " выходит за пределы массива (допустимый диапазон: 0.." << 10 - 1 << ")!" << endl;
    }
};
class safearray {
private:
    int arr[10];
public:
    int& operator[](int index) {
        if (index < 0 || index >= 10)
            throw IndexOutOfBounds(index);
        return arr[index];
    }
};
int main() {
    setlocale(LC_ALL, "Rus"); 
    safearray sa;

    try {
        for (int i = 0; i <= 10; i++) { 
            sa[i] = i * 2;
            cout << "sa[" << i << "] = " << sa[i] << endl;
        }
    }
    catch (IndexOutOfBounds& ex) {
        ex.message();
    }

    return 0;
}
