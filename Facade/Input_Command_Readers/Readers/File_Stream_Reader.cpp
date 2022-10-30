//
// Created by Даниил Павлов on 08.10.2022.
//

#include "File_Stream_Reader.h"

char File_Stream_Reader::get_character() {
//    if (file.is_open()){
//        file.close();
//    }
//    file.open(path);
    if (file.is_open()){
        sleep(1);
        return file.get();
    }else{
        std::cout << "[ERROR] Can't open File Controller." << std::endl;
        throw std::exception();
    }
}

File_Stream_Reader::File_Stream_Reader() {
    file.open(path);
}

File_Stream_Reader::~File_Stream_Reader() {
    file.close();
}
