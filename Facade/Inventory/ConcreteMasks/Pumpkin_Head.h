//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_PUMPKIN_HEAD_H
#define MY_GAME_PUMPKIN_HEAD_H
#include "../Interfaces/Groups_of_Equipment/IMask.h"
#define PUMPKIN_HEAD_WEIGHT 50

class Pumpkin_Head : public IMask{
public:
    Pumpkin_Head();
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_PUMPKIN_HEAD_H
