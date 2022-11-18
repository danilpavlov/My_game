//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_WIN_CELL_SPAWN_H
#define MY_GAME_RULE_WIN_CELL_SPAWN_H
#include "../../../Field/Field.h"


template <int x, int y>
class Rule_Win_Cell_Spawn {
public:
    static void establish(Field* main_field);
};

template<int x, int y>
void Rule_Win_Cell_Spawn<x, y>::establish(Field *main_field) {
    auto field = main_field->get_field();

    field[y][x].set_state(Cell::WIN);
    field[y][x].set_event(Cell::GLOBAL_EVENT);

    main_field->set_field(field);
}


#endif //MY_GAME_RULE_WIN_CELL_SPAWN_H
