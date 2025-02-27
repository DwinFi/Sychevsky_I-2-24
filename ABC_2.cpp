#include <iostream>
#include <bitset>

using namespace std;

void printIEEE754(float num) {
    unsigned int* p = reinterpret_cast<unsigned int*>(&num);
    unsigned int sign = (*p >> 31) & 0x01;
    unsigned int exponent = ((*p >> 23) & 0xFF) - 127; // смещение
    unsigned int mantissa = *p & 0x7FFFFF;

    cout << "Число " << num << " в формате IEEE 754:" << endl;
    cout << "Знак: " << sign << endl;
    cout << "Экспонента (с учетом смещения): " << exponent + 127 << " (бинарно: " << bitset<8>(((*p >> 23) & 0xFF)) << ")" << endl;
    cout << "Мантисса: " << mantissa << " (бинарно: " << bitset<23>(mantissa) << ")" << endl;
    cout << "Бинарное представление: " << bitset<32>(*p) << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    float number;

    cout << "Введите число в десятичной системе: ";
    cin >> number;

    printIEEE754(number);

    return 0;
}
