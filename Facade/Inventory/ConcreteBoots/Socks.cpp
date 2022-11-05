//
// Created by Даниил Павлов on 02.11.2022.
//

#include "Socks.h"

void Socks::put_on() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_socks_status(true);
    hero->set_slippers_status(false);
}

std::string Socks::get_icon() {
    return "🧦";
}

bool Socks::is_empty() {
    return false;
}

int Socks::get_weight() {
    return SOCKS_WEIGHT;
}
