//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_HERO_SPAWN_H
#define MY_GAME_RULE_HERO_SPAWN_H
#include "../../../Singleton/Singleton_Hero.h"

#include "../../../Field/Field.h"
#include <cmath>


template <int x, int y>
class Rule_Hero_Spawn{
public:
    static void establish(Field* main_field);
};

template<int x, int y>
void Rule_Hero_Spawn<x, y>::establish(Field *main_field) {
    auto field = main_field->get_field();

    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_hero_to_default(fmod(x, main_field->get_x()), fmod(y, main_field->get_y()));

    field[ fmod(y, main_field->get_y()) ][ fmod(x, main_field->get_x()) ].set_state(Cell::HERO);
    field[ fmod(y, main_field->get_y())][ fmod(x, main_field->get_x())].set_event(Cell::NO_EVENT);


    main_field->set_field(field);
}


#endif //MY_GAME_RULE_HERO_SPAWN_H
