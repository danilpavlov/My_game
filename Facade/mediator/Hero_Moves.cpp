//
// Created by Даниил Павлов on 23.09.2022.
//

#include "Hero_Moves.h"
#include "../Abstract_Event_Factory/Positive Events/Positive_Event.h"
#include "../Abstract_Event_Factory/Negative Events/Negative_Event.h"
#include "../Abstract_Event_Factory/Global Events/Global_Event.h"


Hero_Moves::Hero_Moves(Field* field) : field(field->get_field()) {
    x_verge = field->get_x();
    y_verge = field->get_y();
    this->hero = Singleton_Hero::getInstance();

    heroMoveMessage = new Hero_Moves_Message;
    warningMessage = new Warning_Message;
    eventMessage = new Event_Message;

    equipmentFactory = new Equipment_Factory;
    consumablesFactory = new Consumables_Factory;
}

void Hero_Moves::redefinition_hero_cell_states(int cell_x_plus, int cell_y_plus, Cell::cell_state present_cell_state, Cell::cell_state future_cell_state) {

    if (!hero->were_moved_on_wall()) {
        field[hero->get_hero_position(Singleton_Hero::y)][hero->get_hero_position(Singleton_Hero::x)].set_state(
                present_cell_state);
    }else{
        field[hero->get_hero_position(Singleton_Hero::y)][hero->get_hero_position(Singleton_Hero::x)].set_state(
                Cell::WALL);
    }

    hero->set_hero_position(Singleton_Hero::x, fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + cell_x_plus,
                                                         x_verge) + x_verge, x_verge)); // Меняем глобальное положения x

    hero->set_hero_position(Singleton_Hero::y, fmod(fmod(hero->get_hero_position(Singleton_Hero::y) + cell_y_plus,
                                                         y_verge) + y_verge, y_verge)); // Меняем глобальное положения y

    field[hero->get_hero_position(Singleton_Hero::y)][hero->get_hero_position(Singleton_Hero::x)].set_state(
            future_cell_state);

    field[hero->get_hero_position(Singleton_Hero::y)][hero->get_hero_position(Singleton_Hero::x)].set_event(
            Cell::NO_EVENT);
    hero->set_hero_moved_on_wall(false);
}


void Hero_Moves::move_hero(direction direction_key, Field* main_field, Inventory* inventory) {
    Abstract_Event_Factory *some_factory;
    int x_plus;
    int y_plus;

    switch(direction_key){
        case direction::LEFT:
            x_plus = -1;
            y_plus = 0;
            break;
        case direction::RIGHT:
            x_plus = 1;
            y_plus = 0;
            break;
        case direction::UP:
            x_plus = 0;
            y_plus = -1;
            break;
        case direction::DOWN:
            x_plus = 0;
            y_plus = 1;
            break;
        default:
            break;
    }


    switch (field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge )]
    [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_event())
    {
        case (Cell::NO_EVENT):
            if (field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge)]
                [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_state() != Cell::WALL) {
                redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);


                Notify(heroMoveMessage, direction_key);

            }else if (field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge)]
                            [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_state() == Cell::WALL && hero->get_ghost_status()){


                redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);
                hero->set_hero_moved_on_wall(true);

                Notify(heroMoveMessage, direction_key);

            }else{
                Notify(warningMessage, Warning_Message::HERO_CANT_MOVE_ON_ROCK);
            }
            break;
        case (Cell::POSITIVE_EVENT):
            some_factory = new Positive_Event();

            switch (field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge)]
            [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_state())
            {
                case (Cell::HEAL):
                    redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                    if (hero->get_hero_attribute(Singleton_Hero::health_points) != 9) {
                        Notify(eventMessage, Event_Message::HEAL);
                    }else if (hero->get_hero_attribute(Singleton_Hero::health_points) == 9){
                        Notify(warningMessage, Warning_Message::TOO_MUCH_HP);
                    }

                    this->do_event_heal_or_enemy_or_win(*some_factory, main_field);

                    break;
                case (Cell::XP):
                    redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                    if (hero->did_hero_eat_shroom()){
                        Notify(eventMessage, Event_Message::CURE);
                    }

                    this->do_event_xp_or_teleport_or_refresher(*some_factory, main_field);


                    Notify(eventMessage, Event_Message::XP);


                    break;
                default:
                    break;
            }
            Notify(heroMoveMessage, direction_key);
            delete some_factory;
            break;
        case (Cell::NEGATIVE_EVENT):
            some_factory = new Negative_Event();
            std::cout<<'\a';

            switch (field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge)]
            [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_state())
            {
                case (Cell::ENEMY):
                    redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);
                    this->do_event_heal_or_enemy_or_win(*some_factory, main_field);

                    Notify(eventMessage, Event_Message::ENEMY);
                    break;
                case (Cell::TELEPORT):
                    redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::EMPTY);

                    this->do_event_xp_or_teleport_or_refresher(*some_factory, main_field);

                    field[hero->get_hero_position(Singleton_Hero::y)][hero->get_hero_position(Singleton_Hero::x)].set_state(Cell::HERO);
                    field[hero->get_hero_position(Singleton_Hero::y)][hero->get_hero_position(Singleton_Hero::x)].set_event(Cell::NO_EVENT);

                    Notify(eventMessage, Event_Message::TELEPORT);
                    break;
                default:
                    break;
            }
            Notify(heroMoveMessage, direction_key);
            delete some_factory;
            break;
        case (Cell::GLOBAL_EVENT):
            some_factory = new Global_Event();

            switch (field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge)]
            [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_state())
            {
                case (Cell::WIN):
                    if (main_field->count_enemies() == 0 && hero->get_hero_attribute(Singleton_Hero::level) >= 1) {
                        Notify(eventMessage, Event_Message::WIN);

                        redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);
                        this->do_event_heal_or_enemy_or_win(*some_factory, main_field);

                    }else{
                        Notify(warningMessage, Warning_Message::HERO_CANT_WIN_YET);
                    }


                    break;
                case (Cell::REFRESHER_OF_EVENTS):

                    this->do_event_xp_or_teleport_or_refresher(*some_factory, main_field);
                    field = main_field->get_field();
                    redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                    Notify(eventMessage, Event_Message::REFRESHER);
                    break;
                default:
                    break;
            }
            Notify(heroMoveMessage, direction_key);
            delete some_factory;
            break;

        case Cell::ITEM:
            switch((field[fmod( fmod( hero->get_hero_position(Singleton_Hero::y) + y_plus, y_verge) + y_verge, y_verge)]
            [fmod(fmod(hero->get_hero_position(Singleton_Hero::x) + x_plus, x_verge) + x_verge, x_verge)].get_state())){

                case Cell::PUMPKIN_HEAD:
                    if (inventory->has_empty_equipment_slots()){
                        redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                        inventory->add_equipment(equipmentFactory->put_pumpkin_head_in_inventory());
                    }

                    break;
                case Cell::GHOST_HEAD:
                    if (inventory->has_empty_equipment_slots()){
                        redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                        inventory->add_equipment(equipmentFactory->put_ghost_head_in_inventory());
                    }
                    break;
                case Cell::DRUG:
                    if (inventory->has_empty_consumable_slots()){
                        redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                        inventory->add_consumable(consumablesFactory->put_drug_in_inventory());
                    }

                    break;
                case Cell::HEAL_POTION:
                    if (inventory->has_empty_consumable_slots()){
                        redefinition_hero_cell_states(x_plus, y_plus, Cell::EMPTY, Cell::HERO);

                        inventory->add_consumable(consumablesFactory->put_heal_potion_in_inventory());
                    }

                    break;
                default:
                    break;

            }
        default:
            break;


    }
    main_field->set_field(field);

}



void Hero_Moves::do_event_heal_or_enemy_or_win(Abstract_Event_Factory &factory, Field* main_field) {
    event = factory.create_event_first();
    event->do_event(main_field);
}

void Hero_Moves::do_event_xp_or_teleport_or_refresher(Abstract_Event_Factory &factory, Field* main_field) {
    event = factory.create_event_second();
    event->do_event(main_field);
}



void Hero_Moves::Attach(IObserver *observer) {
    list_observer_.push_back(observer);
}

void Hero_Moves::Detach(IObserver *observer) {
    list_observer_.erase(std::remove(list_observer_.begin(), list_observer_.end(), observer), list_observer_.end());
}


void Hero_Moves::set_field(Field *new_field) {
    field = new_field->get_field();
}





