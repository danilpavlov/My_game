//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_LEVEL_GENERATOR_H
#define MY_GAME_LEVEL_GENERATOR_H

#include "../Field/Field.h"
#include "../Logs/ISubject.h"

#include <iostream>
#include <exception>

template <typename T1,typename T2,typename T3, typename T4, typename T5, typename ... Types>
class Level_Generator{
public:

    void hero_spawn(int x, int y, T1* hero, Field* main_field);
    void win_cell_spawn(int x, int y, T2* win_cell, Field* main_field);
    void walls_spawn(int magic_number, T3* walls_, Field* main_field);
    void equipment_spawn(int magic_number, int amount, T4* equipment, Field* main_field);
    void consumables_spawn(int magic_number, int amount, T5* consumables, Field* main_field);

    void set_rules(Types *... args, int magic_number, int amount, Field* main_field);


};


template<typename T1, typename T2, typename T3, typename T4, typename T5, typename... Types>
void Level_Generator<T1, T2, T3, T4, T5, Types...>::set_rules(Types*... args, int magic_number, int amount, Field* main_field) {
    ((args)->operator()(magic_number, amount, main_field), ...);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename... Types>
void Level_Generator<T1, T2, T3, T4, T5, Types...>::hero_spawn(int x, int y, T1* hero, Field* main_field) {
    hero->operator()(x, y, main_field);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename... Types>
void Level_Generator<T1, T2, T3, T4, T5, Types...>::win_cell_spawn(int x, int y, T2 *win_cell, Field *main_field) {
    win_cell->operator()(x, y, main_field);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename... Types>
void Level_Generator<T1, T2, T3, T4, T5, Types...>::walls_spawn(int magic_number, T3 *walls_, Field *main_field) {
    walls_->operator()(magic_number, main_field);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename... Types>
void
Level_Generator<T1, T2, T3, T4, T5, Types...>::equipment_spawn(int magic_number, int amount, T4 *equipment, Field *main_field) {
    equipment->operator()(magic_number, amount, main_field);
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename... Types>
void
Level_Generator<T1, T2, T3, T4, T5, Types...>::consumables_spawn(int magic_number,int amount, T5 *consumables, Field *main_field) {
    consumables->operator()(magic_number, amount, main_field);
}


#endif //MY_GAME_LEVEL_GENERATOR_H
