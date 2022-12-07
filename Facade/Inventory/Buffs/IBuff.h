//
// Created by Даниил Павлов on 25.11.2022.
//

#ifndef MY_GAME_IBUFF_H
#define MY_GAME_IBUFF_H
#include "../../Singleton/Singleton_Hero.h"

class IBuff {
public:
    enum type{XP_BUFF, ANTI_ENEMY_BUFF, MOVE_BUFF};
    enum part{WEAPON, MASK};
    virtual void execute() = 0;
    virtual type get_type() = 0;
    virtual part get_part() = 0;
};


#endif //MY_GAME_IBUFF_H
