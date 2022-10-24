//
// Created by Даниил Павлов on 20.10.2022.
//

#include "Level_One.h"

void Level_One::generate_level(Field *ground) {

    levelGenerator->hero_spawn(1, 1, HeroSpawn, ground);
    levelGenerator->win_cell_spawn(30, 1, WinCellSpawn, ground);
    levelGenerator->walls_spawn(123, WallsSpawn, ground);
    levelGenerator->set_rules(EnemiesSpawn, XPsSpawn, HealsSpawn, TeleportsSpawn, RefresherSpawn, 8, 9, ground);
}

Level_One::Level_One(Field *pField) : Level_Strategy(pField) {

}
