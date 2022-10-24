//
// Created by Даниил Павлов on 20.10.2022.
//

#include "Level_Two.h"

void Level_Two::generate_level(Field *field) {
    levelGenerator->hero_spawn(1, 20, HeroSpawn, field);
    levelGenerator->win_cell_spawn(30, 10, WinCellSpawn, field);
    levelGenerator->walls_spawn(666666, WallsSpawn, field);
    levelGenerator->set_rules(EnemiesSpawn, XPsSpawn, HealsSpawn, TeleportsSpawn, RefresherSpawn, 666, 15, field);

}

Level_Two::Level_Two(Field *pField) : Level_Strategy(pField) {

}
