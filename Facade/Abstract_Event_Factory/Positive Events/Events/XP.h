//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_XP_H
#define MY_GAME_XP_H
#include "../Positive_Event.h"
#include "../../Event.h"
#include <math.h>

class XP : public Event{
public:
    void do_event(Field* field) override;


};


#endif //MY_GAME_XP_H
