//
// Created by Даниил Павлов on 02.11.2022.
//

#include "Slippers.h"

void Slippers::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_socks_status(false);
    hero->set_slippers_status(true);
}

std::string Slippers::get_icon() {
    return "🩴";
}

bool Slippers::is_empty() {
    return false;
}

int Slippers::get_weight() {
    return SLIPPERS_WEIGHT;
}
