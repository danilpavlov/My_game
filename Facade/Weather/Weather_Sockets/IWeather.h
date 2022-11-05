//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_IWEATHER_H
#define MY_GAME_IWEATHER_H
#include "../../Field/Field.h"

struct weather_zone{
    int x1;
    int x2;
    int y1;
    int y2;
};

class IWeather {
public:
    virtual void set_weather(Field* field, weather_zone* zone) = 0;


};


#endif //MY_GAME_IWEATHER_H
