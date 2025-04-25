#include <iostream>
#include <cstdlib> 
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return abs(a);
    return gcd(b, a % b);
}

template <typename T>
class frac {
private:
    T num; 
    T den; 
    void reduce() { 
        int g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) { 
            num = -num;
            den = -den;
        }
    }
public:
    frac(T n = 0, T d = 1) : num(n), den(d) {
        if (d == 0) {
            cout << "Ошибка: знаменатель не может быть 0!" << endl;
            exit(1);
        }
        reduce();
    }

    void print() const {
        cout << static_cast<int>(num) << "/" << static_cast<int>(den);
    }

    frac operator+(const frac& f) const {
        return frac(num * f.den + f.num * den, den * f.den);
    }
    frac operator-(const frac& f) const {
        return frac(num * f.den - f.num * den, den * f.den);
    }
    frac operator*(const frac& f) const {
        return frac(num * f.num, den * f.den);
    }
    frac operator/(const frac& f) const {
        return frac(num * f.den, den * f.num);
    }
};
int main() {
    setlocale(LC_ALL, "Rus");   
    frac<char> f1(1, 3);
    frac<char> f2(1, 6);

    cout << "Первая дробь: "; f1.print(); cout << endl;
    cout << "Вторая дробь: "; f2.print(); cout << endl;

    frac<char> sum = f1 + f2;
    frac<char> diff = f1 - f2;
    frac<char> prod = f1 * f2;
    frac<char> quot = f1 / f2;

    cout << "\nСумма: "; sum.print(); cout << endl;
    cout << "Разность: "; diff.print(); cout << endl;
    cout << "Произведение: "; prod.print(); cout << endl;
    cout << "Частное: "; quot.print(); cout << endl;

    return 0;
}
