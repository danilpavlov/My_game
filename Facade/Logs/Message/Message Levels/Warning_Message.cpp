//
// Created by Даниил Павлов on 13.10.2022.
//

#include "Warning_Message.h"

std::string Warning_Message::get_message(int key) {
    switch (key) {
        case type::HERO_CANT_MOVE_ON_ROCK:
            return "[WARNING] Hero Can't Move On Walls!";
        case type::HERO_CANT_WIN_YET:
            return "[WARNING] Hero Can't Win Yet!";
        case type::TOO_MUCH_HP:
            return "[WARNING] Hero Got Too Much HP!";
        default:
            return "[ERROR] Bad Argument for Warning Log!";
    }
}
