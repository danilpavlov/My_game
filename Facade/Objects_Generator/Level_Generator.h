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

template <typename ... Rules>
class Level_Generator{
public:
    void set_rules(Field* field);

};


template<typename... Rules>
void Level_Generator<Rules...>::set_rules(Field* field) {
    (Rules::establish(field), ...);
    //(Rules(field), ...);
    //// P.S. Лучше все-таки сделать так, чтобы этот метод возвращал поле, а не как у меня
}



#endif //MY_GAME_LEVEL_GENERATOR_H
