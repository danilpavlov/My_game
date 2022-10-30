//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_GHOST_HEAD_H
#define MY_GAME_GHOST_HEAD_H
#include "../Interfaces/IEquipment.h"

class Ghost_Head : public IEquipment{
public:
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
};


#endif //MY_GAME_GHOST_HEAD_H
