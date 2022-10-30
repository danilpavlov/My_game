//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Heal_Potion.h"

void Heal_Potion::use() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    if (hero->get_hero_attribute(Singleton_Hero::health_points) < 9) {

        hero->set_hero_attribute(Singleton_Hero::health_points,
                                 hero->get_hero_attribute(Singleton_Hero::health_points) + 1);
    }
}

std::string Heal_Potion::get_icon() {
    return "🚬";
}

bool Heal_Potion::is_empty() {
    return false;
}
