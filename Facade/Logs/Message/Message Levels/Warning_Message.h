//
// Created by Даниил Павлов on 13.10.2022.
//

#ifndef MY_GAME_WARNING_MESSAGE_H
#define MY_GAME_WARNING_MESSAGE_H
#include "../Message.h"

class Warning_Message : public Message {
public:
    enum type{HERO_CANT_MOVE_ON_ROCK, HERO_CANT_WIN_YET, TOO_MUCH_HP,};

    std::string get_message(int key) override;

};


#endif //MY_GAME_WARNING_MESSAGE_H
