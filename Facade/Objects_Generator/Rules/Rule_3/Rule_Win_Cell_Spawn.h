//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_WIN_CELL_SPAWN_H
#define MY_GAME_RULE_WIN_CELL_SPAWN_H
#include "../../../Field/Field.h"


template <typename T1, typename T2>
class Rule_Win_Cell_Spawn {
public:
    Rule_Win_Cell_Spawn(Field* main_field);
    void operator()(T1 x_pos, T2 y_pos, Field* main_field);
private:
    std::vector< std::vector<Cell>> field;
};

template<typename T1, typename T2>
void Rule_Win_Cell_Spawn<T1, T2>::operator()(T1 x_pos, T2 y_pos, Field *main_field) {
    field = main_field->get_field();
    field[y_pos][x_pos].set_state(Cell::WIN);
    field[y_pos][x_pos].set_event(Cell::GLOBAL_EVENT);

    main_field->set_field(field);
}

template<typename T1, typename T2>
Rule_Win_Cell_Spawn<T1, T2>::Rule_Win_Cell_Spawn(Field *main_field) : field(main_field->get_field()) {

}


#endif //MY_GAME_RULE_WIN_CELL_SPAWN_H
