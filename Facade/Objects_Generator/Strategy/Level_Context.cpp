//
// Created by Даниил Павлов on 20.10.2022.
//

#include "Level_Context.h"

void Level_Context::set_strategy(std::unique_ptr<Level_Strategy> &&strategy) {
    strategy_ = std::move(strategy);
}

void Level_Context::create_new_level(Field *field) const {
    strategy_->generate_level(field);
}

