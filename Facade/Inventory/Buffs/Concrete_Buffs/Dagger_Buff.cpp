//
// Created by Даниил Павлов on 25.11.2022.
//

#include "Dagger_Buff.h"

void Dagger_Buff::execute() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_hero_attribute(Singleton_Hero::experience,
                             hero->get_hero_attribute(Singleton_Hero::experience) + 2);
}

IBuff::type Dagger_Buff::get_type() {
    return IBuff::ANTI_ENEMY_BUFF;
}

IBuff::part Dagger_Buff::get_part() {
    return IBuff::WEAPON;
}
