//
// Created by Даниил Павлов on 16.09.2022.
//

#ifndef MY_GAME_ABSTRACT_EVENT_FACTORY_H
#define MY_GAME_ABSTRACT_EVENT_FACTORY_H
#include "../Singleton/Singleton_Hero.h"
#include "Event.h"




class Abstract_Event_Factory {
public:

    virtual  Event* create_event_first() const = 0;
    virtual Event* create_event_second() const = 0;


};


#endif //MY_GAME_ABSTRACT_EVENT_FACTORY_H
