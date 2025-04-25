#include <iostream>
using namespace std;

template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int x = 5, y = 10;
    cout << "До swap (int): x = " << x << ", y = " << y << endl;
    swaps(x, y);
    cout << "После swap (int): x = " << x << ", y = " << y << endl;

    float a = 1.5f, b = 3.2f;
    cout << "\nДо swap (float): a = " << a << ", b = " << b << endl;
    swaps(a, b);
    cout << "После swap (float): a = " << a << ", b = " << b << endl;

    char c1 = 'A', c2 = 'B';
    cout << "\nДо swap (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    swaps(c1, c2);
    cout << "После swap (char): c1 = " << c1 << ", c2 = " << c2 << endl;

    return 0;
}
