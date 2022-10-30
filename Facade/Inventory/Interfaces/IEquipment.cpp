//
// Created by Даниил Павлов on 29.10.2022.
//

#include "IEquipment.h"

void IEquipment::throw_out() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    hero->set_ghost_status(false);
    hero->set_pumpkin_status(false);

    hero->set_hero_model("🧛🏻");
}
