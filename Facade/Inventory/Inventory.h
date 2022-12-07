//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_INVENTORY_H
#define MY_GAME_INVENTORY_H
#include "Interfaces/IConsumable.h"
#include "Interfaces/IEquipment.h"
#include "Factories/Equipment_Factory.h"
#include "Factories/Consumables_Factory.h"

#include "Buffs/Buff_Table.h"

#include <vector>
#include <cmath>
#define MAX_SLOTS 3

class Inventory {
public:
    Inventory();

    void switch_consumable();
    void switch_mask();
    void switch_boot();


    int get_consumable_switcher();
    int get_mask_switcher();
    int get_weapon_switcher();

    std::vector <IConsumable*> get_consumable_slots();
    std::vector <IMask*> get_mask_slots();
    std::vector <IWeapon*> get_boot_slots();

    void use_consumable();

    void add_consumable(IConsumable*);
    void add_mask(IMask*);
    void add_weapon(IWeapon*);

    void throw_out(IConsumable*);
    void throw_out(IMask*);
    void throw_out(IWeapon*);

    void delete_consumable(IConsumable*);
    void delete_mask(IMask*);
    void delete_weapon(IWeapon*);

    bool has_empty_consumable_slots();
    bool has_empty_mask_slots();
    bool has_empty_weapon_slots();

    void clear_inventory();
    void calculate_weight();
private:

    std::vector <IConsumable*> consumable_slots;
    std::vector <IMask*> mask_slots;
    std::vector <IWeapon*> weapon_slots;

    Equipment_Factory* equipmentFactory;
    Consumables_Factory* consumablesFactory;

    int consumable_switcher;
    int mask_switcher;
    int weapon_switcher;

};


#endif //MY_GAME_INVENTORY_H
