//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_CONSUMABLES_FACTORY_H
#define MY_GAME_CONSUMABLES_FACTORY_H
#include "../ConcreteConsumables/Heal_Potion.h"
#include "../ConcreteConsumables/Drug.h"
#include "../ConcreteConsumables/No_Consumable.h"

class Consumables_Factory {
public:
    IConsumable* put_drug_in_inventory();
    IConsumable* put_heal_potion_in_inventory();
    IConsumable* put_no_consumable_in_inventory();

};


#endif //MY_GAME_CONSUMABLES_FACTORY_H
