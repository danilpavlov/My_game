//
// Created by Даниил Павлов on 02.11.2022.
//

#include "No_Boots.h"

void No_Boots::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_socks_status(false);
    hero->set_slippers_status(false);
}

std::string No_Boots::get_icon() {
    return "➕";
}

bool No_Boots::is_empty() {
    return true;
}

int No_Boots::get_weight() {
    return NO_BOOT_WEIGHT;
}
