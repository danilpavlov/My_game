//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_IEQUIPMENT_H
#define MY_GAME_IEQUIPMENT_H
#include "../../Singleton/Singleton_Hero.h"

class IEquipment {
public:
    virtual void put_on() = 0;
    virtual std::string get_icon() = 0;
    virtual bool is_empty() = 0;
    virtual int get_weight() = 0;
protected:
    bool empty;
};


#endif //MY_GAME_IEQUIPMENT_H
