//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_INVENTORY_H
#define MY_GAME_INVENTORY_H
#include "Interfaces/IConsumable.h"
#include "Interfaces/IEquipment.h"
#include "Factories/Equipment_Factory.h"
#include "Factories/Consumables_Factory.h"
#include <vector>
#include <cmath>


// Не добавлять в синглтон - будет ошибка

class Inventory {
public:
    Inventory();

    void switch_consumable();
    void switch_equipment();

    int get_consumable_switcher();
    int get_equipment_switcher();

    std::vector <IConsumable*> get_consumable_slots();
    std::vector <IEquipment*> get_equipment_slots();

    void use_consumable();

    void add_consumable(IConsumable*);
    void add_equipment(IEquipment*);

    void throw_out(IConsumable*);
    void throw_out(IEquipment*);
    void delete_consumable(IConsumable*);
    void delete_equipment(IEquipment*);

    bool has_empty_consumable_slots();
    bool has_empty_equipment_slots();

    void clear_inventory();
private:

    std::vector <IConsumable*> consumable_slots;
    std::vector <IEquipment*> equipment_slots;

    Equipment_Factory* equipmentFactory;
    Consumables_Factory* consumablesFactory;

    int consumable_switcher;
    int equipment_switcher;


};


#endif //MY_GAME_INVENTORY_H
