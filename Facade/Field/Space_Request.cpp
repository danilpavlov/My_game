//
// Created by Даниил Павлов on 21.09.2022.
//

#include "Space_Request.h"


int Space_Request::get_x() {
    try{
        std::stoi(input_x);
    }
    catch (std::exception){
        return 155;
    }
    if (std::stoi(input_x) <= 0){
        return 155;
    }
    return std::stoi(input_x);
}

int Space_Request::get_y() {
    try{
        std::stoi(input_y);
    }
    catch (std::exception){
        return 24;
    }

    if (std::stoi(input_y) <= 0){
        return 24;
    }
    return std::stoi(input_y);
}

Space_Request::Space_Request() {

    char spring_green[] = { 0x1b, '[', '3', '8',';','5',';','4','1','m',0 };    // цвет для текста обращения к пользователю
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };  // дефолт цвет для замещения

    std::cout << spring_green << "Please, type the width of playing field\n" << normal;
    getline(std::cin, input_x);
    std::cout << spring_green << "Please, type the height of playing field\n" << normal;
    getline(std::cin, input_y);
    system("clear");
}
