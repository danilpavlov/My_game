//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Ghost_Head.h"

void Ghost_Head::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    hero->set_ghost_status(true);
    hero->set_pumpkin_status(false);

    hero->set_hero_model("👻");
}

std::string Ghost_Head::get_icon() {
    return "👻";
}

bool Ghost_Head::is_empty() {
    return false;
}

