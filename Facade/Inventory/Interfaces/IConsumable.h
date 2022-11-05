//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_ICONSUMABLE_H
#define MY_GAME_ICONSUMABLE_H
#include "../../Singleton/Singleton_Hero.h"

class IConsumable {
public:
    virtual void use() = 0;
    virtual std::string get_icon() = 0;
    virtual bool is_empty() = 0;
    virtual int get_weight() = 0;
protected:
    bool empty;
};


#endif //MY_GAME_ICONSUMABLE_H
