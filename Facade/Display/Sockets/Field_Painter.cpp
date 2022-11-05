//
// Created by Даниил Павлов on 28.09.2022.
//

#include "Field_Painter.h"
#define TAB_PUSH std::cout << "  ";
#define MARIO_TAB ""
#define LV_LOG_TAB "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"

void Field_Painter::draw_field(Field *main_field, Console_Logger* console_logger, int level) {
//    Данный метод создан для отрисовки всего, включая границы, игрового поля и отдельных игровых аспектов (Например: атрибуты героя)
    std::string facet, hero_icon, wall, empty_cell, heal, xp, teleport, enemy, win_cell, refresher, pumpkin, ghost, drug, heal_potion, slippers, socks;
    std::string fire, fog, freeze, move_blocker;

    Singleton_Hero* hero = Singleton_Hero::getInstance();

    switch(level){
        case 0:
            facet = "🌲";
            hero_icon = hero->get_hero_model();
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

            fire = "🔥";
            fog = "💭";
            freeze = "💎";
            move_blocker = "🔒";
            break;
        case 1:
            facet = "🥀";
            hero_icon = hero->get_hero_model();
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

            fire = "🔥";
            fog = "💭";
            freeze = "💎";
            move_blocker = "🔒";
            break;
        default:
            break;
    }

    logs = console_logger->get_logs();

    std::reverse(logs.begin(), logs.end());

    std::vector< std::vector<Cell> > field_2d = main_field->get_field();
    int x = main_field->get_x();
    int y = main_field->get_y();

    char Hero_color[] = { 0x1b, '[', '3', '8',';','5',';','1','9', '0', 'm',0 };  // ЦВЕТ ГЕРОЯ
    char Walls_color[] = { 0x1b, '[', '3', '8',';','5',';','8', '8', 'm',0 };  // ЦВЕТ СТЕН (ГРАНИЦ)
    char Walls_color_two[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '6', 'm',0 };  // ЦВЕТ СТЕНЫ ВНУТРИ ПОЛЯ
    char Ground_color[] = { 0x1b, '[', '3', '8',';','5',';','9', '5', 'm',0 };   // ЦВЕТ ЗЕМЛИ
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    char lv_table[] = { 0x1b, '[', '3', '8',';','5',';','2','0', '8', 'm',0 };   // ЦВЕТ СЛОВА LEVEL

    char lv_table_number[] = { 0x1b, '[', '3', '8',';','5',';','9', '8', 'm',0 };   // ЦВЕТ САМОГО УРОВНЯ

    std::cout << std::endl << std::endl;

    TAB_PUSH
    for (int i = 0; i < x+2; i++){      // Отрисовка верхней границы
        if (!hero->did_hero_eat_shroom()){
        std::cout << Walls_color << facet << normal;
        }else if (hero->did_hero_eat_shroom()){
            std::cout << Walls_color << "🌈" << normal;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < y; i++){        // Отрисовка всего поля
        TAB_PUSH

        if (!hero->did_hero_eat_shroom()){  // Отрисовка левой границы
            std::cout << Walls_color << facet << normal;
        }else if (hero->did_hero_eat_shroom()){
            std::cout << Walls_color << "🌈" << normal;
        }
        for (int j = 0; j < x; j++){
            if (field_2d[i][j].get_weather() != Cell::FOG) {

                if (field_2d[i][j].get_state() == Cell::HERO) {
                    std::cout << Hero_color << hero_icon << normal;
                } else if (field_2d[i][j].get_state() == Cell::WALL) {
                    if (!hero->did_hero_eat_shroom()) {
                        std::cout << Walls_color_two << wall << normal;
                    } else if (hero->did_hero_eat_shroom()) {
                        std::cout << Walls_color_two << "🌞" << normal;
                    }
                } else if (field_2d[i][j].get_state() == Cell::EMPTY) {

                    if (field_2d[i][j].get_weather() == Cell::NONE) {
                        if (!hero->did_hero_eat_shroom()) {
                            std::cout << Ground_color << empty_cell << normal;
                        } else if (hero->did_hero_eat_shroom()) {
                            std::cout << Ground_color << "🍀" << normal;
                        }
                    }else if (field_2d[i][j].get_weather() == Cell::FREEZE){
                        std::cout << freeze << normal;
                    }else if (field_2d[i][j].get_weather() == Cell::FIRE){
                        std::cout << fire << normal;
                    }else if (field_2d[i][j].get_weather() == Cell::MOVE_BLOCKER){
                        std::cout << move_blocker << normal;
                    }
                } else if (field_2d[i][j].get_state() == Cell::HEAL) {
                    std::cout << Walls_color << heal << normal;
                } else if (field_2d[i][j].get_state() == Cell::XP) {
                    std::cout << Ground_color << xp << normal;
                } else if (field_2d[i][j].get_state() == Cell::TELEPORT) {
                    std::cout << Ground_color << teleport << normal;
                } else if (field_2d[i][j].get_state() == Cell::ENEMY) {
                    std::cout << Ground_color << enemy << normal;
                } else if (field_2d[i][j].get_state() == Cell::WIN) {
                    std::cout << Ground_color << win_cell << normal;
                } else if (field_2d[i][j].get_state() == Cell::REFRESHER_OF_EVENTS) {
                    std::cout << Ground_color << refresher << normal;
                } else if (field_2d[i][j].get_state() == Cell::GHOST_HEAD) {
                    std::cout << Ground_color << ghost << normal;
                } else if (field_2d[i][j].get_state() == Cell::PUMPKIN_HEAD) {
                    std::cout << Ground_color << pumpkin << normal;
                } else if (field_2d[i][j].get_state() == Cell::DRUG) {
                    std::cout << Ground_color << drug << normal;
                } else if (field_2d[i][j].get_state() == Cell::HEAL_POTION) {
                    std::cout << Ground_color << heal_potion << normal;
                } else if (field_2d[i][j].get_state() == Cell::SLIPPERS) {
                    std::cout << Ground_color << slippers << normal;
                } else if (field_2d[i][j].get_state() == Cell::SOCKS) {
                    std::cout << Ground_color << socks << normal;
                }

            }else{
                std::cout << fog << normal;
            }
        }

        std::string right_facet;
        if (!hero->did_hero_eat_shroom()){
            right_facet = facet;
        }else if (hero->did_hero_eat_shroom()){
            right_facet = "🌈";
        }

        char mario_red[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '0', 'm',0 };
        char mario_brown[] = { 0x1b, '[', '3', '8',';','5',';','1','0', '0', 'm',0 };
        char mario_pink[] = { 0x1b, '[', '3', '8',';','5',';','1','8', '0', 'm',0 };
        char mario_yellow[] = { 0x1b, '[', '3', '8',';','5',';','1','8', '5', 'm',0 };
        char mario_black[] = { 0x1b, '[', '3', '8',';','5',';','0', 'm',0 };

        char logs_logo_color[] = { 0x1b, '[', '3', '8',';','5',';','2', '0', '2', 'm',0 };
        char logs_color[] = { 0x1b, '[', '3', '8',';','5',';', '9', '2', 'm',0 };
        if (y == 24){
            switch (i){
                case 0:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"██████████████████████████"<< mario_pink<<"██████"<< normal;

                    std::cout << std::endl;
                    break;
                case 1:
                    std::cout << Walls_color << right_facet + MARIO_TAB  <<mario_black << "██████████"<< mario_red<<"██████████"<< mario_black<<"██████"<< mario_pink<<"██████"<< normal;

                    std::cout << std::endl;
                    break;
                case 2:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"██████████"<< mario_red <<"██████████████████"<< mario_pink <<"████"<< normal;

                    std::cout << std::endl;
                    break;
                case 3:
                    std::cout << Walls_color << right_facet + MARIO_TAB   <<mario_black <<"██████████"<< mario_brown<<"██████"<< mario_pink<<"████"<< mario_brown <<"██"<< mario_pink <<"██"<< mario_black <<"██"<< mario_brown <<"██████"<< normal;

                    std::cout << std::endl;
                    break;
                case 4:
                    std::cout << Walls_color << right_facet + MARIO_TAB  << mario_black << "████████"<< mario_brown<<"██"<<mario_pink <<"██"<< mario_brown<<"██"<< mario_pink<<"██████"<< mario_brown<<"██"<< mario_pink<<"██████"<< mario_brown <<"████"<< normal;

                    std::cout << std::endl;
                    break;
                case 5:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"████████"<< mario_brown<<"██"<< mario_pink<<"██"<< mario_brown <<"████"<< mario_pink<<"██████"<< mario_brown <<"██"<< mario_pink <<"██████"<< mario_brown<<"██"<< normal;

                    std::cout << std::endl;
                    break;
                case 6:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"████████"<< mario_brown <<"████"<< mario_pink <<"████████"<< mario_brown <<"██████████"<< mario_black <<"██"<< normal;

                    std::cout << std::endl;
                    break;
                case 7:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"████████████"<< mario_pink <<"██████████████"<<  mario_brown<<"██"<< mario_black<<"████"<< normal;  // neck

                    std::cout << std::endl;
                    break;
                case 8:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"████"<<mario_brown <<"██████████"<< mario_red<<"██"<< mario_brown<<"██████"<< mario_red<<"██"<< mario_brown<<"██"<< mario_black<<"██████"<< normal;

                    std::cout << std::endl;
                    break;
                case 9:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"██"<< mario_brown<<"██████████████"<< mario_red<<"██"<< mario_brown<<"██████"<<mario_red <<"██"<< mario_black <<"████"<< mario_brown<<"██"<< normal;

                    std::cout << std::endl;
                    break;
                case 10:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_pink<<"████"<< mario_brown<<"████████████"<< mario_red<<"██████████"<< mario_black <<"████"<< mario_brown <<"██"<< normal;

                    std::cout << std::endl;
                    break;
                case 11:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_pink<<"██████"<< mario_black<<"████"<< mario_red<<"██"<< mario_brown<<"██"<< mario_red<<"██████"<< mario_yellow<<"██"<<mario_red <<"██"<< mario_yellow <<"██"<< mario_red <<"██"<< mario_brown <<"████"<< normal;

                    std::cout << std::endl;
                    break;
                case 12:
                    std::cout << Walls_color << right_facet + MARIO_TAB   << mario_black<<"██"<< mario_pink<<"██"<< mario_black<<"██"<< mario_brown<<"██"<< mario_black<<"██"<<mario_red <<"██████████████████"<<mario_brown <<"████"<< normal;

                    std::cout << std::endl;
                    break;
                case 13:
                    std::cout << Walls_color << right_facet + MARIO_TAB  <<mario_black << "████"<< mario_brown<<"██████"<<mario_red <<"██████████████████"<< mario_brown<<"████"<< normal;

                    std::cout << std::endl;
                    break;
                case 14:
                    std::cout << Walls_color << right_facet + MARIO_TAB  << mario_black<<"██"<< mario_brown<<"██"<< mario_black <<"████"<< mario_red<<"████████"<< mario_black <<"████████████████"<< normal; // СИМВОЛ ПРАВОЙ ГРАНИЦЫ

                    std::cout << std::endl;
                    break;
                case 15:
                    std::cout << Walls_color << right_facet + MARIO_TAB  << mario_black<<"██"<< mario_brown<<"██"<< mario_black <<"████"<< mario_red<<"████████"<< mario_black <<"████████████████"<< normal; // СИМВОЛ ПРАВОЙ ГРАНИЦЫ
                    std::cout << std::endl;
                    break;
                case 16:
                    std::cout << right_facet << logs_logo_color <<"Quick Logs:";
                    std::cout << std::endl;
                    break;
                case 17:
                    std::cout << right_facet;
                    if (logs.size() > 0){
                        std::cout << logs_color << logs[0];
                    }
                    std::cout << std::endl;
                    break;
                case 18:
                    std::cout << right_facet;
                    if (logs.size() > 1){
                        std::cout << logs_color << logs[1];
                    }
                    std::cout << std::endl;
                    break;
                case 19:
                    std::cout << right_facet;
                    if (logs.size() > 2){
                        std::cout << logs_color << logs[2];
                    }
                    std::cout << std::endl;
                    break;
                case 20:
                    std::cout << right_facet;
                    if (logs.size() > 3){
                        std::cout << logs_color << logs[3];
                    }
                    std::cout << std::endl;
                    break;
                case 21:
                    std::cout << right_facet;
                    if (logs.size() > 4){
                        std::cout << logs_color << logs[4];
                    }
                    std::cout << std::endl;
                    break;
                case 22:
                    std::cout << right_facet;
                    if (logs.size() > 5){
                        std::cout << logs_color << logs[5];
                    }
                    std::cout << logs_color << std::endl;
                    break;
                case 23:
                    std::cout << right_facet;
                    if (logs.size() > 6){
                        std::cout << logs_color << logs[6];
                    }
                    std::cout << std::endl;
                    break;
                default:
                    std::cout << Walls_color << right_facet << normal << std::endl;
                    break;
            }
        }else{
            std::cout << Walls_color << right_facet << normal << std::endl;
        }
    }

    TAB_PUSH
    for (int i = 0; i < x+2; i++){  // Отрисовка нижней границы

        if (!hero->did_hero_eat_shroom()){
            std::cout << Walls_color << facet << normal;
        }else if (hero->did_hero_eat_shroom()){
            std::cout << Walls_color << "🌈" << normal;
        }
    }

    std::cout << std::endl << std::endl;

    TAB_PUSH
    std::cout <<  lv_table <<  "INVENTORY WEIGHT: " << lv_table_number <<hero->get_weight() << " / " << MAX_WEIGHT <<std::endl;


    TAB_PUSH
    std::cout << lv_table << "Level: "<< lv_table_number    // ОТРИСОВКА УРОВНЯ ГЕРОЯ
              << hero->get_hero_attribute(Singleton_Hero::level) <<normal;

    char logging_color[] = { 0x1b, '[', '3', '8',';','5',';','9','4', 'm',0 };   // Цвет надписи Логов
    char active_logging_color[] = { 0x1b, '[', '3', '8',';','5',';','1','6', '0', 'm',0 };   // Логирование Активно
    char disabled_logging_color[] = { 0x1b, '[', '3', '8',';','5',';','2','3', '7', 'm',0 };   // Логирование Выключено
    switch (logging_state){
        case 0:
            std::cout << logging_color <<LV_LOG_TAB "Logging in:  " << disabled_logging_color <<"Console  " << active_logging_color << "File" << normal << std::endl;
            break;
        case 1:
            std::cout << logging_color <<LV_LOG_TAB "Logging in:  " << active_logging_color <<"Console  " << disabled_logging_color << "File" << normal << std::endl;
            break;
        case 2:
            std::cout << logging_color <<LV_LOG_TAB "Logging in:  " << active_logging_color <<"Console  " << active_logging_color << "File" << normal << std::endl;
            break;
        case 3:
            std::cout << logging_color <<LV_LOG_TAB "Logging in:  " << disabled_logging_color <<"Console  " << disabled_logging_color << "File" << normal << std::endl;
            break;
        default:
            break;
    }



}

Field_Painter::Field_Painter() {
    logging_state = 0;
}

void Field_Painter::set_logging_state(int new_state) {
    logging_state = new_state;
}


