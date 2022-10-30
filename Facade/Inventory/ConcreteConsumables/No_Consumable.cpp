//
// Created by Даниил Павлов on 30.10.2022.
//

#include "No_Consumable.h"

void No_Consumable::use() {

}

std::string No_Consumable::get_icon() {
    return "➕";
}

bool No_Consumable::is_empty() {
    return true;
}
