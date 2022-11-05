//
// Created by Даниил Павлов on 30.10.2022.
//

#include "No_Head.h"

void No_Head::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_ghost_status(false);
    hero->set_pumpkin_status(false);

    hero->set_hero_model("🧛🏻");
}

std::string No_Head::get_icon() {
    return "➕";
}

bool No_Head::is_empty() {
    return true;
}

int No_Head::get_weight() {
    return NO_HEAD_WEIGHT;
}
