//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_TELEPORT_H
#define MY_GAME_TELEPORT_H
#include "../Negative_Event.h"
#include "../../Event.h"
#include <time.h>
#include <vector>
#include "../../../Field/Cell.h"

class Teleport : public Event{
public:
    void do_event(Field* main_field) override;

private:
    std::vector<std::vector<Cell> > field;
};


#endif //MY_GAME_TELEPORT_H
