//
// Created by Даниил Павлов on 20.10.2022.
//

#ifndef MY_GAME_LEVEL_TWO_H
#define MY_GAME_LEVEL_TWO_H
#include "../Level_Strategy.h"

class Level_Two : public Level_Strategy{
public:
    Level_Two(Field*);

    void generate_level(Field* field) override;
};


#endif //MY_GAME_LEVEL_TWO_H
