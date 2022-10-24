//
// Created by Даниил Павлов on 30.09.2022.
//

#include "Console_Logger.h"

void Console_Logger::update(std::string message) {
    logs.push_back(message);
}

std::vector<std::string> Console_Logger::get_logs() {
    return logs;
}
