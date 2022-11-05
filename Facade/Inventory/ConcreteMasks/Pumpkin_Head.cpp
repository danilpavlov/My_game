//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Pumpkin_Head.h"

void Pumpkin_Head::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    hero->set_ghost_status(false);
    hero->set_pumpkin_status(true);

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

