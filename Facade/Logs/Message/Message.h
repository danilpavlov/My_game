//
// Created by Даниил Павлов on 30.09.2022.
//

#ifndef MY_GAME_MESSAGE_H
#define MY_GAME_MESSAGE_H
#include <string>
#include <iostream>

class Message {
public:
    virtual std::string get_message(int key) = 0;
};


#endif //MY_GAME_MESSAGE_H
