//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_FIRE_H
#define MY_GAME_FIRE_H
#include "../Weather_Sockets/IWeather.h"

class Fire : public IWeather{
public:
    void set_weather(Field* field, weather_zone* zone) override;
};


#endif //MY_GAME_FIRE_H
