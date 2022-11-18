//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_WALLS_SPAWN_H
#define MY_GAME_RULE_WALLS_SPAWN_H

#include "../../../Field/Field.h"

template <int magic_number>
class Rule_Walls_Spawn {
public:
    static void establish(Field* main_field);
};

template<int magic_number>
void Rule_Walls_Spawn<magic_number>::establish(Field* main_field) {
    auto field = main_field->get_field();

    for (int i = 2; i < main_field->get_y() - 2; i++){

        for (int j = 2; j < main_field->get_x() - 2; j++){
            if (magic_number/i % 2 == 0 && magic_number/j % 2 != 0){
                field[i][j].set_state(Cell::WALL);
            }
        }
    }

    main_field->set_field(field);

}



#endif //MY_GAME_RULE_WALLS_SPAWN_H
