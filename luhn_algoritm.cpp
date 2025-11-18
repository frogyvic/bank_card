#include <iostream>
#include <string>


bool is_valid_luhn(std::string card_index) {
    int sum = 0;
    for (int i = 1; i <= 15; i += 2) {// Проходим по строке справа налево по каждой второй
        char c = card_index[i];
        int digit = c - '0';//символ в цифру
        digit *= 2;//удвоение числа
        if (digit >= 10) {
            digit -= 9;//отнимаем 9 если больше чем 9
        }
        sum += digit;
    }
    if (sum % 10 == 0) {
        if (sum % 10 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}
