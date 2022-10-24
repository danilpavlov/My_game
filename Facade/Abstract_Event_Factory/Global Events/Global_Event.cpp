//
// Created by Даниил Павлов on 25.09.2022.
//

#include "Global_Event.h"

Event *Global_Event::create_event_first() const {
    return new User_Win;
}

Event *Global_Event::create_event_second() const {
    return new Refresh_Events;
}
