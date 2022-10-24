//
// Created by Даниил Павлов on 13.10.2022.
//

#ifndef MY_GAME_HERO_MOVES_MESSAGE_H
#define MY_GAME_HERO_MOVES_MESSAGE_H
#include "../Message.h"
#include "../../../Singleton/Singleton_Hero.h"

class Hero_Moves_Message : public Message {
public:
    enum type{HERO_MOVE_LEFT, HERO_MOVE_RIGHT, HERO_MOVE_UP, HERO_MOVE_DOWN};
    std::string get_message(int key) override;

};


#endif //MY_GAME_HERO_MOVES_MESSAGE_H
