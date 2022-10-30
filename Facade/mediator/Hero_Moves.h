//
// Created by Даниил Павлов on 23.09.2022.
//

#ifndef MY_GAME_HERO_MOVES_H
#define MY_GAME_HERO_MOVES_H
#include <vector>
#include "../Singleton/Singleton_Hero.h"
#include "../Field/Field.h"
#include "../Abstract_Event_Factory/Abstract_Event_Factory.h"
#include "../Inventory/Inventory.h"

#include "../Logs/ISubject.h"




#include <cmath>


class Hero_Moves : ISubject{
public:
    enum direction{LEFT, RIGHT, UP, DOWN};
    Hero_Moves(Field* playing_field);

    void set_field(Field* new_field);

    void move_hero(direction direction_key, Field* main_field, Inventory* inventory);

    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;

private:
    void redefinition_hero_cell_states(int cell_x_plus, int cell_y_plus, Cell::cell_state present_cell_state, Cell::cell_state future_cell_state);

    std::vector<std::vector<Cell> > field;
    Singleton_Hero* hero;

    int x_verge;
    int y_verge;

    Event* event;

    Message* heroMoveMessage;
    Message* warningMessage;
    Message* eventMessage;

    void do_event_heal_or_enemy_or_win(Abstract_Event_Factory& factory, Field* main_field);
    void do_event_xp_or_teleport_or_refresher(Abstract_Event_Factory& factory, Field* main_field);

    Equipment_Factory* equipmentFactory;
    Consumables_Factory* consumablesFactory;

};


#endif //MY_GAME_HERO_MOVES_H
