#include <iostream>
#include <string>
#include "visual_functions.hpp"

void index_output(std::string card_index) {
    for (int i = 1; i < 4; i++) {//нормальный вывод номера карты шоб пользователю норм было
        card_index.insert(i * 5 - 1, " ");
    }
    std::cout << card_index;
}
void cout_hello_menu(std::string index,std::string pin_code,std::string cvv_code) {
    std::cout << "       Добро пожаловать в Кошелеффф Банк, ваши реквизиты(запомните их для входа в систему):\n";
    std::cout << "Номер карты: "; index_output(index); std::cout << "\n";
    std::cout << "Пин-код: " << pin_code << "\n";
    std::cout << "CVV-код: " << cvv_code << "\n";
}
