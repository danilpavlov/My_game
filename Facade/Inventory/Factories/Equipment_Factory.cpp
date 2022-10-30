//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Equipment_Factory.h"

IEquipment *Equipment_Factory::put_ghost_head_in_inventory() {
    return new Ghost_Head;
}

IEquipment *Equipment_Factory::put_pumpkin_head_in_inventory() {
    return new Pumpkin_Head;
}

IEquipment *Equipment_Factory::put_no_equipment_in_inventory() {
    return new No_Equipment;
}
