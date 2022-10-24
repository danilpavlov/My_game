//
// Created by Даниил Павлов on 20.10.2022.
//

#ifndef MY_GAME_LEVEL_ONE_H
#define MY_GAME_LEVEL_ONE_H
#include "../Level_Strategy.h"

class Level_One : public Level_Strategy{
public:
    Level_One(Field *pField);

    void generate_level(Field* filed);
};


#endif //MY_GAME_LEVEL_ONE_H
