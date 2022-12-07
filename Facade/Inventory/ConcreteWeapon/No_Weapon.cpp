//
// Created by Даниил Павлов on 02.11.2022.
//

#include "No_Weapon.h"

void No_Weapon::put_on() {
    Buff_Table* buffTable = Buff_Table::getInstance();

    buffTable->remove_buff(IBuff::WEAPON);
}

std::string No_Weapon::get_icon() {
    return "➕";
}

bool No_Weapon::is_empty() {
    return true;
}

int No_Weapon::get_weight() {
    return NO_WEAPON_WEIGHT;
}
