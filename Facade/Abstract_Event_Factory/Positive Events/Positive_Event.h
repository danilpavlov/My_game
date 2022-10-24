//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_POSITIVE_EVENT_H
#define MY_GAME_POSITIVE_EVENT_H
#include "../Abstract_Event_Factory.h"
#include "../Event.h"
#include "Events/Heal.h"
#include "Events/XP.h"

class Positive_Event : public Abstract_Event_Factory{
public:
    Event* create_event_first() const override;;
    Event* create_event_second() const override;;
};


#endif //MY_GAME_POSITIVE_EVENT_H
