//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_EQUIPMENT_FACTORY_H
#define MY_GAME_EQUIPMENT_FACTORY_H
#include "../ConcreteEquipment/Ghost_Head.h"
#include "../ConcreteEquipment/Pumpkin_Head.h"
#include "../ConcreteEquipment/No_Equipment.h"

class Equipment_Factory {
public:
    IEquipment* put_ghost_head_in_inventory();
    IEquipment* put_pumpkin_head_in_inventory();
    IEquipment* put_no_equipment_in_inventory();
};


#endif //MY_GAME_EQUIPMENT_FACTORY_H
