//
// Created by Даниил Павлов on 16.10.2022.
//

#ifndef MY_GAME_SYSTEM_MESSAGES_H
#define MY_GAME_SYSTEM_MESSAGES_H
#include "../Message.h"

class System_Messages : public Message{
public:
    enum type{JOY_DIVISION, HAVE_A_NICE_LIFE, THE_SMITHS, ECCO2K,
            FILE_CONTROL, STANDART_CONTROL};

    std::string get_message(int key);

};


#endif //MY_GAME_SYSTEM_MESSAGES_H
