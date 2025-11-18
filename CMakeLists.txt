cmake_minimum_required(VERSION 3.15)


set(PROJECT_NAME bank_card)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_EXECUTABLE("${PROJECT_NAME}" main.cpp
    generators.cpp
    luhn_algoritm.cpp
    valid_index_and_pin.cpp
    visual_functions.cpp
    bank_functions.cpp
)