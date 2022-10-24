//
// Created by Даниил Павлов on 13.10.2022.
//

#include "Field_Message.h"

std::string Field_Message::get_message(int key) {
    switch (key) {
        case type::FIRST_LEVEL:
            return "[FIELD] Level One Started.";
        case type::SECOND_LEVEL:
            return "[EVENT] Level Two Started.";
        default:
            return "[ERROR] Bad Argument for Field Log!";
    }
}
