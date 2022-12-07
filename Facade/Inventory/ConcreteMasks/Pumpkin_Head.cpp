//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Pumpkin_Head.h"

void Pumpkin_Head::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    Buff_Table* buffTable = Buff_Table::getInstance();

    buffTable->remove_buff(IBuff::MASK);
    buffTable->add_buff(buff);

    hero->set_hero_model("🎃");
}

std::string Pumpkin_Head::get_icon() {
    return "🎃";
}

bool Pumpkin_Head::is_empty() {
    return false;
}

int Pumpkin_Head::get_weight() {
    return PUMPKIN_HEAD_WEIGHT;
}

Pumpkin_Head::Pumpkin_Head() {
    buff = new Pumpkin_Buff;
}

