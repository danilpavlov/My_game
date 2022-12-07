//
// Created by Даниил Павлов on 02.11.2022.
//

#ifndef MY_GAME_IWEAPON_H
#define MY_GAME_IWEAPON_H
#include "../IEquipment.h"
#include "../../Buffs/Buff_Table.h"
#include "../../Buffs/Concrete_Buffs/Dagger_Buff.h"
#include "../../Buffs/Concrete_Buffs/Magic_Glove_Buff.h"

class IWeapon : IEquipment {
public:
//    IWeapon();
    virtual void put_on() = 0;
    virtual std::string get_icon() = 0;
    virtual bool is_empty() = 0;
    virtual int get_weight() = 0;
protected:
    bool empty;
    IBuff* buff;
};


#endif //MY_GAME_IWEAPON_H
