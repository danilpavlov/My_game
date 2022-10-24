//
// Created by Даниил Павлов on 13.10.2022.
//

#ifndef MY_GAME_EVENT_MESSAGE_H
#define MY_GAME_EVENT_MESSAGE_H
#include "../Message.h"

class Event_Message : public Message{
public:
    enum type{HEAL, XP, ENEMY, TELEPORT, WIN, REFRESHER, CURE, DEATH, VICTORY};
    std::string get_message(int type) override;
};


#endif //MY_GAME_EVENT_MESSAGE_H
