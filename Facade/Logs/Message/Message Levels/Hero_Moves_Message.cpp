//
// Created by Даниил Павлов on 13.10.2022.
//

#include "Hero_Moves_Message.h"

std::string Hero_Moves_Message::get_message(int key) {
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    switch (key) {
        case type::HERO_MOVE_LEFT:
            return "[HERO MOVE] Hero moved Left. New coordinates of Hero: X: " + std::to_string(hero->get_hero_position(Singleton_Hero::x)) + "; Y: " + std::to_string(hero->get_hero_position(Singleton_Hero::y));
        case type::HERO_MOVE_RIGHT:
            return "[HERO MOVE] Hero moved Right. New coordinates of Hero: X: " + std::to_string(hero->get_hero_position(Singleton_Hero::x)) + "; Y: " + std::to_string(hero->get_hero_position(Singleton_Hero::y));
        case type::HERO_MOVE_UP:
            return "[HERO MOVE] Hero moved Up. New coordinates of Hero: X: " + std::to_string(hero->get_hero_position(Singleton_Hero::x)) + "; Y: " + std::to_string(hero->get_hero_position(Singleton_Hero::y));
        case type::HERO_MOVE_DOWN:
            return "[HERO MOVE] Hero moved Down. New coordinates of Hero: X: " + std::to_string(hero->get_hero_position(Singleton_Hero::x)) + "; Y: " + std::to_string(hero->get_hero_position(Singleton_Hero::y));
        default:
            return "[ERROR] Bad Argument for Hero Moves Log!";
    }
}
