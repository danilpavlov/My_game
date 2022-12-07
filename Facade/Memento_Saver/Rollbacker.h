//
// Created by Даниил Павлов on 21.11.2022.
//

#ifndef MY_GAME_ROLLBACKER_H
#define MY_GAME_ROLLBACKER_H
#include "../Singleton/Singleton_Hero.h"
#include "../Field/Field.h"
#include <vector>

class Rollbacker {
public:
    void remember(Field* field);
    void rollback_changes(Field* field);

private:
    std::vector <std::vector <Cell>> field_;
    int field_level;

    int hero_x;
    int hero_y;
    int hero_level;
    int hero_hp;
    int hero_xp;

};


#endif //MY_GAME_ROLLBACKER_H
