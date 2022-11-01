//
// Created by Даниил Павлов on 18.09.2022.
//

#ifndef MY_GAME_GAME_LOGIC_H
#define MY_GAME_GAME_LOGIC_H
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <ncurses.h>
#include "../kbhit.h"

#include "./Field/Field.h"
#include "./Field/Space_Request.h"

#include "Singleton/Singleton_Hero.h"

#include "mediator/Mediator.h"


#include "Display/Sockets/Intro.h"
#include "Display/Sockets/Field_Painter.h"
#include "Display/Sockets/Attribute_display.h"
#include "Display/Display_Wrapper.h"

#include "Logs/ISubject.h"
#include "Logs/Loggers/Console_Logger.h"
#include "Logs/Loggers/File_Logger.h"

#include "Input_Command_Readers/Command_Wrapper.h"


#include "Objects_Generator/Strategy/Level_Context.h"
#include "Objects_Generator/Strategy/ConcreteStrategies/Level_One.h"
#include "Objects_Generator/Strategy/ConcreteStrategies/Level_Two.h"

#include "Memento_Saver/Caretaker.h"

#include "Inventory/Inventory.h"

class Game_Logic{
public:
    enum levels{FIRST, SECOND};

    Game_Logic();

    void start_main_menu();

    ~Game_Logic();

private:

    levels current_level;
    bool end_choice;

    Display_Wrapper* display_wrapper;

    Field* ground;

    Singleton_Hero* hero;

    Mediator* mediator;

    void intro();

    bool end = false;
    bool quit = false;
    bool load_checker = false;

    void start_new_game();

    void generate_level(levels current_level);

    int logging_setter = 0;

    Console_Logger* consoleLogger_;
    File_Logger* fileLogger_;

    Event_Message* message;

    void Attach_all_to(IObserver *observer);
    void Detach_all_from(IObserver *observer);


    Request_Stream* request_input_stream;
    void request_user_about_input_stream();

    Command_Wrapper* command_wrapper;


    Level_Context levelContext;

    void start_user_level_choice();

    Saver *game_saver;
    Caretaker* caretaker;

    Inventory* inventory;

    void quick_load();

};


#endif //MY_GAME_GAME_LOGIC_H
