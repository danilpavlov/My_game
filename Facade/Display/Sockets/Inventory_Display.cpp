//
// Created by Даниил Павлов on 30.10.2022.
//

#include "Inventory_Display.h"
#define TAB "\t\t\t\t\t\t\t   "

void Inventory_Display::draw_inventory(Inventory *inventory) {
    char yellow_color[] = { 0x1b, '[', '3', '8',';','5',';','2', '2', '0', 'm',0 };
    char orange_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '3', '0', 'm',0 };
    char purple_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '2', '8', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    std::cout << TAB << orange_color << "Equipment     " << purple_color << "|" << orange_color <<"     Consumables"<<std::endl << normal <<TAB;

    for (int i = 0; i < inventory->get_equipment_slots().size(); i++){
        std::cout << inventory->get_equipment_slots()[i]->get_icon();
        std::cout << " ";
    }
    std::cout << yellow_color <<"     |     " << normal;

    for (int i = 0; i < inventory->get_consumable_slots().size(); i++){
        std::cout << inventory->get_consumable_slots()[i]->get_icon();
        std::cout << " ";
    }
    std::cout << std::endl << TAB;

    if (inventory->get_equipment_switcher()%3 == 0) {
        std::cout << "🔺            ";
    }else if (inventory->get_equipment_switcher()%3 == 1){
        std::cout << "   🔺         ";
    }else if (inventory->get_equipment_switcher()%3 == 2){
        std::cout << "      🔺      ";
    }

    std::cout << purple_color << "|     " << normal;

    if (inventory->get_consumable_switcher()%3 == 0) {
        std::cout << "🔺            " << std::endl;
    }else if (inventory->get_consumable_switcher()%3 == 1){
        std::cout << "   🔺         " << std::endl;
    }else if (inventory->get_consumable_switcher()%3 == 2){
        std::cout << "      🔺      " << std::endl;
    }
}
