//
// Created by Даниил Павлов on 08.10.2022.
//

#ifndef MY_GAME_INPUT_STREAM_READER_H
#define MY_GAME_INPUT_STREAM_READER_H
#include "../Command_Reader.h"
#include <iostream>

class Input_Stream_Reader : public Command_Reader{
public:
    char get_character() override;
};


#endif //MY_GAME_INPUT_STREAM_READER_H
