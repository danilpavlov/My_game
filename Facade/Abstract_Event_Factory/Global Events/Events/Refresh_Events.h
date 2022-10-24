//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_REFRESH_EVENTS_H
#define MY_GAME_REFRESH_EVENTS_H
#include <vector>
#include "../Global_Event.h"
#include "../../Event.h"


class Refresh_Events : public Event{
public:
    void do_event(Field* main_field) override;

private:
    std::vector <std::vector <Cell> > field;
};


#endif //MY_GAME_REFRESH_EVENTS_H
