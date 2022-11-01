//
// Created by Даниил Павлов on 23.10.2022.
//

#ifndef MY_GAME_MEMENTO_SAVE_H
#define MY_GAME_MEMENTO_SAVE_H
#include "Memento.h"
#include <fstream>
#include <ostream>

class Memento_Save : public Memento{
public:
    std::vector<std::vector<Cell>> get_field() const override;
    int hero_position(Singleton_Hero::coordinates) const override;
    int hero_attribute(Singleton_Hero::hero_attributes) const override;
    int field_level() const override;
};


#endif //MY_GAME_MEMENTO_SAVE_H
