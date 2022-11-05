//
// Created by Даниил Павлов on 25.09.2022.
//

#include "XP.h"

void XP::do_event(Field* field) {

    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_hero_attribute(Singleton_Hero::experience,
                                   hero->get_hero_attribute(Singleton_Hero::experience) + 1);

    if (hero->get_pumpkin_status()){
        hero->set_hero_attribute(Singleton_Hero::experience,
                                 hero->get_hero_attribute(Singleton_Hero::experience) + 1);
    }

    if (hero->get_slippers_status()){
        hero->set_hero_attribute(Singleton_Hero::experience,
                                 hero->get_hero_attribute(Singleton_Hero::experience) + 1);
    }


    hero->set_hero_shroom_status(false);


}

