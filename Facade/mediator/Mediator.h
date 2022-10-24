//
// Created by Даниил Павлов on 23.09.2022.
//

#ifndef MY_GAME_MEDIATOR_H
#define MY_GAME_MEDIATOR_H
#include "Hero_Moves.h"
#include "../Field/Field.h"
#include "GUI_Display.h"
#include "../Logs/ISubject.h"


class Mediator{
public:
    enum key{LEFT, RIGHT, UP, DOWN};

    Mediator(Field* main_field);
    Mediator();

    void move_hero(int key, Field* field);

    void move_menu(int key);
    void move_request(int key);
    void move_level_choice(int key);

    int get_menu_type();



    void set_field(Field* new_field);

    ~Mediator();

    void Attach(IObserver *observer);
    void Detach(IObserver *observer);
private:
    Hero_Moves* hero_mover;
    GUI_Display* menu;

};


#endif //MY_GAME_MEDIATOR_H
