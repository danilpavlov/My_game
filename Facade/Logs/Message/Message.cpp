//
// Created by Даниил Павлов on 30.09.2022.
//

#include "Message.h"

#include <utility>


//std::string Message::get_message(Message::log_type logType, Message::message_type messageType) {
//    switch (logType){
//        case log_type::EVENT:
//            switch (messageType){
//                case message_type::HEAL:
//                    return "[EVENT] Hero was healed by Healing.";
//                case message_type::XP:
//                    return "[EVENT] Hero got plus one XP.";
//                case message_type::ENEMY:
//                    return "[EVENT] Hero was hit by Enemy.";
//                case message_type::TELEPORT:
//                    return "[EVENT] Hero was Teleported.";
//                case message_type::WIN:
//                    return "[EVENT] Hero moved to the victory cell.";
//                case message_type::REFRESHER:
//                    return "[EVENT] Hero ate some magic shroom... new objects were spawned at the field.";
//                case message_type::CURE:
//                    return "[EVENT] Hero was Cured by Blood.";
//                default:
//                    break;
//            }
//            break;
//        case log_type::HERO:
//            switch (messageType){
//                case message_type::HERO_DEAD:
//                    return "[HERO] Hero was healed by Heart.";
//                case message_type::HERO_LEVEL_UP:
//                    return "[HERO] Hero reached New Level.";
//                case message_type::HERO_WIN:
//                    return "[HERO] Hero wins.";
//                default:
//                    break;
//            }
//            break;
//
//        case log_type::WARNING:
//            switch (messageType){
//                case message_type::HERO_CANT_MOVE_ON_ROCK:
//                    return "[WARNING] Hero Can't Move on the Walls.";
//                case message_type::HERO_CANT_WIN_YET:
//                    return "[WARNING] Hero Can't Win Yet.";
//                case message_type::TOO_MUCH_HP:
//                    return "[WARNING] Hero has max health points.";
//                default:
//                    break;
//            }
//            break;
//        case log_type::FIELD:
//            switch (messageType){
//                case message_type::NEW_FIELD_GENERATED:
//                    return "[FIELD] New Field was created.";
//                default:
//                    break;
//            }
//            break;
//        case log_type::GUI_Display:
//            switch(messageType){
//                case message_type::NEW_GAME:
//                        return "[GLOBAL] New game is starting...";
//                case message_type::LOADING:
//                    return "[GLOBAL] Moved to Loadings...";
//                case message_type::MAIN_MENU:
//                    return "[GLOBAL] GUI_Display Started.";
//                case message_type::INTRO:
//                    return "[GLOBAL] Intro was shown.";
//                case message_type::QUIT:
//                    return "[GLOBAL] Bye!";
//                default:
//                    break;
//            }
//        case log_type::MUSIC:
//            switch(messageType){
//                case message_type::JOY_DIVISION:
//                    return "[SYSTEM] Joy Division - Disorder is playing...";
//                case message_type::HAVE_A_NICE_LIFE:
//                    return "[SYSTEM] Have A Nice Life - Bloodhail is playing...";
//                case message_type::SLINT:
//                    return "[SYSTEM] Slint - Nosferatu Man is playing...";
//                case message_type::NO_MUSIC:
//                    return "[SYSTEM] Music was switched off.";
//                default:
//                    break;
//            }
//
//        default:
//            return "[ERROR] Bad Argument!";
//
//    }
//}
