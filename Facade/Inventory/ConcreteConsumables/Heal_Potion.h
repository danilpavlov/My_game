//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_HEAL_POTION_H
#define MY_GAME_HEAL_POTION_H
#include "../Interfaces/IConsumable.h"
#define HEAL_POTION_WEIGHT 10

class Heal_Potion : public IConsumable{
public:
    void use() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_HEAL_POTION_H
