//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_FREEZE_H
#define MY_GAME_FREEZE_H
#include "../Weather_Sockets/IWeather.h"

class Freeze : public IWeather{
public:
    void set_weather(Field* filed, weather_zone* zone) override;
};


#endif //MY_GAME_FREEZE_H
