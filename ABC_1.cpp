#include <iostream>
#include <string>
#include <cmath>

int convertToDecimal(const std::string& number, int base) {
    int decimalValue = 0;
    int length = number.length();

    for (int i = 0; i < length; ++i) {
        char digit = number[length - 1 - i];
        int value;

        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        }
        else if (digit >= 'a' && digit <= 'f') {
            value = digit - 'a' + 10;
        }
        else {
            std::cerr << "Недопустимый символ: " << digit << std::endl;
            return -1;
        }
        if (value >= base) {
            std::cerr << "Цифра " << digit << " недопустима для основания " << base << std::endl;
            return -1;
        }

        decimalValue += value * std::pow(base, i);
    }

    return decimalValue;
}

int main() {
    setlocale(LC_ALL, "Ru");
    std::string number;
    int base;

    std::cout << "Введите число: ";
    std::cin >> number;
    std::cout << "Введите основание системы счисления (от 2 до 16): ";
    std::cin >> base;

    if (base < 2 || base > 16) {
        std::cerr << "Основание должно быть в диапазоне от 2 до 16." << std::endl;
        return 1;
    }

    int decimalValue = convertToDecimal(number, base);
    if (decimalValue != -1) {
        std::cout << "Десятичное значение: " << decimalValue << std::endl;
    }

    return 0;
}