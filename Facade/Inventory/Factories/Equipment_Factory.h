//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_EQUIPMENT_FACTORY_H
#define MY_GAME_EQUIPMENT_FACTORY_H
#include "../ConcreteMasks/Ghost_Head.h"
#include "../ConcreteMasks/Pumpkin_Head.h"
#include "../ConcreteMasks/No_Head.h"

#include "../ConcreteWeapon/Magic_Glove.h"
#include "../ConcreteWeapon/Dagger.h"
#include "../ConcreteWeapon/No_Weapon.h"


class Equipment_Factory {
public:
    IMask* put_ghost_head_in_inventory();
    IMask* put_pumpkin_head_in_inventory();
    IMask* put_no_head_in_inventory();

    IWeapon* put_magic_glove_in_inventory();
    IWeapon* put_dagger_in_inventory();
    IWeapon* put_no_weapon_in_inventory();

};


#endif //MY_GAME_EQUIPMENT_FACTORY_H
