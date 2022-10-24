//
// Created by Даниил Павлов on 28.09.2022.
//

#ifndef MY_GAME_FIELD_PAINTER_H
#define MY_GAME_FIELD_PAINTER_H
#include "../../Field/Field.h"
#include "../../Logs/Loggers/Console_Logger.h"

class Field_Painter{
public:
    Field_Painter();
    void draw_field(Field* main_field, Console_Logger* console_logger, int level);
    void set_logging_state(int new_state);

private:
    int logging_state;
    std::vector <std::string> logs;
    std::vector< std::vector<Cell> > field_2d;
};


#endif //MY_GAME_FIELD_PAINTER_H
