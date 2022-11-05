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

IBoot *Equipment_Factory::put_slippers_in_inventory() {
    return new Slippers;
}

IBoot *Equipment_Factory::put_socks_in_inventory() {
    return new Socks;
}

IBoot *Equipment_Factory::put_no_boot_in_inventory() {
    return new No_Boots;
}
