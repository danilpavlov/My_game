//
// Created by Даниил Павлов on 25.09.2022.
//

#include "Teleport.h"

void Teleport::do_event(Field* main_field) {

    int new_x_position = time(nullptr) % main_field->get_x();
    int new_y_position = time(nullptr) % main_field->get_y();
    field = main_field->get_field();
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    while (true){

        if (field[new_y_position][new_x_position].get_state() == Cell::EMPTY){
            hero->set_hero_position(Singleton_Hero::x, new_x_position);
            hero->set_hero_position(Singleton_Hero::y, new_y_position);
            break;
        }else{
            new_x_position += 1;
            new_y_position += 1;
        }
    }
    main_field->set_field(field);
}
