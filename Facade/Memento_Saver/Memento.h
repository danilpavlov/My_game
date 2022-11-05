//
// Created by Даниил Павлов on 23.10.2022.
//

#ifndef MY_GAME_MEMENTO_H
#define MY_GAME_MEMENTO_H
#include "../Field/Field.h"
#include <fstream>

struct Save_Files{
    std::fstream field_file;
    std::string field_path = "Save/Saved_Field.txt";

    std::fstream field_level_file;
    std::string field_level_path = "Save/Saved_Field_Level.txt";

    std::fstream hero_level_file;
    std::string hero_level_path = "Save/Saved_Hero_Level.txt";

    std::fstream hp_file;
    std::string hp_path = "Save/Saved_HP.txt";

    std::fstream xp_file;
    std::string xp_path = "Save/Saved_XP.txt";

    std::fstream hero_x_pos_file;
    std::string hero_x_pos_path = "Save/Saved_Hero_X.txt";

    std::fstream hero_y_pos_file;
    std::string hero_y_pos_path = "Save/Saved_Hero_Y.txt";
};

class Memento {
public:
    virtual ~Memento() {}
    virtual std::vector<std::vector<Cell>> get_field() const = 0;
    virtual int hero_position(Singleton_Hero::coordinates) const = 0;
    virtual int hero_attribute(Singleton_Hero::hero_attributes) const = 0;
    virtual int field_level() const = 0;
};


#endif //MY_GAME_MEMENTO_H
