//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Inventory.h"

void Inventory::switch_consumable() {
    consumable_switcher++;
}

void Inventory::switch_equipment() {
    equipment_switcher++;
    equipment_slots[equipment_switcher%3]->put_on();
}



void Inventory::throw_out(IConsumable *some_consumable) {
    if (!some_consumable->is_empty()) {
        consumable_slots.erase(std::remove(consumable_slots.begin(), consumable_slots.end(), some_consumable),
                               consumable_slots.end());

        consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
    }
}

void Inventory::throw_out(IEquipment *some_equipment) {
    if (!some_equipment->is_empty()) {
        equipment_slots.erase(std::remove(equipment_slots.begin(), equipment_slots.end(), some_equipment),
                              equipment_slots.end());

        equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());

        equipment_slots[equipment_switcher%3]->put_on();
    }
}

void Inventory::use_consumable() {
    consumable_slots[consumable_switcher%3]->use();
    throw_out(consumable_slots[consumable_switcher%3]);
}

void Inventory::delete_consumable(IConsumable* some_consumable) {
    consumable_slots.erase(std::remove(consumable_slots.begin(), consumable_slots.end(), some_consumable),
                           consumable_slots.end());
}

void Inventory::delete_equipment(IEquipment* some_equipment) {
    equipment_slots.erase(std::remove(equipment_slots.begin(), equipment_slots.end(), some_equipment),
                          equipment_slots.end());

}

void Inventory::add_consumable(IConsumable *some_consumable) {

    bool can_add = false;
    for (int i = 0; i < 3; i++){
        if (consumable_slots[i]->is_empty()){
            delete_consumable(consumable_slots[i]);
            can_add = true;
            break;
        }
    }

    if (can_add) {
        consumable_slots.push_back(some_consumable);
    }
}

void Inventory::add_equipment(IEquipment *some_equipment) {

    bool can_add = false;
    for (int i = 0; i < 3; i++){
        if (equipment_slots[i]->is_empty()){
            delete_equipment(equipment_slots[i]);
            can_add = true;

            break;
        }
    }
    if (can_add) {
        equipment_slots.push_back(some_equipment);
        equipment_slots[equipment_switcher%3]->put_on();
    }
}



int Inventory::get_equipment_switcher() {
    return equipment_switcher;
}

int Inventory::get_consumable_switcher() {
    return consumable_switcher;
}

std::vector<IConsumable *> Inventory::get_consumable_slots() {
    return consumable_slots;
}

std::vector<IEquipment *> Inventory::get_equipment_slots() {
    return equipment_slots;
}

Inventory::Inventory() {
    consumable_switcher = 0;
    equipment_switcher = 0;
    equipmentFactory = new Equipment_Factory;
    consumablesFactory = new Consumables_Factory;


    equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());
    equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());
    equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());

    consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
    consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
    consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
}

bool Inventory::has_empty_consumable_slots() {
    for (int i = 0; i < 3; i++){
        if (consumable_slots[i]->is_empty()){
            return true;
        }
    }
    return false;
}

bool Inventory::has_empty_equipment_slots() {
    for (int i = 0; i < 3; i++){
        if (equipment_slots[i]->is_empty()){
            return true;
        }
    }
    return false;
}

void Inventory::clear_inventory() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    hero->set_hero_model(DEFAULT_HERO_MODEL);
    hero->set_ghost_status(false);
    hero->set_pumpkin_status(false);

    equipment_slots.clear();
    consumable_slots.clear();

    equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());
    equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());
    equipment_slots.push_back(equipmentFactory->put_no_equipment_in_inventory());

    consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
    consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
    consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
}


