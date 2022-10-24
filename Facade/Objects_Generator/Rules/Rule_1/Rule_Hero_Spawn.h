//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_HERO_SPAWN_H
#define MY_GAME_RULE_HERO_SPAWN_H
#include "../../../Singleton/Singleton_Hero.h"

#include "../../../Field/Field.h"
#include <cmath>


template <typename T1, typename T2>
class Rule_Hero_Spawn{
public:
    Rule_Hero_Spawn(Field* main_field) : field(main_field->get_field()) {};
    void operator()(T1 x_hero, T2 y_hero, Field* main_field);
private:
    std::vector<std::vector<Cell>> field;

};

template<typename T1, typename T2>
void Rule_Hero_Spawn<T1, T2>::operator()(T1 x_hero, T2 y_hero, Field *main_field) {
    field = main_field->get_field();

    Singleton_Hero* hero = Singleton_Hero::getInstance();

    hero->set_hero_to_default(fmod(x_hero, main_field->get_x()), fmod(y_hero, main_field->get_y()));

    field[ fmod(y_hero, main_field->get_y()) ][ fmod(x_hero, main_field->get_x()) ].set_state(Cell::HERO);
    field[ fmod(y_hero, main_field->get_y())][ fmod(x_hero, main_field->get_x())].set_event(Cell::NO_EVENT);


    main_field->set_field(field);
}


#endif //MY_GAME_RULE_HERO_SPAWN_H
