//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_EQUIPMENT_FACTORY_H
#define MY_GAME_EQUIPMENT_FACTORY_H
#include "../ConcreteMasks/Ghost_Head.h"
#include "../ConcreteMasks/Pumpkin_Head.h"
#include "../ConcreteMasks/No_Head.h"

#include "../ConcreteBoots/Slippers.h"
#include "../ConcreteBoots/Socks.h"
#include "../ConcreteBoots/No_Boots.h"


class Equipment_Factory {
public:
    IMask* put_ghost_head_in_inventory();
    IMask* put_pumpkin_head_in_inventory();
    IMask* put_no_head_in_inventory();

    IBoot* put_slippers_in_inventory();
    IBoot* put_socks_in_inventory();
    IBoot* put_no_boot_in_inventory();

};


#endif //MY_GAME_EQUIPMENT_FACTORY_H
