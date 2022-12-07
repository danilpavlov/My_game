//
// Created by Даниил Павлов on 25.11.2022.
//

#include "Ghost_Buff.h"

void Ghost_Buff::execute() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_flying_ability(true);
}

IBuff::type Ghost_Buff::get_type() {
    return IBuff::MOVE_BUFF;
}

IBuff::part Ghost_Buff::get_part() {
    return IBuff::MASK;
}
