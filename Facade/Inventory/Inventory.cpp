//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Inventory.h"

void Inventory::switch_consumable() {
    consumable_switcher++;
}

void Inventory::switch_mask() {
    mask_switcher++;
    mask_slots[mask_switcher % MAX_SLOTS]->put_on();
}



void Inventory::throw_out(IConsumable *some_consumable) {
    if (!some_consumable->is_empty()) {
        consumable_slots.erase(std::remove(consumable_slots.begin(), consumable_slots.end(), some_consumable),
                               consumable_slots.end());

        consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
    }
    calculate_weight();
}

void Inventory::throw_out(IMask *some_equipment) {
    if (!some_equipment->is_empty()) {
        mask_slots.erase(std::remove(mask_slots.begin(), mask_slots.end(), some_equipment),
                              mask_slots.end());

        mask_slots.push_back(equipmentFactory->put_no_head_in_inventory());

        mask_slots[mask_switcher % MAX_SLOTS]->put_on();
    }
    calculate_weight();
}

void Inventory::use_consumable() {
    consumable_slots[consumable_switcher % MAX_SLOTS]->use();
    throw_out(consumable_slots[consumable_switcher % MAX_SLOTS]);
}

void Inventory::delete_consumable(IConsumable* some_consumable) {
    consumable_slots.erase(std::remove(consumable_slots.begin(), consumable_slots.end(), some_consumable),
                           consumable_slots.end());
    calculate_weight();
}

void Inventory::delete_mask(IMask* some_equipment) {
    mask_slots.erase(std::remove(mask_slots.begin(), mask_slots.end(), some_equipment),
                          mask_slots.end());
    calculate_weight();

}

void Inventory::add_consumable(IConsumable *some_consumable) {

    bool can_add = false;
    for (int i = 0; i < MAX_SLOTS; i++){
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

void Inventory::add_mask(IMask *some_equipment) {

    bool can_add = false;
    for (int i = 0; i < MAX_SLOTS; i++){
        if (mask_slots[i]->is_empty()){
            delete_mask(mask_slots[i]);
            can_add = true;

            break;
        }
    }
    if (can_add) {
        mask_slots.push_back(some_equipment);
        mask_slots[mask_switcher % MAX_SLOTS]->put_on();
    }
}



int Inventory::get_mask_switcher() {
    return mask_switcher;
}

int Inventory::get_consumable_switcher() {
    return consumable_switcher;
}

std::vector<IConsumable *> Inventory::get_consumable_slots() {
    return consumable_slots;
}

std::vector<IMask *> Inventory::get_mask_slots() {
    return mask_slots;
}

Inventory::Inventory() {
    consumable_switcher = 0;
    mask_switcher = 0;
    equipmentFactory = new Equipment_Factory;
    consumablesFactory = new Consumables_Factory;

    for (int i = 0; i < MAX_SLOTS; i++){
        mask_slots.push_back(equipmentFactory->put_no_head_in_inventory());
        consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
        weapon_slots.push_back(equipmentFactory->put_no_weapon_in_inventory());
    }
}

bool Inventory::has_empty_consumable_slots() {
    for (int i = 0; i < MAX_SLOTS; i++){
        if (consumable_slots[i]->is_empty()){
            return true;
        }
    }
    return false;
}

bool Inventory::has_empty_mask_slots() {
    for (int i = 0; i < MAX_SLOTS; i++){
        if (mask_slots[i]->is_empty()){
            return true;
        }
    }
    return false;
}

void Inventory::clear_inventory() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    Buff_Table* buffTable = Buff_Table::getInstance();
    hero->set_hero_model(DEFAULT_HERO_MODEL);

    buffTable->remove_buff(IBuff::WEAPON);
    buffTable->remove_buff(IBuff::MASK);

    hero->set_weight(0);

    mask_slots.clear();
    consumable_slots.clear();
    weapon_slots.clear();

    for (int i = 0; i < MAX_SLOTS; i++){
        mask_slots.push_back(equipmentFactory->put_no_head_in_inventory());
        consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
        weapon_slots.push_back(equipmentFactory->put_no_weapon_in_inventory());
    }
    calculate_weight();
}

void Inventory::switch_boot() {
    weapon_switcher++;
    weapon_slots[weapon_switcher % MAX_SLOTS]->put_on();
}

int Inventory::get_weapon_switcher() {
    return weapon_switcher;
}

std::vector<IWeapon *> Inventory::get_boot_slots() {
    return weapon_slots;
}

void Inventory::throw_out(IWeapon *some_equipment) {
    if (!some_equipment->is_empty()) {
        weapon_slots.erase(std::remove(weapon_slots.begin(), weapon_slots.end(), some_equipment),
                         weapon_slots.end());

        weapon_slots.push_back(equipmentFactory->put_no_weapon_in_inventory());

        weapon_slots[weapon_switcher % MAX_SLOTS]->put_on();
    }
    calculate_weight();
}

void Inventory::add_weapon(IWeapon *some_weapon) {
    bool can_add = false;
    for (int i = 0; i < MAX_SLOTS; i++){
        if (weapon_slots[i]->is_empty()){
            delete_weapon(weapon_slots[i]);
            can_add = true;
            break;
        }
    }

    if (can_add) {
        weapon_slots.push_back(some_weapon);
        weapon_slots[weapon_switcher % MAX_SLOTS]->put_on();
    }
}

void Inventory::delete_weapon(IWeapon *some_boot) {
    weapon_slots.erase(std::remove(weapon_slots.begin(), weapon_slots.end(), some_boot),
                     weapon_slots.end());
}

bool Inventory::has_empty_weapon_slots() {

    for (int i = 0; i < MAX_SLOTS; i++){
        if (weapon_slots[i]->is_empty()){
            return true;
        }
    }
    return false;
}

void Inventory::calculate_weight() {
    int result = 0;
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    for (int i = 0; i < MAX_SLOTS; i++) {
        result += mask_slots[i]->get_weight();
        result += weapon_slots[i]->get_weight();
        result += consumable_slots[i]->get_weight();
    }
    hero->set_weight(result);
}



