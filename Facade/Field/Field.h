//
// Created by Даниил Павлов on 15.09.2022.
//

#ifndef MY_GAME_FIELD_H
#define MY_GAME_FIELD_H

#include <vector>
#include <iostream>
#include <ctime>
#include "Cell.h"
#include "../Singleton/Singleton_Hero.h"
#include "../Logs/ISubject.h"


class Field{
private:
    std::vector< std::vector<Cell> >field_2d;   // Все поле
    int x;  // значение ширины
    int y;  // значение длины
    int level;

public:
    Field(int x, int y);
    Field();
    Field(const Field&);
    Field& operator=(const Field&);
    Field(Field&&);
    Field& operator=(Field&& obj);

    void create_2D_field();
    void clear_field();

    std::vector<std::vector<Cell> > get_field();
    void set_field(std::vector<std::vector<Cell> > new_field);

    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_level() const { return level; }
    void set_level(int new_level);


    int count_enemies();

};

#endif //MY_GAME_FIELD_H
