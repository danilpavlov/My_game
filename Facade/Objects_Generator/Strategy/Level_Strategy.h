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
    Level_Strategy(Field*);

    virtual ~Level_Strategy() = default;
    virtual void generate_level(Field* field) = 0;

protected:
    Rule_Hero_Spawn<int, int> *HeroSpawn;
    Rule_Walls_Spawn<int, int> *WallsSpawn;
    Rule_Win_Cell_Spawn<int, int> *WinCellSpawn;
    Rule_Enemies_Spawn<int, int> *EnemiesSpawn;
    Rule_XPs_Spawn<int, int> *XPsSpawn;
    Rule_Heals_Spawn<int, int> *HealsSpawn;
    Rule_Teleports_Spawn<int, int> *TeleportsSpawn;
    Rule_Refresher_Spawn<int, int> *RefresherSpawn;
    Rule_Equipment_Spawn<int, int> *EquipmentSpawn;
    Rule_Consumables_Spawn<int, int> *ConsumablesSpawn;


    Level_Generator<    Rule_Hero_Spawn<int, int>,
                        Rule_Win_Cell_Spawn<int, int>,
                        Rule_Equipment_Spawn<int, int>,
                        Rule_Consumables_Spawn<int, int>,

                        Rule_Walls_Spawn<int, int>,
                        Rule_Enemies_Spawn<int, int>,
                        Rule_XPs_Spawn<int, int>,
                        Rule_Heals_Spawn<int, int>,
                        Rule_Teleports_Spawn<int, int>,
                        Rule_Refresher_Spawn<int, int>    > *levelGenerator;

};


#endif //MY_GAME_LEVEL_STRATEGY_H
