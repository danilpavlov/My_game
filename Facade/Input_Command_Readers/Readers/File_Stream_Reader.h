//
// Created by Даниил Павлов on 08.10.2022.
//

#ifndef MY_GAME_FILE_STREAM_READER_H
#define MY_GAME_FILE_STREAM_READER_H
#include "../Command_Reader.h"
#include <fstream>
#include <iostream>
#include <unistd.h>

class File_Stream_Reader : public Command_Reader{
public:
    File_Stream_Reader();
    char get_character() override;
    ~File_Stream_Reader();
private:
    std::ifstream file;
    std::string path = "File_Controller.txt";   // done
};


#endif //MY_GAME_FILE_STREAM_READER_H
