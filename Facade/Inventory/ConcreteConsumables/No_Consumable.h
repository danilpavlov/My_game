//
// Created by Даниил Павлов on 30.10.2022.
//

#ifndef MY_GAME_NO_CONSUMABLE_H
#define MY_GAME_NO_CONSUMABLE_H
#include "../Interfaces/IConsumable.h"

class No_Consumable : public IConsumable{
public:
    void use() override;
    std::string get_icon() override;
    bool is_empty() override;
};


#endif //MY_GAME_NO_CONSUMABLE_H
