//
// Created by Даниил Павлов on 25.09.2022.
//

#include "Negative_Event.h"

Event *Negative_Event::create_event_first() const {
    return new Enemy;
}

Event *Negative_Event::create_event_second() const {
    return new Teleport;
}
