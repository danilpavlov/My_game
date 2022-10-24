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

};


#endif //MY_GAME_SINGLETON_HERO_H
