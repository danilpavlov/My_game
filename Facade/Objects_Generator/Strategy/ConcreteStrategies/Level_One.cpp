//
// Created by Даниил Павлов on 20.10.2022.
//

#include "Level_One.h"

void Level_One::generate_level(Field *ground) {

    levelGenerator->hero_spawn(1, 1, HeroSpawn, ground);
    levelGenerator->win_cell_spawn(30, 1, WinCellSpawn, ground);
    levelGenerator->equipment_spawn(54, 4, EquipmentSpawn, ground);
    levelGenerator->consumables_spawn(69, 6, ConsumablesSpawn, ground);

    levelGenerator->set_rules(WallsSpawn, EnemiesSpawn, XPsSpawn, HealsSpawn, TeleportsSpawn, RefresherSpawn, 123, 9, ground);
}

Level_One::Level_One(Field *pField) : Level_Strategy(pField) {

}
