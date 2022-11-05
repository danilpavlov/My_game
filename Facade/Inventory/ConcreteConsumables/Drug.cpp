//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Drug.h"

void Drug::use() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_hero_shroom_status(true);
}

std::string Drug::get_icon() {
    return "🍄";
}

bool Drug::is_empty() {
    return false;
}

int Drug::get_weight() {
    return DRUG_WEIGHT;
}
