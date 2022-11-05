//
// Created by Даниил Павлов on 30.09.2022.
//

#include "File_Logger.h"

std::ostream &operator<<(std::fstream &stream, File_Logger& obj) {

    stream << obj.message;

    return stream;
}

void File_Logger::update(std::string new_message) {

    const std::time_t now = std::time(nullptr);

    const std::tm calendar_time = *std::localtime( std::addressof(now) );


    if (logs.is_open()) {
        logs << calendar_time.tm_hour << ":" << calendar_time.tm_min << ":" << calendar_time.tm_sec << "  " << new_message << std::endl;
    }else{
        std::cout << "[ERROR] Can't open file.";
    }

}

void File_Logger::clear() {
    std::fstream clear_file(path, std::ios::out);
    clear_file.close();
}

File_Logger::File_Logger() {
    logs.open(path, std::ios_base::app);
}

File_Logger::~File_Logger() {
    logs.close();
}







