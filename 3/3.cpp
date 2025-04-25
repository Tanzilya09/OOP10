#include <iostream>
using namespace std;

template <typename T>
class safearray {
private:
    T arr[10]; 
public:
    T& operator[](int index) {
        if (index < 0 || index >= 10) {
            cout << "Ошибка: индекс " << index << " вне границ!" << endl;
            exit(1);
        }
        return arr[index];
    }
};

int main() {
    setlocale(LC_ALL, "Rus"); 
    safearray<int> intArray;
    cout << "Введите массив(int): ";
    for (int i = 0; i < 5; i++) {
        cin >> intArray[i];
    }
    cout << "intArray: ";
    for (int i = 0; i < 5; i++)
        cout << intArray[i] << " ";
    cout << endl;

    safearray<float> floatArray;
    cout << "Введите массив(float): ";
    for (int i = 0; i < 5; i++) {
        cin >> floatArray[i];
    }

    cout << "floatArray: ";
    for (int i = 0; i < 5; i++)
        cout << floatArray[i] << " ";
    cout << endl;

    return 0;
}
