#include <iostream>
using namespace std;

template <typename T>
T amax(T* arr, int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int arrInt[] = { 1, 5, 3, 9, 2 };
    float arrFloat[] = { 1.0, 3.5, 0.9, 4.8 };
    char arrChar[] = { 'a', 'z', 'm', 'b' };

    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);
    int sizeFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    int sizeChar = sizeof(arrChar) / sizeof(arrChar[0]);

    cout << "Максимум в int-массиве: " << amax(arrInt, sizeInt) << endl;
    cout << "Максимум в float-массиве: " << amax(arrFloat, sizeFloat) << endl;
    cout << "Максимум в char-массиве: " << amax(arrChar, sizeChar) << endl;

    return 0;
}
