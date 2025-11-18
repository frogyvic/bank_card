#include <iostream>
#include <string>
#include "valid_index_and_pin.hpp"


bool is_valid_enter_data(std::string card_index_from_user,std::string card_index,std::string pin_code_from_user, std::string pin_code) {
    if ((card_index == card_index) && (pin_code == pin_code_from_user)) {
        return true;
    }
    else {
        return false;
    }    
}
