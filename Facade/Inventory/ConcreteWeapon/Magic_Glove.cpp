//
// Created by Даниил Павлов on 02.11.2022.
//

#include "Magic_Glove.h"

void Magic_Glove::put_on() {
    Buff_Table* buffTable = Buff_Table::getInstance();

    buffTable->remove_buff(IBuff::WEAPON);
    buffTable->add_buff(buff);
}

std::string Magic_Glove::get_icon() {
    return "🪬";
}

bool Magic_Glove::is_empty() {
    return false;
}

int Magic_Glove::get_weight() {
    return MAGIC_GLOVE_WEIGHT;
}

Magic_Glove::Magic_Glove() {
    buff = new Magic_Glove_Buff;
}
