//
// Created by Даниил Павлов on 25.09.2022.
//

#include "Refresh_Events.h"

void Refresh_Events::do_event(Field *main_field) {

    Singleton_Hero* hero = Singleton_Hero::getInstance();
    hero->set_hero_shroom_status(true);
    field = main_field->get_field();

    int magic_number = 123;

    for (int i = 1; i <= 4; i++) {
        while (true) {
            if (field[magic_number * i % main_field->get_y()][magic_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY) {
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_state(
                        Cell::ENEMY);
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_event(
                        Cell::NEGATIVE_EVENT);
                break;
            } else {
                magic_number += 1;
            }
        }
    }

    for (int i = 1; i <= 2; i++){
        while (true) {
            if (field[magic_number * i % main_field->get_y()][magic_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_state(Cell::HEAL);
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_event(Cell::POSITIVE_EVENT);
                break;
            }else
            {
                magic_number += 1;
            }
        }
    }

    for (int i = 1; i <= 5; i++){
        while (true) {
            if (field[magic_number * i % main_field->get_y()][magic_number * i %
                                                              main_field->get_x()].get_state() == Cell::EMPTY)
            {
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_state(Cell::XP);
                field[magic_number * i % main_field->get_y()][magic_number * i % main_field->get_x()].set_event(Cell::POSITIVE_EVENT);
                break;
            }else
            {
                magic_number += 1;
            }
        }
    }

    main_field->set_field(field);

}
