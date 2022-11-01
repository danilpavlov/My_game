//
// Created by Даниил Павлов on 23.10.2022.
//

#ifndef MY_GAME_SAVER_H
#define MY_GAME_SAVER_H
#include "../Field/Field.h"
#include "Memento_Save.h"
#include <fstream>
class Saver {
public:
    void save(Field* main_filed);
    void restore(Memento* memento, Field* main_field);
    Memento* save_current_memento();

private:
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

    void open_all_files();
    void close_all_files();
    void clear_all_files();
};


#endif //MY_GAME_SAVER_H
