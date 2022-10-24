//
// Created by Даниил Павлов on 25.09.2022.
//

#include "GUI_Display.h"
#define TAB "\t\t\t\t\t\t\t"

GUI_Display::GUI_Display() {

    new_game_string.push_back("   _ __   _____      __   __ _  __ _ _ __ ___   ___");
    new_game_string.push_back("  | '_ \\ / _ \\ \\ /\\ / /  / _` |/ _` | '_ ` _ \\ / _ \\");
    new_game_string.push_back("  | | | |  __/\\ V  V /  | (_| | (_| | | | | | |  __/");
    new_game_string.push_back("  |_| |_|\\___| \\_/\\_/    \\__, |\\__,_|_| |_| |_|\\___|");
    new_game_string.push_back("                          __/ |");
    new_game_string.push_back("                         |___/");

    load_game_string.push_back("   _                 _");
    load_game_string.push_back("  | |               | |");
    load_game_string.push_back("  | | ___   __ _  __| |");
    load_game_string.push_back("  | |/ _ \\ / _` |/ _` | ");
    load_game_string.push_back("  | | (_) | (_| | (_| |");
    load_game_string.push_back("  |_|\\___/ \\__,_|\\__,_|");

    quit_string.push_back("               _ _");
    quit_string.push_back("              (_) |");
    quit_string.push_back("    __ _ _   _ _| |_");
    quit_string.push_back("   / _` | | | | | __|");
    quit_string.push_back("  | (_| | |_| | | |_");
    quit_string.push_back("   \\__, |\\__,_|_|\\__|");
    quit_string.push_back("      | |");
    quit_string.push_back("      |_|");

    yes_string.push_back("   _   _  ___  ___ ");
    yes_string.push_back("  | | | |/ _ \\/ __|");
    yes_string.push_back("  | |_| |  __/\\__ \\");
    yes_string.push_back("   \\__, |\\___||___/");
    yes_string.push_back("   |___/           ");

    no_string.push_back("   _ __   ___  ");
    no_string.push_back("  | '_ \\ / _ \\ ");
    no_string.push_back("  | | | | (_) |");
    no_string.push_back("  |_| |_|\\___/ ");

    first_level_string.push_back("     ___ _          _       __                _");
    first_level_string.push_back("    / __(_)_ __ ___| |_    / /  _____   _____| |");
    first_level_string.push_back("   / _\\ | | '__/ __| __|  / /  / _ \\ \\ / / _ \\ |");
    first_level_string.push_back("  / /   | | |  \\__ \\ |_  / /__|  __/\\ V /  __/ |");
    first_level_string.push_back("  \\/    |_|_|  |___/\\__| \\____/\\___| \\_/ \\___|_|");
    first_level_string.push_back("");

    second_level_string.push_back("   __                          _     __                _");
    second_level_string.push_back("  / _\\ ___  ___ ___  _ __   __| |   / /  _____   _____| |");
    second_level_string.push_back("  \\ \\ / _ \\/ __/ _ \\| '_ \\ / _` |  / /  / _ \\ \\ / / _ \\ |");
    second_level_string.push_back("  _\\ \\  __/ (_| (_) | | | | (_| | / /__|  __/\\ V /  __/ |");
    second_level_string.push_back("  \\__/\\___|\\___\\___/|_| |_|\\__,_| \\____/\\___| \\_/ \\___|_|");
    second_level_string.push_back("");

    back_string.push_back("   _                _    ");
    back_string.push_back("  | |__   __ _  ___| | __");
    back_string.push_back("  | '_ \\ / _` |/ __| |/ /");
    back_string.push_back("  | |_) | (_| | (__|   < ");
    back_string.push_back("  |_.__/ \\__,_|\\___|_|\\_\\");



}

GUI_Display::~GUI_Display() {
    new_game_string.clear();
    load_game_string.clear();
    quit_string.clear();
    no_string.clear();
    yes_string.clear();
}

void GUI_Display::print_main_menu(GUI_Display::type string_type, char* color) {
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    assert(string_type == GUI_Display::NEW_GAME || string_type == GUI_Display::LOAD_GAME || string_type == GUI_Display::QUIT);

    switch (string_type) {
        case (type::NEW_GAME):
            for (int i = 0; i < new_game_string.size(); i++){
                std::cout << TAB << color << new_game_string[i] << normal <<std::endl;
            }
            break;
        case (type::LOAD_GAME):
            for (int i = 0; i < load_game_string.size(); i++){
                std::cout << TAB << color<< load_game_string[i] << normal << std::endl;
            }
            break;
        case (type::QUIT):
            for (int i = 0; i < quit_string.size(); i++){
                std::cout << TAB << color << quit_string[i] << normal <<std::endl;
            }
            break;
        default:
            break;
    }
}

void GUI_Display::print_file_control_request(GUI_Display::type string_type, char* color) {
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    assert(string_type == GUI_Display::YES || string_type == GUI_Display::NO);

    switch(string_type){
        case (GUI_Display::YES):
            for (int i = 0; i < yes_string.size(); i++){
                std::cout << TAB << TAB << color<< yes_string[i] << normal << std::endl;
            }
            break;
        case (GUI_Display::NO):
            for (int i = 0; i < no_string.size(); i++){
                std::cout << TAB << TAB << color<< no_string[i] << normal << std::endl;
            }
            break;
        default:
            break;
    }
}



void GUI_Display::print_level_choice(type string_type, char* color) {
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    assert(string_type == GUI_Display::BACK || string_type == GUI_Display::FIRST_LEVEL || string_type == GUI_Display::SECOND_LEVEL);

    switch(string_type){
        case (GUI_Display::FIRST_LEVEL):
            for (int i = 0; i < first_level_string.size(); i++){
                std::cout << TAB << color<< first_level_string[i] << normal << std::endl;
            }
            break;
        case (GUI_Display::SECOND_LEVEL):
            for (int i = 0; i < second_level_string.size(); i++){
                std::cout << TAB  << color<< second_level_string[i] << normal << std::endl;
            }
            break;
        case (GUI_Display::BACK):
            for (int i = 0; i < back_string.size(); i++){
                std::cout << TAB << color<< back_string[i] << normal << std::endl;
            }
            break;
        default:
            break;
    }

}




