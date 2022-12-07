//
// Created by Даниил Павлов on 02.11.2022.
//

#include "Dagger.h"

void Dagger::put_on() {
    Buff_Table* buffTable = Buff_Table::getInstance();

    buffTable->remove_buff(IBuff::WEAPON);
    buffTable->add_buff(buff);
}

std::string Dagger::get_icon() {
    return "🔪";
}

bool Dagger::is_empty() {
    return false;
}

int Dagger::get_weight() {
    return DAGGER_WEIGHT;
}

Dagger::Dagger() {
    buff = new Dagger_Buff;
}
