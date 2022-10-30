//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Consumables_Factory.h"

IConsumable *Consumables_Factory::put_drug_in_inventory() {
    return new Drug;
}

IConsumable *Consumables_Factory::put_heal_potion_in_inventory() {
    return new Heal_Potion;
}

IConsumable *Consumables_Factory::put_no_consumable_in_inventory() {
    return new No_Consumable;
}
