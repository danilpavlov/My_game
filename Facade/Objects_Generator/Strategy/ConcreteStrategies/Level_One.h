//
// Created by Даниил Павлов on 20.10.2022.
//

#ifndef MY_GAME_LEVEL_ONE_H
#define MY_GAME_LEVEL_ONE_H
#include "../Level_Strategy.h"

class Level_One : public Level_Strategy{
public:
    Level_One(Field *pField);

    void generate_level(Field* filed) override;
private:
    Level_Generator<Rule_Hero_Spawn<1, 1>,
                    Rule_Win_Cell_Spawn<30, 1>,
                    Rule_Walls_Spawn<123>,
                    Rule_Enemies_Spawn<123, 5>,
                    Rule_Teleports_Spawn<123, 3>,
                    Rule_XPs_Spawn<123, 10>,
                    Rule_Heals_Spawn<123, 5>,
                    Rule_Refresher_Spawn<123, 3>,
                    Rule_Equipment_Spawn<123, 3>,
                    Rule_Consumables_Spawn<123, 5>
                    > levelGenerator;
};


#endif //MY_GAME_LEVEL_ONE_H
