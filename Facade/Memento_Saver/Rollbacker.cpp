//
// Created by Даниил Павлов on 21.11.2022.
//

#include "Rollbacker.h"

void Rollbacker::remember(Field *field) {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    field_ = field->get_field();
    field_level = field->get_level();

    hero_x = hero->get_hero_position(Singleton_Hero::x);
    hero_y = hero->get_hero_position(Singleton_Hero::y);
    hero_level = hero->get_hero_attribute(Singleton_Hero::level);
    hero_hp = hero->get_hero_attribute(Singleton_Hero::health_points);
    hero_xp = hero->get_hero_attribute(Singleton_Hero::experience);

}

void Rollbacker::rollback_changes(Field *field) {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    field->set_field(field_);
    field->set_level(field_level);

    hero->set_hero_attribute(Singleton_Hero::health_points, hero_hp);
    hero->set_hero_attribute(Singleton_Hero::experience, hero_xp);
    hero->set_hero_attribute(Singleton_Hero::level, hero_level);

    hero->set_hero_position(Singleton_Hero::x, hero_x);
    hero->set_hero_position(Singleton_Hero::y, hero_y);
}
