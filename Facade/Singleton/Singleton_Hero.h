//
// Created by Даниил Павлов on 17.09.2022.
//

#ifndef MY_GAME_SINGLETON_HERO_H
#define MY_GAME_SINGLETON_HERO_H

#include <iostream>
#include "../Logs/ISubject.h"


class Singleton_Hero{
private:
    static Singleton_Hero* instance;
    Singleton_Hero();

    std::string hero_model = "🧛🏻";
    bool ghost_status = false;
    bool pumpkin_status = false;
    bool hero_moved_on_wall = false;


    int hp;
    int xp;
    int lv;
    int x_hero_position;
    int y_hero_position;

    bool alive = true;
    bool victory = false;

    bool hero_eated_shroom = false;
public:
    enum hero_attributes{health_points, experience, level};
    enum coordinates{x, y};
    static Singleton_Hero* getInstance();

    void set_hero_attribute(int attribute_number, int new_number_of_some_attribute);
    int get_hero_attribute(int attribute_number);

    void set_hero_position(int coordinate_number, int new_position);
    int get_hero_position(int coordinate_number);

    bool is_alive();
    void dead();
    void hero_won();
    bool is_hero_won();

    bool did_hero_eat_shroom();
    void set_hero_shroom_status(bool new_shroom_status);

    void set_hero_to_default(int new_x, int new_y);


    std::string get_hero_model();
    void set_hero_model(std::string new_model);

    void set_ghost_status(bool new_status);
    void set_pumpkin_status(bool new_status);

    bool get_ghost_status();
    bool get_pumpkin_status();

    bool were_moved_on_wall();
    void set_hero_moved_on_wall(bool new_status);

};


#endif //MY_GAME_SINGLETON_HERO_H
