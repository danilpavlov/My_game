//
// Created by Даниил Павлов on 20.10.2022.
//

#ifndef MY_GAME_LEVEL_STRATEGY_H
#define MY_GAME_LEVEL_STRATEGY_H
#include "../../Field/Field.h"
#include "../Rules/Rule_2/Rule_Walls_Spawn.h"
#include "../Rules/Rule_1/Rule_Hero_Spawn.h"
#include "../Rules/Rule_3/Rule_Win_Cell_Spawn.h"
#include "../Rules/Rule_4/Rule_Enemies_Spawn.h"
#include "../Rules/Rule_5/Rule_XPs_Spawn.h"
#include "../Rules/Rule_6/Rule_Heals_Spawn.h"
#include "../Rules/Rule_7/Rule_Teleports_Spawn.h"
#include "../Rules/Rule_8/Rule_Refresher_Spawn.h"
#include "../Rules/Rule_9/Rule_Equipment_Spawn.h"
#include "../Rules/Rule_10/Rule_Consumables_Spawn.h"
#include "../Level_Generator.h"

class Level_Strategy {
public:
    virtual ~Level_Strategy() = default;
    virtual void generate_level(Field* field) = 0;
};


#endif //MY_GAME_LEVEL_STRATEGY_H
