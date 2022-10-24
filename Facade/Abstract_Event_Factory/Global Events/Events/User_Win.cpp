//
// Created by Даниил Павлов on 25.09.2022.
//

#include "User_Win.h"

void User_Win::do_event(Field* field) {

    Singleton_Hero* hero = Singleton_Hero::getInstance();
    if (field->count_enemies() == 0 && hero->get_hero_attribute(Singleton_Hero::level) >= 1) {
        hero->hero_won();
    }
}

