//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_ENEMIES_SPAWN_H
#define MY_GAME_RULE_ENEMIES_SPAWN_H
#include "../../../Field/Field.h"

template <typename T1, typename T2>
class Rule_Enemies_Spawn {
public:
    Rule_Enemies_Spawn(Field* main_field) : field(main_field->get_field()) {};
    void operator()(T1 magic_number, T2 enemies_amount, Field* main_field);
private:
    std::vector< std::vector<Cell> > field;
};

template<typename T1, typename T2>
void Rule_Enemies_Spawn<T1, T2>::operator()(T1 magic_number, T2 enemies_amount, Field *main_field) {
    field = main_field->get_field();

    for (int i = 1; i <= enemies_amount; i++){
        while (true) {
            if (field[magic_number * i % main_field->get_y()][magic_number * i %
                                                                      main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_state(Cell::ENEMY);
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_event(Cell::NEGATIVE_EVENT);
                break;
            }else
            {
                magic_number += 1;
            }
        }
    }
    main_field->set_field(field);
}




#endif //MY_GAME_RULE_ENEMIES_SPAWN_H
