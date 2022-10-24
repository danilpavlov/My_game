//
// Created by Даниил Павлов on 16.10.2022.
//

#include "System_Messages.h"

std::string System_Messages::get_message(int key) {
    switch(key){
        case type::JOY_DIVISION:
            return "[SYSTEM] Joy Division - Disorder is playing";
        case type::HAVE_A_NICE_LIFE:
            return "[SYSTEM] Have A Nice Life - Bloodhail is playing";
        case type::THE_SMITHS:
            return "[SYSTEM] The Smiths - This Charming Man is playing";
        case type::ECCO2K:
            return "[SYSTEM] Ecco2k - In The Flash is playing";
        case type::FILE_CONTROL:
            return "[SYSTEM] **File Control**";
        case type::STANDART_CONTROL:
            return "[SYSTEM] **Standart Control**";


    }
}
