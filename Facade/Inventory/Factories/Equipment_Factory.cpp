//
// Created by Даниил Павлов on 29.10.2022.
//

#include "Equipment_Factory.h"

IMask *Equipment_Factory::put_ghost_head_in_inventory() {
    return new Ghost_Head;
}

IMask *Equipment_Factory::put_pumpkin_head_in_inventory() {
    return new Pumpkin_Head;
}

IMask *Equipment_Factory::put_no_head_in_inventory() {
    return new No_Head;
}

IWeapon *Equipment_Factory::put_magic_glove_in_inventory() {
    return new Magic_Glove;
}

IWeapon *Equipment_Factory::put_dagger_in_inventory() {
    return new Dagger;
}

IWeapon *Equipment_Factory::put_no_weapon_in_inventory() {
    return new No_Weapon;
}
