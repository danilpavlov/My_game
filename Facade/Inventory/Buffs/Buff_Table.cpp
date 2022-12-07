//
// Created by Даниил Павлов on 26.11.2022.
//

#include "Buff_Table.h"

Buff_Table* Buff_Table::instance = nullptr;

Buff_Table *Buff_Table::getInstance() {
    if (instance == nullptr){
        instance = new Buff_Table();
    }

    return instance;
}

void Buff_Table::activate_buffs_of_type(IBuff::type some_type) {
    for (int i = 0; i < buffs_.size(); i++){
        if (buffs_[i]->get_type() == some_type){
            buffs_[i]->execute();
        }
    }

}

void Buff_Table::add_buff(IBuff *buff) {
    buffs_.push_back(buff);
}

void Buff_Table::remove_buff(IBuff::part part_to_remove) {
    for (int i = 0; i < buffs_.size(); i++){
        if (buffs_[i]->get_part() == part_to_remove){
            buffs_.erase(std::remove(buffs_.begin(), buffs_.end(), buffs_[i]), buffs_.end());
        }
    }
}

std::vector<IBuff *> Buff_Table::get_buffs() {
    return buffs_;
}

