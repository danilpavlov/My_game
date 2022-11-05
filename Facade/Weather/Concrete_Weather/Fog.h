//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_FOG_H
#define MY_GAME_FOG_H
#include "../Weather_Sockets/IWeather.h"

class Fog : public IWeather{
public:
    void set_weather(Field* filed, weather_zone* zone) override;
};


#endif //MY_GAME_FOG_H
