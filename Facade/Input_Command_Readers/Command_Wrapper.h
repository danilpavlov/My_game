//
// Created by Даниил Павлов on 27.10.2022.
//

#ifndef MY_GAME_COMMAND_WRAPPER_H
#define MY_GAME_COMMAND_WRAPPER_H
#include "Request_Stream.h"
#include <fstream>

struct Control_Settings{
    std::ifstream enter_file;
    std::string enter_path = "binds/Enter.txt";

    std::ifstream log_stream_file;
    std::string log_stream_path = "binds/Logging_stream.txt";

    std::ifstream move_down_file;
    std::string move_down_path = "binds/Move_down.txt";

    std::ifstream move_up_file;
    std::string move_up_path = "binds/Move_up.txt";

    std::ifstream move_left_file;
    std::string move_left_path = "binds/Move_left.txt";

    std::ifstream move_right_file;
    std::string move_right_path = "binds/Move_right.txt";

    std::ifstream quit_file;
    std::string quit_path = "binds/Quit.txt";

    std::ifstream save_file;
    std::string save_path = "binds/Save.txt";

    std::ifstream load_file;
    std::string load_path = "binds/Load.txt";

    //// Inventory
    std::ifstream drop_consumable_file;
    std::string drop_consumable_path = "binds/Inventory_Binds/Drop_Consumable.txt";

    std::ifstream drop_equipment_file;
    std::string drop_equipment_path = "binds/Inventory_Binds/Drop_Equipment.txt";

    std::ifstream switch_consumable_file;
    std::string switch_consumable_path = "binds/Inventory_Binds/Switch_Consumable.txt";

    std::ifstream switch_equipment_file;
    std::string switch_equipment_path = "binds/Inventory_Binds/Switch_Equipment.txt";

    std::ifstream use_consumable_file;
    std::string use_consumable_path = "binds/Inventory_Binds/Use_Consumable.txt";

};

struct Commands{
    char up;
    char down;
    char left;
    char right;

    char quit;
    char enter;
    char set_log_stream;

    char save;
    char load;

    //// Inventory
    char drop_consumable;
    char drop_equipment;
    char switch_consumable;
    char switch_equipment;
    char use_consumable;
};

class Command_Wrapper {
public:
    enum command_type{MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, QUIT, ENTER, LOG_STREAM, SAVE, LOAD,
            DROP_CONSUMABLE, DROP_EQUIPMENT, SWITCH_CONSUMABLE, SWITCH_EQUIPMENT, USE_CONSUMABLE};

    Command_Wrapper();

    command_type read_user_symbol();

    void make_file_input();
    void make_standart_input();

    ~Command_Wrapper();
private:
    Command_Reader* reader;
    Control_Settings Settings;
    Commands commands;

};


#endif //MY_GAME_COMMAND_WRAPPER_H
