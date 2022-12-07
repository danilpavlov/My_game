//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_GHOST_HEAD_H
#define MY_GAME_GHOST_HEAD_H
#include "../Interfaces/Groups_of_Equipment/IMask.h"
#include "../Buffs/Concrete_Buffs/Ghost_Buff.h"
#define GHOST_HEAD_WEIGHT 90

class Ghost_Head : public IMask{
public:
    Ghost_Head();
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_GHOST_HEAD_H
