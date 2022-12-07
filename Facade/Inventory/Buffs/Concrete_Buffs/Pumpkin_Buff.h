//
// Created by Даниил Павлов on 26.11.2022.
//

#ifndef MY_GAME_PUMPKIN_BUFF_H
#define MY_GAME_PUMPKIN_BUFF_H
#include "../IBuff.h"

class Pumpkin_Buff : public IBuff{
public:
    void execute() override;
    type get_type() override;
    part get_part() override;
};


#endif //MY_GAME_PUMPKIN_BUFF_H
