#include "generators.hpp"
#include <iostream>
#include <string>
#include "luhn_algoritm.hpp"

std::string generate_pin() {
    std::string pin = "";
    for (int i = 0; i < 4; i++) {
        int d = rand() % 10;
        std::string digit = std::to_string(d);
        pin.append(digit);
    }
    return pin;
}
std::string generate_cvv() {
    std::string cvv = "";
    for (int i = 0; i < 3; i++) {
        int d = rand() % 10;
        std::string digit = std::to_string(d);
        cvv.append(digit);
    }
    return cvv;


}
std::string generate_card_index() {
    std::string index_visa = "4";
    int k = 1; int ri = rand() % 2;//рандомный выбор типа карты, при необходимости заменить
    if (ri == 1) {
        std::string index_visa = "4";
        for (int i = 0; i < 15; i++) {
            short r = 0 + rand() % 10;
            std::string r1 = std::to_string(r);
            index_visa.append(r1);
        }
        if (is_valid_luhn(index_visa) == true) {
            return index_visa;
        }
        else {
            return generate_card_index();
        }
    }
    else {
        std::string index_master_card = "5";
        for (int i = 0; i < 15; i++) {
            short r = 0 + rand() % 10;
            std::string r1 = std::to_string(r);
            index_master_card.append(r1);
        }
        if (is_valid_luhn(index_master_card) == true) {
            return index_master_card;
        }
        else {
            return generate_card_index();
        }
    }
}
