//
// Created by Даниил Павлов on 30.09.2022.
//

#ifndef MY_GAME_CONSOLE_LOGGER_H
#define MY_GAME_CONSOLE_LOGGER_H
#include "../IObserver.h"
#include <vector>

class Console_Logger : public IObserver{
public:
    void update(std::string message) override;
    std::vector<std::string> get_logs();
private:
    std::vector<std::string> logs;
};


#endif //MY_GAME_CONSOLE_LOGGER_H
