//
// Created by Даниил Павлов on 23.09.2022.
//

#include "Mediator.h"

Mediator::Mediator(Field* main_field) {
    hero_mover = new Hero_Moves(main_field);
    menu = new GUI_Display;
    menu->set_type(GUI_Display::NEW_GAME);
}



void Mediator::move_hero(int key, Field* field) {

    switch (key){
        case (Mediator::LEFT):
            hero_mover->move_hero(Hero_Moves::LEFT, field);
            break;
        case (Mediator::RIGHT):
            hero_mover->move_hero(Hero_Moves::RIGHT, field);
            break;
        case (Mediator::UP):
            hero_mover->move_hero(Hero_Moves::UP, field);
            break;
        case (Mediator::DOWN):
            hero_mover->move_hero(Hero_Moves::DOWN, field);
            break;
        default:
            break;
    }

}

void Mediator::move_menu(int key) {
    char non_active_color[] = { 0x1b, '[', '3', '8',';','5',';','2','3', '8', 'm',0 };
    char active_color[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '0', 'm',0 };

    switch (key){
        case (GUI_Display::NEW_GAME):
            menu->set_type(GUI_Display::NEW_GAME);
            menu->print_main_menu(GUI_Display::NEW_GAME, active_color);
            menu->print_main_menu(GUI_Display::LOAD_GAME, non_active_color);
            menu->print_main_menu(GUI_Display::QUIT, non_active_color);
            break;
        case (GUI_Display::LOAD_GAME):
            menu->set_type(GUI_Display::LOAD_GAME);
            menu->print_main_menu(GUI_Display::NEW_GAME, non_active_color);
            menu->print_main_menu(GUI_Display::LOAD_GAME, active_color);
            menu->print_main_menu(GUI_Display::QUIT, non_active_color);
            break;
        case (GUI_Display::QUIT):
            menu->set_type(GUI_Display::QUIT);
            menu->print_main_menu(GUI_Display::NEW_GAME, non_active_color);
            menu->print_main_menu(GUI_Display::LOAD_GAME, non_active_color);
            menu->print_main_menu(GUI_Display::QUIT, active_color);
            break;
        default:
            break;
    }

}



int Mediator::get_menu_type() {
    return menu->get_type();
}

Mediator::~Mediator() {
    delete hero_mover;
    delete menu;

}

void Mediator::Attach(IObserver *observer) {
    hero_mover->Attach(observer);
}

void Mediator::Detach(IObserver *observer) {
    hero_mover->Detach(observer);
}

void Mediator::move_request(int key) {
    char non_active_color[] = { 0x1b, '[', '3', '8',';','5',';','2','3', '8', 'm',0 };
    char active_color[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '0', 'm',0 };

    switch (key) {
        case GUI_Display::YES:
            menu->print_file_control_request(GUI_Display::YES, active_color);
            menu->print_file_control_request(GUI_Display::NO, non_active_color);
            menu->set_type(GUI_Display::YES);
            break;
        case GUI_Display::NO:
            menu->print_file_control_request(GUI_Display::YES, non_active_color);
            menu->print_file_control_request(GUI_Display::NO, active_color);
            menu->set_type(GUI_Display::NO);
            break;
        default:
            break;

    }

}

Mediator::Mediator() {
    menu = new GUI_Display;
    menu->set_type(GUI_Display::YES);
}

void Mediator::set_field(Field* new_field) {
    hero_mover->set_field(new_field);
}

void Mediator::move_level_choice(int key) {
    char non_active_color[] = { 0x1b, '[', '3', '8',';','5',';','2','3', '8', 'm',0 };
    char active_color[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '0', 'm',0 };

    switch (key) {
        case GUI_Display::FIRST_LEVEL:
            menu->print_level_choice(GUI_Display::FIRST_LEVEL, active_color);
            menu->print_level_choice(GUI_Display::SECOND_LEVEL, non_active_color);
            menu->print_level_choice(GUI_Display::BACK, non_active_color);
            menu->set_type(GUI_Display::FIRST_LEVEL);
            break;
        case GUI_Display::SECOND_LEVEL:
            menu->print_level_choice(GUI_Display::FIRST_LEVEL, non_active_color);
            menu->print_level_choice(GUI_Display::SECOND_LEVEL, active_color);
            menu->print_level_choice(GUI_Display::BACK, non_active_color);
            menu->set_type(GUI_Display::SECOND_LEVEL);
            break;
        case GUI_Display::BACK:
            menu->print_level_choice(GUI_Display::FIRST_LEVEL, non_active_color);
            menu->print_level_choice(GUI_Display::SECOND_LEVEL, non_active_color);
            menu->print_level_choice(GUI_Display::BACK, active_color);
            menu->set_type(GUI_Display::BACK);
            break;
        default:
            break;

    }
}




