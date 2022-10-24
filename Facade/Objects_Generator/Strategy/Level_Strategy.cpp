//
// Created by Даниил Павлов on 20.10.2022.
//

#include "Level_Strategy.h"


Level_Strategy::Level_Strategy(Field* ground) {
    HeroSpawn = new Rule_Hero_Spawn<int, int>(ground);
    WallsSpawn = new Rule_Walls_Spawn<int>(ground);
    WinCellSpawn = new Rule_Win_Cell_Spawn<int, int>(ground);
    EnemiesSpawn = new Rule_Enemies_Spawn<int, int>(ground);
    XPsSpawn = new Rule_XPs_Spawn<int, int>(ground);
    HealsSpawn = new Rule_Heals_Spawn<int, int>(ground);
    TeleportsSpawn = new Rule_Teleports_Spawn<int, int>(ground);
    RefresherSpawn = new Rule_Refresher_Spawn<int, int>(ground);

    levelGenerator = new Level_Generator<Rule_Hero_Spawn<int, int>,
                                        Rule_Win_Cell_Spawn<int, int>,
                                        Rule_Walls_Spawn<int>,
                                        Rule_Enemies_Spawn<int, int>,
                                        Rule_XPs_Spawn<int, int>,
                                        Rule_Heals_Spawn<int, int>,
                                        Rule_Teleports_Spawn<int, int>,
                                        Rule_Refresher_Spawn<int, int>>;
}
