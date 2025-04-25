#include <iostream>
#include <string>
using namespace std; 
class DistanceError {
public:
    virtual void message() const = 0;
};

class InvalidInches : public DistanceError {
private:
    int value;
public:
    InvalidInches(int v) : value(v) {}

    void message() const override {
        cout << "Ошибка: значение дюймов " << value << " недопустимо (должно быть < 12)" << endl;
    }
};

class NonNumericInput : public DistanceError {
private:
    string input;
public:
    NonNumericInput(string in) : input(in) {}
    void message() const override {
        cout << "Ошибка: \"" << input << "\" — не числовое значение" << endl;
    }
};

class TooManyDigits : public DistanceError {
public:
    void message() const override {
        cout << "Ошибка: число содержит слишком много цифр" << endl;
    }
};

class EmptyInput : public DistanceError {
public:
    void message() const override {
        cout << "Ошибка: ввод пустой" << endl;
    }
};
int isint(const string& s) {
    if (s.empty())
        throw EmptyInput();
    if (s.length() > 5) 
        throw TooManyDigits();

    for (char c : s) {
        if (!isdigit(c))
            throw NonNumericInput(s);
    }

    return stoi(s);
}
class Distance {
private:
    int feet;
    float inches;
public:
    Distance(int f, float in) {
        if (in >= 12.0f)
            throw InvalidInches(in);
        feet = f;
        inches = in;
    }

    void showdist() const {
        cout << feet << "\'-" << inches << "\"" << endl;
    }
};
int main() {
    setlocale(LC_ALL, "Rus"); 
    Distance dist(0, 0);

    while (true) {
        try {
            string inputFeet, inputInches;
            cout << "Введите футы: ";
            getline(cin, inputFeet);
            int feet = isint(inputFeet);

            cout << "Введите дюймы: ";
            getline(cin, inputInches);
            int inches = isint(inputInches);

            dist = Distance(feet, inches);
            break;
        }
        catch (DistanceError& e) {
            e.message();
            cout << "Повторите ввод...\n";
        }
    }

    cout << "Вы ввели расстояние: ";
    dist.showdist();

    return 0;
}
