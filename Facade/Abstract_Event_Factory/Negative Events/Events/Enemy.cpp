//
// Created by Даниил Павлов on 25.09.2022.
//

#include "Enemy.h"

void Enemy::do_event(Field* field) {

    Singleton_Hero *hero = Singleton_Hero::getInstance();
    if (hero->get_hero_attribute(Singleton_Hero::health_points) >= 1) {
        hero->set_hero_attribute(Singleton_Hero::health_points,
                                       hero->get_hero_attribute(Singleton_Hero::health_points) - 1);
    }

    if (hero->get_hero_attribute(Singleton_Hero::health_points) == 0){
        hero->dead();

    }
}

