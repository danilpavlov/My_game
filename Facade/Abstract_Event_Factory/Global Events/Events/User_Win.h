//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_USER_WIN_H
#define MY_GAME_USER_WIN_H
#include "../Global_Event.h"
#include "../../Event.h"

class User_Win : public Event{
public:
    void do_event(Field* field) override;

};


#endif //MY_GAME_USER_WIN_H
