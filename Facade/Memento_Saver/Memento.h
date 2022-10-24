//
// Created by Даниил Павлов on 23.10.2022.
//

#ifndef MY_GAME_MEMENTO_H
#define MY_GAME_MEMENTO_H
#include "../Field/Field.h"

class Memento {
public:
    virtual ~Memento() {}
    virtual std::vector<std::vector<Cell>> get_field() const = 0;
    virtual int hero_position(Singleton_Hero::coordinates) const = 0;
    virtual int hero_attribute(Singleton_Hero::hero_attributes) const = 0;
    virtual int field_level() const = 0;
};


#endif //MY_GAME_MEMENTO_H
