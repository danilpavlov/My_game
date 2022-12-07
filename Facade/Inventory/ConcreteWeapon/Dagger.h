//
// Created by Даниил Павлов on 02.11.2022.
//

#ifndef MY_GAME_DAGGER_H
#define MY_GAME_DAGGER_H
#include "../Interfaces/Groups_of_Equipment/IWeapon.h"
#define DAGGER_WEIGHT 10

class Dagger : public IWeapon{
public:
    Dagger();
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_DAGGER_H
