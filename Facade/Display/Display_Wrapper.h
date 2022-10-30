//
// Created by Даниил Павлов on 30.09.2022.
//

#ifndef MY_GAME_DISPLAY_WRAPPER_H
#define MY_GAME_DISPLAY_WRAPPER_H
#include "Sockets/Attribute_display.h"
#include "Sockets/Intro.h"
#include "Sockets/Field_Painter.h"
#include "Sockets/File_Control_Request_Display.h"
#include <iostream>
#include <string>
#include "Sockets/Inventory_Display.h"

class Display_Wrapper{
public:
    Display_Wrapper();

    void show_request_file_control();
    void static_show_request_file_control();
    void show_alucard();

    void in_game_intro();
    void show_intro();

    void print_devil(std::string tab);

    void draw(Field* field, Console_Logger* console_logger, int level, Inventory* inventory);
    void draw_field_only(Field* field, int level);



    void print_victory(std::string tab);
    void print_lose(bool quit, std::string tab);


    ~Display_Wrapper();


    void set_logging(int new_logging_state);

    void print_cant_load();


private:
    Attribute_display* attribute_display;
    Inventory_Display* inventory_display;
    Intro* intro;
    Field_Painter* field_painter;
    File_Control_Request_Display* request_file_control;

    void print_press_any_button(std::string tab);
};


#endif //MY_GAME_DISPLAY_WRAPPER_H
