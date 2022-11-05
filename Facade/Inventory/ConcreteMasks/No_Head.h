//
// Created by Даниил Павлов on 30.10.2022.
//

#ifndef MY_GAME_NO_HEAD_H
#define MY_GAME_NO_HEAD_H
#include "../Interfaces/Groups_of_Equipment/IMask.h"
#define NO_HEAD_WEIGHT 0

class No_Head : public IMask{
public:
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_NO_HEAD_H
