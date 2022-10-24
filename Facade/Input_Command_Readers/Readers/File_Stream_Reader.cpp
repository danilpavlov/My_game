//
// Created by Даниил Павлов on 08.10.2022.
//

#include "File_Stream_Reader.h"

char File_Stream_Reader::get_character() {
    std::ifstream file;
    std::string path = "/Users/pavlov/CLionProjects/My_game/File_Controller.txt";

    file.open(path);

    if (file.is_open()){
        char move;
        move = file.get();
        file.close();
        sleep(1);
        return move;
    }else{
        std::cout << "[ERROR] Can't open file." << std::endl;
        throw std::exception();
    }
}
