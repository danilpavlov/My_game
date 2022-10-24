//
// Created by Даниил Павлов on 25.09.2022.
//

#include "Positive_Event.h"


Event *Positive_Event::create_event_first() const {
    return new Heal;
}

Event *Positive_Event::create_event_second() const {
    return new XP;
}
