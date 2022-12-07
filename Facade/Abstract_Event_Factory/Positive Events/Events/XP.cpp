//
// Created by Даниил Павлов on 25.09.2022.
//

#include "XP.h"

void XP::do_event(Field* field) {
    Buff_Table* buffTable = Buff_Table::getInstance();

    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_hero_attribute(Singleton_Hero::experience,
                                   hero->get_hero_attribute(Singleton_Hero::experience) + 1);

    buffTable->activate_buffs_of_type(IBuff::ANTI_ENEMY_BUFF);

    hero->set_hero_shroom_status(false);


}

