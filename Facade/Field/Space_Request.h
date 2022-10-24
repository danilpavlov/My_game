//
// Created by Даниил Павлов on 21.09.2022.
//

#ifndef MY_GAME_SPACE_REQUEST_H
#define MY_GAME_SPACE_REQUEST_H
#include <string>
#include <iostream>
#include <exception>

class Space_Request {
private:
    std::string input_x;
    std::string input_y;

public:
    Space_Request();

    int get_x();
    int get_y();


};


#endif //MY_GAME_SPACE_REQUEST_H
