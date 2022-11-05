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
        boot_slots.push_back(equipmentFactory->put_no_boot_in_inventory());
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
    hero->set_hero_model(DEFAULT_HERO_MODEL);
    hero->set_ghost_status(false);
    hero->set_pumpkin_status(false);
    hero->set_socks_status(false);
    hero->set_slippers_status(false);

    hero->set_weight(0);

    mask_slots.clear();
    consumable_slots.clear();
    boot_slots.clear();

    for (int i = 0; i < MAX_SLOTS; i++){
        mask_slots.push_back(equipmentFactory->put_no_head_in_inventory());
        consumable_slots.push_back(consumablesFactory->put_no_consumable_in_inventory());
        boot_slots.push_back(equipmentFactory->put_no_boot_in_inventory());
    }
    calculate_weight();
}

void Inventory::switch_boot() {
    boot_switcher++;
    boot_slots[boot_switcher % MAX_SLOTS]->put_on();
}

int Inventory::get_boot_switcher() {
    return boot_switcher;
}

std::vector<IBoot *> Inventory::get_boot_slots() {
    return boot_slots;
}

void Inventory::throw_out(IBoot *some_equipment) {
    if (!some_equipment->is_empty()) {
        boot_slots.erase(std::remove(boot_slots.begin(), boot_slots.end(), some_equipment),
                         boot_slots.end());

        boot_slots.push_back(equipmentFactory->put_no_boot_in_inventory());

        boot_slots[boot_switcher % MAX_SLOTS]->put_on();
    }
    calculate_weight();
}

void Inventory::add_boot(IBoot *some_boot) {
    bool can_add = false;
    for (int i = 0; i < MAX_SLOTS; i++){
        if (boot_slots[i]->is_empty()){
            delete_boot(boot_slots[i]);
            can_add = true;
            break;
        }
    }

    if (can_add) {
        boot_slots.push_back(some_boot);
    }
}

void Inventory::delete_boot(IBoot *some_boot) {
    boot_slots.erase(std::remove(boot_slots.begin(), boot_slots.end(), some_boot),
                     boot_slots.end());
}

bool Inventory::has_empty_boot_slots() {

    for (int i = 0; i < MAX_SLOTS; i++){
        if (boot_slots[i]->is_empty()){
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
        result += boot_slots[i]->get_weight();
        result += consumable_slots[i]->get_weight();
    }
    hero->set_weight(result);
}



