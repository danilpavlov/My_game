//
// Created by Даниил Павлов on 20.10.2022.
//

#include "Level_Two.h"

void Level_Two::generate_level(Field *field) {
    levelGenerator->hero_spawn(1, 20, field);
    levelGenerator->win_cell_spawn(30, 10, field);
    levelGenerator->equipment_spawn(66, 4, field);
    levelGenerator->consumables_spawn(666, 7, field);

    levelGenerator->set_rules(WallsSpawn, EnemiesSpawn, XPsSpawn, HealsSpawn, TeleportsSpawn, RefresherSpawn, 666666, 15, field);

}

Level_Two::Level_Two(Field *pField) : Level_Strategy(pField) {

}
