//
// Created by Даниил Павлов on 02.11.2022.
//

#ifndef MY_GAME_MAGIC_GLOVE_H
#define MY_GAME_MAGIC_GLOVE_H
#include "../Interfaces/Groups_of_Equipment/IWeapon.h"
#define MAGIC_GLOVE_WEIGHT 10

class Magic_Glove : public IWeapon{
public:
    Magic_Glove();
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_MAGIC_GLOVE_H
