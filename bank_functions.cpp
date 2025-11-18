#include <iostream>
#include <string>
#include "bank_functions.hpp"

void bank_account( int& rubles, int& dollars,int& cash) {
    if ((rubles == 0) && (dollars == 0)) {
        std::cout << "похоже, на вашем счету совсем нет денег(вы чо нищи типа?)\n";
    }
    if (rubles != 0) {
        std::cout << "на вашем счету ";std::cout<< rubles; std::cout << " руб.\n";
    }
    if (dollars != 0) {
        std::cout << "на вашем счету "; std::cout << dollars; std::cout << " дол.\n";
    }
    std::cout << "Кажется мне, что у вас на руках "; std::cout << cash; std::cout << " рублей\n\n";
    std::cout << "       что желаете сделать со счётом?\n0) вернуться в главное меню\n1) пополнить счёт\n2) снять денег\n";
    bool operations_finish = false;
    while (operations_finish == false) {
        int window1; int value = 0;
        if (std::cin >> window1) {
            switch (window1) {
            
            case 0:
                operations_finish = true; break;
            case 1:
                if (cash == 0) {
                    std::cout << " у тебя на руках совсем нет денег, нечего класть на счет\n"; operations_finish = true; break;
                }
                std::cout << "введите сколько рублей хотите положить на счёт: "; if (std::cin >> value) {
                    if (cash < value) {
                        std::cout << "\nУ вас недостаточно рублей, на счет будет положена максимально возможная сумма\n\n";
                        rubles += cash; cash = 0; operations_finish = true; break;
                    }
                    if (value < 0) {
                        std::cout << "На счет нельзя положить отрицательное кол-во рублей\n"; break;
                    }
                    rubles += value; cash -= value;
                    std::cout << "Успешно!\n\n"; operations_finish = true; break;
                }
                else {
                    std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    operations_finish = true; break;
                }
            case 2:
                if (rubles == 0) {
                    std::cout << " на счету совсем нет рублей, пополните счет или обменяйте валюту на рубли для снятия\n"; operations_finish = true; break;
                }
                std::cout << "введите сколько рублей хотите снять: "; if (std::cin >> value) {
                    if (rubles < value) {
                        std::cout << "\nУ вас недостаточно рублей на счету, вам будет выдано максимально возможное количество\n\n";
                        cash+=rubles; rubles = 0; operations_finish = true; break;
                    }
                    if (value < 0) {
                        std::cout << "Со счета нельзя снять отрицательное количecтво рублей\n"; break;
                    }
                    rubles -= value; cash += value;
                    std::cout << "Успешно! \n\n"; operations_finish = true; break;
                }
                else {
                    std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(); operations_finish = true; break;
                }
            default:
                std::cout << "Неизвестная функция, попробуйте снова" << std::endl; break;
            }
        }
        else {
            std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
            operations_finish = true;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    
}
void change_pin(std::string& pin_code) {
    std::cout << "       Похоже вы хотите сменить свой пин-код,это правда?" << std::endl;
    int new_pin; int old_pin;
    std::cout << "0)нет, я хочу вернуться в главное меню\n1)да, я хочу сменить свой старый пинкод" << std::endl;
    if (std::cin >> new_pin) {
       
        if (new_pin==0){
        }
        else {
            std::cout << "Пожалуйста, введите свой старый пин-код";
            if (std::cin >> old_pin) {
                if (std::to_string(old_pin) == pin_code) {
                    std::cout << "Отлично, а теперь придумайте новый пин-код: ";
                    if (std::cin >> new_pin) {
                        std::string str_pin = std::to_string(new_pin);
                        if ((new_pin < 0) || (str_pin.length() != 4)) {
                            std::cout << "Некорректный новый пинкод, введите четырехзначное число без пробелов или иных символов\n\n";
                        }
                        else {
                            pin_code = str_pin;
                            std::cout << "Пин-код успешно изменен!\n\n";
                        }

                    }
                    else {
                        std::cout << "Некорректный новый пинкод, введите четырехзначное число без пробелов или иных символов\n\n";
                    }
                }
                else {
                    std::cout << "Неправильный пин-код\n\n";
                }
            }
            else {
                std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
    else {
        std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }


}
void currency_shop(int& rubles, int& dollars, int e_rate) {
    bool operations_finish = false;
    std::cout << "       Cегодня как никогда благоприятный курс!всего-лишь " << e_rate << " руб. к 1-му дол.\n";
    if ((rubles < e_rate) && (dollars == 0)) {
        std::cout << "Ой, кажется вам совсем нечего менять! внесите на счет деньги и возвращайтесь снова\n\n";
    }
    else{
        std::cout << "Что бы вы хотели сделать?\n0)вернуться в главное меню\n1)Купить доллары\n2)Купить рубли\n";
        while (operations_finish == false) {
            int window2; int value = 0;
            if (std::cin >> window2) {
                switch (window2) {
                case 0:
                    operations_finish = true; break;
                case 1:
                    std::cout << "сколько долларов вы хотели бы купить?\n";
                    if (std::cin >> value) {
                        if (value < 0) {
                            std::cout << "Нельзя купить отрицательное количество долларов, пожалуйста, попробуйте снова";
                            break;
                        }
                        if (value * e_rate > rubles) {
                            std::cout << "Кажется у вас недостаточно рублей, вам будет предоставлено максимально возможное количество долларов\n\n";
                            value = rubles / e_rate; dollars += value; rubles -= value * e_rate;
                            operations_finish = true; break;
                        }
                        else {
                            std::cout << "Успешно!\n\n";
                            dollars += value; rubles -= value * e_rate;
                            operations_finish = true; break;
                        }
                    }
                    else {
                        std::cout << "Некорректный ввод,пожалуйста,введите целое количество валюты, которую вы хотите купить" << std::endl;
                        operations_finish = true;
                        std::cin.clear();
                        std::cin.ignore(); break;
                    }
                case 2:
              
                    std::cout << "сколько рублей вы хотели бы купить?\n";
                    if (std::cin >> value) {
                        if (value < 0) {
                            std::cout << "Нельзя купить отрицательное количество рублей, пожалуйста, попробуйте снова";
                            break;
                        }
                        if (value / e_rate > (dollars-1)) {
                            std::cout << "Кажется у вас недостаточно долларов, вам будет предоставлено максимально возможное количество рублей\n\n";
                           
                            value = dollars*e_rate;  rubles += value; dollars -= value/e_rate;
                            operations_finish = true; break;
                        }
                        else {
                            std::cout << "Успешно!\n\n";
                            dollars -= (value)/e_rate+1; rubles += (value/e_rate)*e_rate+(value-value%e_rate);
                            operations_finish = true; break;
                        }
                    }
                    else {
                        std::cout << "Некорректный ввод,пожалуйста,введите целое количество валюты, которую вы хотите купить" << std::endl;
                        operations_finish = true;
                        std::cin.clear();
                        std::cin.ignore(); break;
                    }
                default:
                    std::cout << "Неизвестная функция, попробуйте снова" << std::endl; break;

                }
            }
            else {
                std::cout << "Некорректный ввод,пожалуйста,попробуйте снова" << std::endl;
                operations_finish = true;
                std::cin.clear();
                std::cin.ignore();
            }
        }
    }
}


