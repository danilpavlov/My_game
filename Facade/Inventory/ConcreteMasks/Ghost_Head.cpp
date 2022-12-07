//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Ghost_Head.h"

void Ghost_Head::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    Buff_Table* buffTable = Buff_Table::getInstance();

    buffTable->remove_buff(IBuff::MASK);
    buffTable->add_buff(buff);

    hero->set_hero_model("👻");
}

std::string Ghost_Head::get_icon() {
    return "👻";
}

bool Ghost_Head::is_empty() {
    return false;
}

int Ghost_Head::get_weight() {
    return GHOST_HEAD_WEIGHT;
}

Ghost_Head::Ghost_Head() {
    buff = new Ghost_Buff;
}

