//
// Created by Даниил Павлов on 30.09.2022.
//

#ifndef MY_GAME_FILE_LOGGER_H
#define MY_GAME_FILE_LOGGER_H
#include "../IObserver.h"
#include "../Message/Message.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <ostream>

class File_Logger : public IObserver{
public:
    File_Logger();

    void update(std::string message) override;
    void clear();
    friend std::ostream& operator<<(std::fstream& stream, File_Logger& obj);

    ~File_Logger() override;

private:
     std::string message;
     std::fstream logs;
     std::string path = "Logs.txt";
};


#endif //MY_GAME_FILE_LOGGER_H
