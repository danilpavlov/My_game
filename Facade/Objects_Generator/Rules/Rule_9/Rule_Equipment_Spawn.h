//
// Created by Даниил Павлов on 30.10.2022.
//

#ifndef MY_GAME_RULE_EQUIPMENT_SPAWN_H
#define MY_GAME_RULE_EQUIPMENT_SPAWN_H
#include "../../../Field/Field.h"

template <int magic_number, int amount>
class Rule_Equipment_Spawn {
public:
    static void establish(Field *main_field);

};

template<int magic_number, int amount>
void Rule_Equipment_Spawn<magic_number, amount>::establish(Field *main_field) {
    auto field = main_field->get_field();
    int tmp_number = magic_number;

    for (int i = 1; i <= amount; i++){
        while (true) {
            if (field[tmp_number * i % main_field->get_y()][tmp_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_state(Cell::PUMPKIN_HEAD);
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_event(Cell::ITEM);
                break;
            }else
            {
                tmp_number += 1;
            }
        }
    }

    for (int i = 1; i <= amount; i++){
        while (true) {
            if (field[tmp_number * i % main_field->get_y()][tmp_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_state(Cell::GHOST_HEAD);
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_event(Cell::ITEM);
                break;
            }else
            {
                tmp_number += 1;
            }
        }
    }

    for (int i = 1; i <= amount; i++){
        while (true) {
            if (field[tmp_number * i % main_field->get_y()][tmp_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_state(Cell::MAGIC_GLOVE);
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_event(Cell::ITEM);
                break;
            }else
            {
                tmp_number += 1;
            }
        }
    }

    for (int i = 1; i <= amount; i++){
        while (true) {
            if (field[tmp_number * i % main_field->get_y()][tmp_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_state(Cell::DAGGER);
                field[tmp_number * i % main_field->get_y()][tmp_number * i % main_field->get_x()].set_event(Cell::ITEM);
                break;
            }else
            {
                tmp_number += 1;
            }
        }
    }
    main_field->set_field(field);
}


#endif //MY_GAME_RULE_EQUIPMENT_SPAWN_H
