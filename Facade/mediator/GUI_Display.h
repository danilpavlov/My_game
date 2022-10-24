//
// Created by Даниил Павлов on 25.09.2022.
//

#ifndef MY_GAME_GUI_DISPLAY_H
#define MY_GAME_GUI_DISPLAY_H
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>

class GUI_Display{
public:
    enum type{NEW_GAME, LOAD_GAME, QUIT, YES, NO, FIRST_LEVEL, SECOND_LEVEL, BACK};

    GUI_Display();

    type get_type(){
        return type_now;
    }

    void set_type(type new_type){
        type_now = new_type;
    }


    void print_main_menu(type string_type, char* color);

    void print_file_control_request(type string_type, char* color);

    void print_level_choice(type string_type, char* color);
    ~GUI_Display();


private:
    type type_now;

    std::vector<std::string> new_game_string;
    std::vector<std::string> load_game_string;
    std::vector<std::string> quit_string;

    std::vector<std::string> yes_string;
    std::vector<std::string> no_string;

    std::vector<std::string> first_level_string;
    std::vector<std::string> second_level_string;
    std::vector<std::string> back_string;

};


#endif //MY_GAME_GUI_DISPLAY_H

