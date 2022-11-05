//
// Created by Даниил Павлов on 02.11.2022.
//

#ifndef MY_GAME_SOCKS_H
#define MY_GAME_SOCKS_H
#include "../Interfaces/Groups_of_Equipment/IBoot.h"
#define SOCKS_WEIGHT 10

class Socks : public IBoot{
public:
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
    int get_weight() override;
};


#endif //MY_GAME_SOCKS_H
