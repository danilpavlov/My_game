//
// Created by Даниил Павлов on 13.10.2022.
//

#ifndef MY_GAME_FIELD_MESSAGE_H
#define MY_GAME_FIELD_MESSAGE_H
#include "../Message.h"

class Field_Message : public Message {
public:
    enum type{FIRST_LEVEL, SECOND_LEVEL};
    std::string get_message(int key) override;

};


#endif //MY_GAME_FIELD_MESSAGE_H
