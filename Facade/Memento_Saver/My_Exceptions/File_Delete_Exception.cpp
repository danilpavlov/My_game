//
// Created by Даниил Павлов on 23.11.2022.
//

#include "File_Delete_Exception.h"

const std::string File_Delete_Exception::what(){
    return "Save file was deleted: " + error_message;
}

File_Delete_Exception::File_Delete_Exception(std::string message) {
    error_message = message;
}
