//
// Created by Даниил Павлов on 17.09.2022.
//

#include "Singleton_Hero.h"
#include <iostream>

Singleton_Hero *Singleton_Hero::getInstance() {
    if (instance == 0){
        instance = new Singleton_Hero();
    }

    return instance;
}

Singleton_Hero* Singleton_Hero::instance = 0;

Singleton_Hero::Singleton_Hero(){
    this->lv = 0;
    this->hp = 9;
    this->xp = 0;
}


void Singleton_Hero::set_hero_attribute(int attribute_number, int new_number_of_some_attribute) {
    switch(attribute_number){
        case (hero_attributes::health_points):
            this->hp = new_number_of_some_attribute;
            break;
        case (hero_attributes::experience):
            this->xp = new_number_of_some_attribute;
            break;
        case (hero_attributes::level):
            this->lv = new_number_of_some_attribute;
            break;
        default:
            break;
    }

}

int Singleton_Hero::get_hero_attribute(int attribute_number) {
    switch(attribute_number){
        case (hero_attributes::health_points):
            return this->hp;
        case (hero_attributes::experience):
            return this->xp;
        case (hero_attributes::level):
            return this->lv;
        default:
            return 0;
    }

}

void Singleton_Hero::set_hero_position(int coordinate_number, int new_position) {
    switch (coordinate_number) {
        case (coordinates::x):
            this->x_hero_position = new_position;
            break;
        case (coordinates::y):
            this->y_hero_position = new_position;
            break;
        default:
            break;
    }

}

int Singleton_Hero::get_hero_position(int coordinate_number) {
    switch (coordinate_number){
        case (coordinates::x):
            return this->x_hero_position;
        case (coordinates::y):
            return this->y_hero_position;
        default:
            return 0;
    }
}


void Singleton_Hero::dead() {
    alive = false;
}

bool Singleton_Hero::is_alive() {
    return alive;
}

void Singleton_Hero::hero_won() {
    victory = true;
}

bool Singleton_Hero::is_hero_won() {
    return victory;
}

bool Singleton_Hero::did_hero_eat_shroom() {
    return hero_eated_shroom;
}

void Singleton_Hero::set_hero_shroom_status(bool new_shroom_status) {
    hero_eated_shroom = new_shroom_status;
}

void Singleton_Hero::set_hero_to_default(int new_x, int new_y) {
    this->lv = 0;
    this->hp = 9;
    this->xp = 0;
    x_hero_position = new_x;
    y_hero_position = new_y;
    alive = true;
    victory = false;
    hero_eated_shroom = false;
}

std::string Singleton_Hero::get_hero_model() {
    return hero_model;
}

void Singleton_Hero::set_hero_model(std::string new_model) {
    hero_model = new_model;
}

void Singleton_Hero::set_ghost_status(bool new_status) {
    ghost_status = new_status;
}

void Singleton_Hero::set_pumpkin_status(bool new_status) {
    pumpkin_status = new_status;
}

bool Singleton_Hero::get_ghost_status() {
    return ghost_status;
}

bool Singleton_Hero::get_pumpkin_status() {
    return pumpkin_status;
}

void Singleton_Hero::set_hero_moved_on_wall(bool new_status) {
    hero_moved_on_wall = new_status;
}

bool Singleton_Hero::were_moved_on_wall() {
    return hero_moved_on_wall;
}
















