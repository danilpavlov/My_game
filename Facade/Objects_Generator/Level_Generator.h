//
// Created by Даниил Павлов on 09.10.2022.
//

#ifndef MY_GAME_LEVEL_GENERATOR_H
#define MY_GAME_LEVEL_GENERATOR_H

#include "../Field/Field.h"
#include "../Logs/ISubject.h"
#include "Rules/Rule_1/Rule_Hero_Spawn.h"
#include "Rules/Rule_3/Rule_Win_Cell_Spawn.h"
#include "Rules/Rule_9/Rule_Equipment_Spawn.h"
#include "Rules/Rule_10/Rule_Consumables_Spawn.h"

#include <iostream>
#include <exception>

template <typename ... Types>
class Level_Generator{
public:
    Level_Generator(Field*);

    void hero_spawn(int x, int y, Field* main_field);
    void win_cell_spawn(int x, int y, Field* main_field);
    void equipment_spawn(int magic_number, int amount, Field* main_field);
    void consumables_spawn(int magic_number, int amount, Field* main_field);

    void set_rules(Types *... args, int magic_number, int amount, Field* main_field);

    ~Level_Generator();
private:
    Rule_Hero_Spawn<int, int> *HeroSpawn;
    Rule_Win_Cell_Spawn<int, int> *WinCellSpawn;
    Rule_Equipment_Spawn<int, int> *EquipmentSpawn;
    Rule_Consumables_Spawn<int, int> *ConsumablesSpawn;
};


template<typename... Types>
void Level_Generator<Types...>::set_rules(Types*... args, int magic_number, int amount, Field* main_field) {
    ((args)->operator()(magic_number, amount, main_field), ...);
}

template<typename... Types>
void Level_Generator<Types...>::hero_spawn(int x, int y, Field* main_field) {
    HeroSpawn->operator()(x, y, main_field);
}

template<typename... Types>
void Level_Generator<Types...>::win_cell_spawn(int x, int y, Field *main_field) {
    WinCellSpawn->operator()(x, y, main_field);
}

template<typename... Types>
void
Level_Generator<Types...>::equipment_spawn(int magic_number, int amount, Field *main_field) {
    EquipmentSpawn->operator()(magic_number, amount, main_field);
}

template<typename... Types>
void
Level_Generator<Types...>::consumables_spawn(int magic_number,int amount, Field *main_field) {
    ConsumablesSpawn->operator()(magic_number, amount, main_field);
}

template<typename... Types>
Level_Generator<Types...>::Level_Generator(Field* ground) {
    EquipmentSpawn = new Rule_Equipment_Spawn<int, int>(ground);
    ConsumablesSpawn = new Rule_Consumables_Spawn<int, int>(ground);
    HeroSpawn = new Rule_Hero_Spawn<int, int>(ground);
    WinCellSpawn = new Rule_Win_Cell_Spawn<int, int>(ground);
}

template<typename... Types>
Level_Generator<Types...>::~Level_Generator() {
    delete EquipmentSpawn;
    delete ConsumablesSpawn;
    delete HeroSpawn;
    delete WinCellSpawn;
}


#endif //MY_GAME_LEVEL_GENERATOR_H
