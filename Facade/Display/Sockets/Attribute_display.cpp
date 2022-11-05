//
// Created by Даниил Павлов on 21.09.2022.
//

#include "Attribute_display.h"
#include <iostream>


void Attribute_display::show_hp_display() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };


    char big_heart_color[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '0', 'm',0 };
    char small_hearts_color[] = { 0x1b, '[', '3', '8',';','5',';','2','2', '0', 'm',0 };
    char bg_color[] = { 0x1b, '[', '3', '8',';','5',';','9', '4', 'm',0 };


    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << bg_color <<"__"<< big_heart_color <<"♥"<< big_heart_color <<"__"<< big_heart_color <<"♥"<< bg_color <<"_____"<< big_heart_color <<"♥"<< big_heart_color <<"__"<< big_heart_color <<"♥"<< bg_color <<"___"<< normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << "_"<< big_heart_color <<"♥"<< big_heart_color <<"_____"<< big_heart_color <<"♥"<< bg_color <<"_"<< big_heart_color <<"♥"<< big_heart_color <<"_____"<< big_heart_color <<"♥"<< bg_color <<"__" << normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color <<"_"<< big_heart_color <<"♥"<< big_heart_color <<"______"<< big_heart_color <<"♥"<< big_heart_color <<"______"<< big_heart_color <<"♥"<< bg_color <<"__" << normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << "__"<< big_heart_color <<"♥"<< big_heart_color<<"_____"<< small_hearts_color <<"/"<< big_heart_color <<"______"<< big_heart_color <<"♥"<< bg_color <<"__" << normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << "___"<< big_heart_color <<"♥"<< big_heart_color <<"____"<< small_hearts_color << "\\"<< big_heart_color <<"_____"<< big_heart_color <<"♥"<< bg_color <<"___" << normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << "____"<< big_heart_color <<"♥"<< big_heart_color <<"___"<< small_hearts_color <<"/"<< big_heart_color <<"___"<< big_heart_color <<"♥"<< bg_color <<"_____" << normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << "______"<< big_heart_color <<"♥"<< big_heart_color <<"_"<< small_hearts_color <<"\\" << big_heart_color <<"_"<< big_heart_color <<"♥"<< bg_color <<"_______"<< normal;
    }
    std::cout<<std::endl;

    for (int i = 0; i<hero->get_hero_attribute(Singleton_Hero::health_points); i++) {
        std::cout << bg_color << "________"<< big_heart_color<<"♥"<< bg_color <<"_________" << normal;
    }
    std::cout<<std::endl;


}

void Attribute_display::show_xp_display() {
    Singleton_Hero* hero = Singleton_Hero::getInstance();

    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    char xp_color[] = { 0x1b, '[', '3', '8',';','5',';','9', '3', 'm',0 };
    char no_xp_color[] = { 0x1b, '[', '3', '8',';','5',';','2','4', '1', 'm',0 };

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << "  .----------------. " << normal;
        }else{
            std::cout<< no_xp_color << "  .----------------. " << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | .--------------. |" << normal;
        }else{
            std::cout<< no_xp_color << " | .--------------. |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i <7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |      _       | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |      _       | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |   /\\| |/\\    | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |   /\\| |/\\    | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |   \\     /    | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |   \\     /    | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |  |_     _|   | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |  |_     _|   | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |   /     \\    | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |   /     \\    | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |   \\/|_|\\/    | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |   \\/|_|\\/    | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | |              | |" << normal;
        }else{
            std::cout<< no_xp_color << " | |              | |" << normal;
        }
    }

    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << " | '--------------' |" << normal;
        }else{
            std::cout<< no_xp_color << " | '--------------' |" << normal;
        }
    }
    std::cout<< std::endl;

    for (int i = 0; i < 7; i++){
        if (hero->get_hero_attribute(Singleton_Hero::experience)%7 >= i){
            std::cout<< xp_color << "  '----------------' " << normal;
        }else{
            std::cout<< no_xp_color << "  '----------------' " << normal;
        }
    }
    std::cout<< std::endl;


}






