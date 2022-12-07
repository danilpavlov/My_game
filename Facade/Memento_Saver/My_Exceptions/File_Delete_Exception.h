//
// Created by Даниил Павлов on 23.11.2022.
//

#ifndef MY_GAME_FILE_DELETE_EXCEPTION_H
#define MY_GAME_FILE_DELETE_EXCEPTION_H
#include <iostream>
#include <exception>

class File_Delete_Exception : public std::exception{
public:
    explicit File_Delete_Exception(std::string message);
    const std::string what();
private:
    std::string error_message;
};


#endif //MY_GAME_FILE_DELETE_EXCEPTION_H
