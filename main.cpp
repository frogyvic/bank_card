#include <string>
#include <random>
#include <time.h>
#include <cctype>
#include <iostream>
#include "generators.hpp"
#include "valid_index_and_pin.hpp"
#include "visual_functions.hpp" 
#include "bank_functions.hpp"






int main() {
    srand(time(0));
    setlocale(LC_ALL, "");
    std::string index = generate_card_index();
    std::string pin_code = generate_pin();
    std::string cvv_code = generate_cvv();
    int cash = rand() % 50000;
    int rubles_on_card=0;
    int dollars_on_card = 0;
    int exchange_rate = 70 + rand() % 31;
    cout_hello_menu(index, pin_code, cvv_code);
    bool correct_data = false;

    while (correct_data == false) {
        index = "1"; pin_code = "1";//ИЗМЕНИТЬ ПРИ СБОРКЕ!
        std::string card_index_from_user; std::string pin_code_from_user;
        std::cout << "Добро пожаловать в Кошелеффф Банк, введите ваши реквизиты(без пробелов)\n" << "Номер карты: ";
        std::cin >> card_index_from_user;
        std::cout << "Пин-код: ";
        std::cin >> pin_code_from_user;
        correct_data = is_valid_enter_data(card_index_from_user, index, pin_code_from_user, pin_code);
        if (correct_data == false) {
            std::cout << "Неправильно введенный номер карты или пин-код\n";
        }
    }
    int window = 0;
    bool stopper=false;
    while (stopper==false) {
        std::cout << "======================================================================\n";
        main_menu();
        if (std::cin >> window) {
            switch (window) {
            case 1:
                std::cout << "======================================================================\n";
                bank_account(rubles_on_card, dollars_on_card, cash); break;
            case 2:
                std::cout << "======================================================================\n";
                change_pin(pin_code); break;
            case 3: 
                std::cout << "======================================================================\n";
                currency_shop(rubles_on_card, dollars_on_card,exchange_rate); break;
            case 2812:
                stopper=true;break;
            default:
                std::cout << "======================================================================\n";
                std::cout << "Неизвестное окно" << std::endl;
            }
        }
        else {
            std::cout << "======================================================================\n";
            std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
           std::cin.clear();
           std::cin.ignore();

        }
    }
}
    