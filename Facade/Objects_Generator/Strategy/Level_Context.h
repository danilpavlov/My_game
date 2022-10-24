//
// Created by Даниил Павлов on 20.10.2022.
//

#ifndef MY_GAME_LEVEL_CONTEXT_H
#define MY_GAME_LEVEL_CONTEXT_H
#include "Level_Strategy.h"

class Level_Context {
public:
    explicit Level_Context(std::unique_ptr<Level_Strategy> &&strategy = {}) : strategy_(std::move(strategy)){}

    void set_strategy(std::unique_ptr<Level_Strategy> &&strategy);

    void create_new_level(Field* field) const;

private:
    std::unique_ptr<Level_Strategy> strategy_;

};


#endif //MY_GAME_LEVEL_CONTEXT_H
