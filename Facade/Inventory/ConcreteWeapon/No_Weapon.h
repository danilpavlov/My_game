//
// Created by Даниил Павлов on 02.11.2022.
//

#ifndef MY_GAME_NO_WEAPON_H
#define MY_GAME_NO_WEAPON_H
#include "../Interfaces/Groups_of_Equipment/IWeapon.h"
#define NO_WEAPON_WEIGHT 0

class No_Weapon : public IWeapon{
public:
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_NO_WEAPON_H
