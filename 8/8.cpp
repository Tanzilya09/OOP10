#include <iostream>
#include <string>
using namespace std;


class StringTooLong {
public:
    string message;
    StringTooLong(const string& msg) : message(msg) {}

    void showMessage() const {
        cout << message << endl;
    }
};
class Str {
private:
    string str;

public:
    Str(const string& s) {
        if (s.length() > 50)
            throw StringTooLong("Ошибка: строка инициализации слишком длинная!");
        str = s;
    }

    Str operator+(const Str& other) {
        if (str.length() + other.str.length() > 50)
            throw StringTooLong("Ошибка: результат конкатенации слишком длинный!");
        return Str(str + other.str);
    }
    void display() const {
        cout << "Строка: " << str << endl;
    }
};
int main() {
    setlocale(LC_ALL, "Rus");
    try {
        Str s1("Hello");
        Str s2("World");

        Str s3 = s1 + s2;
        s3.display();

        Str s4("Очень длинная,длинная,длинная,длинная,длинная строка");      

    }
    catch (StringTooLong& e) {
        e.showMessage();
    }

    try {
        Str s5("Строка ");
        Str s6("нормальная");
        Str s7 = s5 + s6;
        s7.display();
    }
    catch (StringTooLong& e) {
        e.showMessage();
    }

    return 0;
}
