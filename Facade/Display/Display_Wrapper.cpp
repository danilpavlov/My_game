//
// Created by Даниил Павлов on 30.09.2022.
//

#include "Display_Wrapper.h"

Display_Wrapper::Display_Wrapper() {
    attribute_display = new Attribute_display;
    intro = new Intro;
    field_painter = new Field_Painter;
    request_file_control = new File_Control_Request_Display;
    inventory_display = new Inventory_Display;
}

void Display_Wrapper::print_devil(std::string tab) {
    char Devil_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '9','6', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    std::cout << std::endl << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⡼⠁⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡌⢳⡀⠀⠀⠀" << normal << std::endl;
    std::cout << tab <<Devil_color << "⠀⠀⠀⣸⠃⢰⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠈⣧⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⢠⡏⠀⢸⣇⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⢸⡇⠀⢸⡆⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⢸⡇⠀⠘⢿⠀⠀⣠⠴⠚⠉⠉⠁⠀⠉⠉⠛⠶⣄⡀⠀⣼⠃⠀⠀⡇⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⡆⠀⢸⡇⠀⠀⠈⠳⣾⣭⡙⠀⠀⠀⠀⠀⠀⠀⠀⠏⣭⣿⡾⠃⠀⠀⠀⡇⠀⢠" << normal << std::endl;
    std::cout << tab << Devil_color << "⡿⡄⠘⣇⠀⠀⢀⠀⠀⢹⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣏⠁⠀⡀⠀⠀⢸⠇⢀⢾" << normal << std::endl;
    std::cout << tab << Devil_color << "⢸⡙⢄⠹⣆⢄⠀⠁⢲⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣖⠊⠀⢠⣤⠏⢠⢊⡾" << normal << std::endl;
    std::cout << tab << Devil_color << "⠸⡝⣌⠳⣬⡟⠻⠛⠫⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠜⠛⠟⠺⣏⠔⢁⠊⡇" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⣧⠉⡦⣼⡀⠀⡱⠀⠀⠀⠀⠀⠀⡄⢀⠊⠀⠀⠀⠀⠀⠪⠀⢀⣿⠴⠁⢸⠁" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠸⣤⡀⠀⣿⢌⡀⠀⠀⠀⠀⠀⠀⠃⠀⡀⠀⠀⠀⠀⠀⢀⡡⣾⠁⠘⣠⠏⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠈⠻⣄⡏⠀⠈⢻⡖⠦⣄⡀⢠⠀⠀⡇⠀⣀⠤⢒⡿⠁⠀⢹⣄⡼⠁⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠸⡇⠀⠀⠀⠈⠓⠚⠋⠚⠀⠀⠓⠛⠓⠒⠁⠀⠀⠀⢀⡏⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠙⣦⠀⢤⣔⠒⠀⠀⢹⠀⠀⣌⠀⠀⠒⢒⢤⠄⣰⠟⠀⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠀⠘⣧⠈⠊⣧⡀⠀⡎⠁⠀⢸⡀⠀⣴⠣⠁⣰⡇⠀⠀⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠘⡜⠢⢼⣆⢠⡯⠔⢊⠏⠀⢀⣸⠀⠀⠀⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠀⠀⠀⠙⢶⡀⢫⠺⢤⢿⣮⡦⠒⡹⢀⡴⠋⠁⠀⠀⠀⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⢊⡳⢤⣈⣁⣤⡖⡱⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⡄⠉⠉⠉⠉⢀⡼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << normal << std::endl;
    std::cout << tab << Devil_color << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⣀⣀⣠⠟⠀⠀         ⠀⠀" << normal << std::endl;

}

void Display_Wrapper::print_victory(std::string tab) {
    system("clear");
    char victory_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '7', '8', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    in_game_intro();

    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << tab << victory_color << "   ▄█    █▄   ▄█   ▄████████     ███      ▄██████▄     ▄████████ ▄██   ▄   " << normal << std::endl;
    std::cout << tab << victory_color << "  ███    ███ ███  ███    ███ ▀█████████▄ ███    ███   ███    ███ ███   ██▄ " << normal << std::endl;
    std::cout << tab << victory_color << "  ███    ███ ███▌ ███    █▀     ▀███▀▀██ ███    ███   ███    ███ ███▄▄▄███ " << normal << std::endl;
    std::cout << tab << victory_color << "  ███    ███ ███▌ ███            ███   ▀ ███    ███  ▄███▄▄▄▄██▀ ▀▀▀▀▀▀███ " << normal << std::endl;
    std::cout << tab << victory_color << "  ███    ███ ███▌ ███            ███     ███    ███ ▀▀███▀▀▀▀▀   ▄██   ███ " << normal << std::endl;
    std::cout << tab << victory_color << "  ███    ███ ███  ███    █▄      ███     ███    ███ ▀███████████ ███   ███ " << normal << std::endl;
    std::cout << tab << victory_color << "  ███    ███ ███  ███    ███     ███     ███    ███   ███    ███ ███   ███ " << normal << std::endl;
    std::cout << tab << victory_color << "   ▀██████▀  █▀   ████████▀     ▄████▀    ▀██████▀    ███    ███  ▀█████▀  " << normal << std::endl;
    std::cout << tab << victory_color << "                                                      ███    ███           " << normal << std::endl;



    print_press_any_button(tab);
}

void Display_Wrapper::print_lose(bool quit, std::string tab) {
    system("clear");
    char death_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '2', '4', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    in_game_intro();

    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << tab << death_color << "            _______             ______  _________ _______  ______" << normal << std::endl;
    std::cout << tab << death_color << "  |\\     /|(  ___  )|\\     /|  (  __  \\ \\__   __/(  ____ \\(  __  \\" << normal << std::endl;
    std::cout << tab << death_color << "  ( \\   / )| (   ) || )   ( |  | (  \\  )   ) (   | (    \\/| (  \\  )" << normal << std::endl;
    std::cout << tab << death_color << "   \\ (_) / | |   | || |   | |  | |   ) |   | |   | (__    | |   ) |" << normal << std::endl;
    std::cout << tab << death_color << "    \\   /  | |   | || |   | |  | |   | |   | |   |  __)   | |   | |" << normal << std::endl;
    std::cout << tab << death_color << "     ) (   | |   | || |   | |  | |   ) |   | |   | (      | |   ) |" << normal << std::endl;
    std::cout << tab << death_color << "     | |   | (___) || (___) |  | (__/  )___) (___| (____/\\| (__/  )" << normal << std::endl;
    std::cout << tab << death_color << "     \\_/   (_______)(_______)  (______/ \\_______/(_______/(______/" << normal << std::endl;
    std::cout << tab << death_color << "    \\   /  | |   | || |   | |  | |   | |   | |   |  __)   | |   | |" << normal << std::endl;

    quit = true;

    print_press_any_button(tab);
}

void Display_Wrapper::show_intro() {
    system("clear");

    this->intro->start_intro();

    system("clear");
}

void Display_Wrapper::in_game_intro() {
    this->intro->cout_intro();
}

void Display_Wrapper::draw(Field* field, Console_Logger* console_logger, int level, Inventory* inventory) {
    field_painter->draw_field(field, console_logger, level);
    attribute_display->show_hp_display();
    attribute_display->show_xp_display();
    inventory_display->draw_inventory(inventory);
}

Display_Wrapper::~Display_Wrapper() {
    delete field_painter;
    delete intro;
    delete attribute_display;
}

void Display_Wrapper::set_logging(int new_logging_state) {
    field_painter->set_logging_state(new_logging_state);
}


void Display_Wrapper::show_request_file_control() {
    request_file_control->print_request();
}

void Display_Wrapper::static_show_request_file_control() {
    request_file_control->static_request_printed();
}

void Display_Wrapper::print_press_any_button(std::string tab) {
    char press_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '6', '6', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
    usleep(6000000);

    tab = "\t\t\t";
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << tab << press_color << "   _______  ______    _______  _______  _______    _______  __    _  __   __    _______  __   __  _______  _______  _______  __    _ " << normal << std::endl;
    std::cout << tab << press_color << "  |       ||    _ |  |       ||       ||       |  |   _   ||  |  | ||  | |  |  |  _    ||  | |  ||       ||       ||       ||  |  | |" << normal << std::endl;
    std::cout << tab << press_color << "  |    _  ||   | ||  |    ___||  _____||  _____|  |  |_|  ||   |_| ||  |_|  |  | |_|   ||  | |  ||_     _||_     _||   _   ||   |_| |" << normal << std::endl;
    std::cout << tab << press_color << "  |   |_| ||   |_||_ |   |___ | |_____ | |_____   |       ||       ||       |  |       ||  |_|  |  |   |    |   |  |  | |  ||       |" << normal << std::endl;
    std::cout << tab << press_color << "  |    ___||    __  ||    ___||_____  ||_____  |  |       ||  _    ||_     _|  |  _   | |       |  |   |    |   |  |  |_|  ||  _    |" << normal << std::endl;
    std::cout << tab << press_color << "  |   |    |   |  | ||   |___  _____| | _____| |  |   _   || | |   |  |   |    | |_|   ||       |  |   |    |   |  |       || | |   |" << normal << std::endl;
    std::cout << tab << press_color << "  |___|    |___|  |_||_______||_______||_______|  |__| |__||_|  |__|  |___|    |_______||_______|  |___|    |___|  |_______||_|  |__|" << normal << std::endl;

}

void Display_Wrapper::draw_field_only(Field *field, int level) {
    std::string tab = "\t";

    std::string facet, hero_icon, wall, empty_cell, heal, xp, teleport, enemy, win_cell, refresher, pumpkin, ghost, drug, heal_potion, slippers, socks;

    switch(level){
        case 0:
            facet = "🌲";
            hero_icon = "🧛🏻";
            wall = "🪨";
            empty_cell = "🪹";
            heal = "🫀";
            xp = "🩸";
            teleport = "💨";
            enemy = "🧙";
            win_cell = "🍺";
            refresher = "🧞";
            ghost = "👻";
            pumpkin = "🎃";
            drug = "🍄";
            heal_potion = "🍕";
            slippers = "🩴";
            socks = "🧦";
            break;
        case 1:
            facet = "🥀";
            hero_icon = "🧛🏻";
            wall = "🪦";
            empty_cell = "🍁";
            heal = "🫀";
            xp = "🩸";
            teleport = "💨";
            enemy = "🧟";
            win_cell = "🍺";
            refresher = "🧞";
            ghost = "👻";
            pumpkin = "🎃";
            drug = "🍄";
            heal_potion = "🍕";
            slippers = "🩴";
            socks = "🧦";
            break;
        default:
            break;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << tab;
    for(int i = 0; i < field->get_x()+2; i++){
        std::cout << facet;
    }
    std::cout << std::endl;

    for (int i = 0; i < field->get_y(); i++){

        std::cout << tab;
        std::cout << facet;
        for (int j = 0; j < field->get_x(); j++){
            switch(field->get_field()[i][j].get_state()){
                case Cell::HERO:
                    std::cout << hero_icon;
                    break;
                case Cell::EMPTY:
                    std::cout << empty_cell;
                    break;
                case Cell::WALL:
                    std::cout << wall;
                    break;
                case Cell::HEAL:
                    std::cout << heal;
                    break;
                case Cell::XP:
                    std::cout << xp;
                    break;
                case Cell::ENEMY:
                    std::cout << enemy;
                    break;
                case Cell::TELEPORT:
                    std::cout << teleport;
                    break;
                case Cell::WIN:
                    std::cout << win_cell;
                    break;
                case Cell::REFRESHER_OF_EVENTS:
                    std::cout << refresher;
                    break;
                case Cell::PUMPKIN_HEAD:
                    std::cout << pumpkin;
                    break;
                case Cell::GHOST_HEAD:
                    std::cout << ghost;
                    break;
                case Cell::DRUG:
                    std::cout << drug;
                    break;
                case Cell::HEAL_POTION:
                    std::cout << heal_potion;
                    break;
                case Cell::SLIPPERS:
                    std::cout << slippers;
                    break;
                case Cell::SOCKS:
                    std::cout << socks;
                    break;
                default:
                    break;
            }
        }
        std::cout << facet << std::endl;
    }
    std::cout << tab;
    for(int i = 0; i < field->get_x()+2; i++){
        std::cout << facet;
    }
    std::cout << std::endl;

}

void Display_Wrapper::show_alucard() {
    request_file_control->draw_gats();
}

void Display_Wrapper::print_cant_load() {
    char color[] = { 0x1b, '[', '3', '8',';','5',';','1', '2', '4', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    std::cout<<color<<"                    _     _                 _                                                                          " << normal<<std::endl;
    std::cout<<color<<"     ___ __ _ _ __ | |_  | | ___   __ _  __| |                                                                         " << normal<<std::endl;
    std::cout<<color<<"    / __/ _` | '_ \\| __| | |/ _ \\ / _` |/ _` |                                                                         " << normal<<std::endl;
    std::cout<<color<<"   | (_| (_| | | | | |_  | | (_) | (_| | (_| |                                                                         " << normal<<std::endl;
    std::cout<<color<<"    \\___\\__,_|_| |_|\\__| |_|\\___/_\\__,_|\\__,_|                                _                                      _ " << normal<<std::endl;
    std::cout<<color<<"    ___  ___  _ __ ___   ___   / _(_) ___| |___  __      _____ _ __ ___    __| | __ _ _ __ ___   __ _  __ _  ___  __| |" << normal<<std::endl;
    std::cout<<color<<"   / __|/ _ \\| '_ ` _ \\ / _ \\ | |_| |/ _ \\ / __| \\ \\ /\\ / / _ \\ '__/ _ \\  / _` |/ _` | '_ ` _ \\ / _` |/ _` |/ _ \\/ _` |" << normal<<std::endl;
    std::cout<<color<<"   \\__ \\ (_) | | | | | |  __/ |  _| |  __/ \\__ \\  \\ V  V /  __/ | |  __/ | (_| | (_| | | | | | | (_| | (_| |  __/ (_| |" << normal<<std::endl;
    std::cout<<color<<"   |___/\\___/|_| |_| |_|\\___| |_| |_|\\___|_|___/   \\_/\\_/ \\___|_|  \\___|  \\__,_|\\__,_|_| |_| |_|\\__,_|\\__, |\\___|\\__,_|" << normal<<std::endl;
    std::cout<<color<<"                                                                                                      |___/            " << normal<<std::endl;
}

