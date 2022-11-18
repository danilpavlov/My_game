//
// Created by Даниил Павлов on 20.10.2022.
//

#ifndef MY_GAME_LEVEL_TWO_H
#define MY_GAME_LEVEL_TWO_H
#include "../Level_Strategy.h"

class Level_Two : public Level_Strategy{
public:
    Level_Two(Field *pField);

    void generate_level(Field* field) override;
private:
    Level_Generator<Rule_Hero_Spawn<1, 20>,
            Rule_Win_Cell_Spawn<30, 10>,
            Rule_Walls_Spawn<666666>,
            Rule_Enemies_Spawn<6666, 9>,
            Rule_Teleports_Spawn<666, 6>,
            Rule_XPs_Spawn<666, 15>,
            Rule_Heals_Spawn<666, 7>,
            Rule_Refresher_Spawn<6666, 4>,
            Rule_Equipment_Spawn<666, 2>,
            Rule_Consumables_Spawn<6666, 5>
    > levelGenerator;
};


#endif //MY_GAME_LEVEL_TWO_H
