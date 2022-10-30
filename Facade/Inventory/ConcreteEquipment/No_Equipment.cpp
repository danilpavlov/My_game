//
// Created by Даниил Павлов on 30.10.2022.
//

#include "No_Equipment.h"

void No_Equipment::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_ghost_status(false);
    hero->set_pumpkin_status(false);

    hero->set_hero_model("🧛🏻");
}

std::string No_Equipment::get_icon() {
    return "➕";
}

bool No_Equipment::is_empty() {
    return true;
}
