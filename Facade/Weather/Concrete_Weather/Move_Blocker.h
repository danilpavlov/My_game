//
// Created by Даниил Павлов on 05.11.2022.
//

#ifndef MY_GAME_MOVE_BLOCKER_H
#define MY_GAME_MOVE_BLOCKER_H
#include "../Weather_Sockets/IWeather.h"

class Move_Blocker : public IWeather{
public:
    void set_weather(Field* field, weather_zone* zone) override;
};


#endif //MY_GAME_MOVE_BLOCKER_H
