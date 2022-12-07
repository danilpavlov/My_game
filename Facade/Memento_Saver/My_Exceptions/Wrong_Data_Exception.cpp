//
// Created by Даниил Павлов on 23.11.2022.
//

#include "Wrong_Data_Exception.h"

const std::string Wrong_Data_Exception::what(){
    return "File got wrong data: " + error_message;
}

Wrong_Data_Exception::Wrong_Data_Exception(std::string message) {
    error_message = message;
}
