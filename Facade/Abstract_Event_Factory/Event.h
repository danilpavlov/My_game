//
// Created by Даниил Павлов on 26.09.2022.
//

#ifndef MY_GAME_EVENT_H
#define MY_GAME_EVENT_H
#include "../Singleton/Singleton_Hero.h"
#include "../Field/Field.h"
#include "../Inventory/Buffs/Buff_Table.h"


class Event{
public:
    virtual void do_event(Field* field) = 0;

};


#endif //MY_GAME_EVENT_H
