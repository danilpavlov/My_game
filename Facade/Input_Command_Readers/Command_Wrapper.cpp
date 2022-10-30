//
// Created by Даниил Павлов on 27.10.2022.
//

#include "Command_Wrapper.h"

Command_Wrapper::Command_Wrapper() {
    Settings.enter_file.open(Settings.enter_path);
    Settings.log_stream_file.open(Settings.log_stream_path);

    Settings.move_down_file.open(Settings.move_down_path);
    Settings.move_left_file.open(Settings.move_left_path);
    Settings.move_right_file.open(Settings.move_right_path);
    Settings.move_up_file.open(Settings.move_up_path);

    Settings.quit_file.open(Settings.quit_path);
    Settings.save_file.open(Settings.save_path);



    commands.up = Settings.move_up_file.get();
    commands.right = Settings.move_right_file.get();
    commands.down = Settings.move_down_file.get();
    commands.left = Settings.move_left_file.get();

    commands.save = Settings.save_file.get();
    commands.quit = Settings.quit_file.get();
    commands.enter = Settings.enter_file.get();
    commands.set_log_stream = Settings.log_stream_file.get();

    //// Inventory
    Settings.drop_consumable_file.open(Settings.drop_consumable_path);
    Settings.drop_equipment_file.open(Settings.drop_equipment_path);

    Settings.switch_consumable_file.open(Settings.switch_consumable_path);
    Settings.switch_equipment_file.open(Settings.switch_equipment_path);

    Settings.use_consumable_file.open(Settings.use_consumable_path);


    commands.drop_consumable = Settings.drop_consumable_file.get();
    commands.drop_equipment = Settings.drop_equipment_file.get();
    commands.switch_consumable = Settings.switch_consumable_file.get();
    commands.switch_equipment = Settings.switch_equipment_file.get();
    commands.use_consumable = Settings.use_consumable_file.get();
}

void Command_Wrapper::make_file_input() {
    reader = new File_Stream_Reader;
}

void Command_Wrapper::make_standart_input() {
    reader = new Input_Stream_Reader;
}

Command_Wrapper::~Command_Wrapper() {
    Settings.enter_file.close();
    Settings.log_stream_file.close();

    Settings.move_down_file.close();
    Settings.move_left_file.close();
    Settings.move_right_file.close();
    Settings.move_up_file.close();

    Settings.quit_file.close();
    Settings.save_file.close();

    ////Inventory
    Settings.drop_consumable_file.close();
    Settings.drop_equipment_file.close();

    Settings.switch_consumable_file.close();
    Settings.switch_equipment_file.close();

    Settings.use_consumable_file.close();
}

Command_Wrapper::command_type Command_Wrapper::read_user_symbol() {
    char user_symbol = reader->get_character();

    if (user_symbol == commands.set_log_stream){
        return Command_Wrapper::LOG_STREAM;

    }else if (user_symbol == commands.enter){
        return Command_Wrapper::ENTER;

    }else if (user_symbol == commands.quit){
        return Command_Wrapper::QUIT;

    }else if (user_symbol == commands.save){
        return Command_Wrapper::SAVE;

    }else if (user_symbol == commands.up){
        return Command_Wrapper::MOVE_UP;

    }else if (user_symbol == commands.left){
        return Command_Wrapper::MOVE_LEFT;

    }else if (user_symbol == commands.right){
        return Command_Wrapper::MOVE_RIGHT;

    }else if (user_symbol == commands.down){
        return Command_Wrapper::MOVE_DOWN;

    }else if (user_symbol == commands.switch_equipment){
        return Command_Wrapper::SWITCH_EQUIPMENT;

    }else if (user_symbol == commands.switch_consumable){
        return Command_Wrapper::SWITCH_CONSUMABLE;

    }else if (user_symbol == commands.use_consumable){
        return Command_Wrapper::USE_CONSUMABLE;

    }else if (user_symbol == commands.drop_equipment){
        return Command_Wrapper::DROP_EQUIPMENT;

    }else if (user_symbol == commands.drop_consumable){
        return Command_Wrapper::DROP_CONSUMABLE;

    }
}




