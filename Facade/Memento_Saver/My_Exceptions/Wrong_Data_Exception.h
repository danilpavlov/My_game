//
// Created by Даниил Павлов on 23.11.2022.
//

#ifndef MY_GAME_WRONG_DATA_EXCEPTION_H
#define MY_GAME_WRONG_DATA_EXCEPTION_H
#include <iostream>
#include <exception>

class Wrong_Data_Exception : public std::exception{
public:
    explicit Wrong_Data_Exception(std::string message);
    const std::string what();
private:
    std::string error_message;

};


#endif //MY_GAME_WRONG_DATA_EXCEPTION_H
