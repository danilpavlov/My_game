//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_ENEMY_H
#define MY_GAME_ENEMY_H
#include "../Negative_Event.h"
#include "../../Event.h"

class Enemy : public Event{
public:
    void do_event(Field* field) override;


};


#endif //MY_GAME_ENEMY_H
