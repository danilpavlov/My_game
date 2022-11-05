//
// Created by Даниил Павлов on 23.10.2022.
//

#ifndef MY_GAME_SAVER_H
#define MY_GAME_SAVER_H
#include "../Field/Field.h"
#include "Memento_Save.h"

class Saver {
public:
    void save(Field* main_filed);
    void restore(Memento* memento, Field* main_field);
    Memento* save_current_memento();

private:
    Save_Files saveFiles;

    void open_all_files();
    void close_all_files();
    void clear_all_files();
};


#endif //MY_GAME_SAVER_H
