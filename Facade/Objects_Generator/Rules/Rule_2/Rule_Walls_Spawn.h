//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_RULE_WALLS_SPAWN_H
#define MY_GAME_RULE_WALLS_SPAWN_H

#include "../../../Field/Field.h"

template <typename T>
class Rule_Walls_Spawn {
public:
    Rule_Walls_Spawn(Field* main_field);
    void operator()(T magic_number, Field* main_field);

private:
    std::vector<std::vector<Cell> > field;
};

template<typename T>
void Rule_Walls_Spawn<T>::operator()(T magic_number ,Field* main_field) {
    field = main_field->get_field();

    for (int i = 2; i < main_field->get_y() - 2; i++){

        for (int j = 2; j < main_field->get_x() - 2; j++){
            if (magic_number/i % 2 == 0 && magic_number/j % 2 != 0){
                field[i][j].set_state(Cell::WALL);
            }
        }
    }

    main_field->set_field(field);


}


template<typename T>
Rule_Walls_Spawn<T>::Rule_Walls_Spawn(Field *main_field) : field(main_field->get_field()){
}


#endif //MY_GAME_RULE_WALLS_SPAWN_H
