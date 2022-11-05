//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_THUNDER_H
#define MY_GAME_THUNDER_H
#include "../Weather_Sockets/IWeather.h"

class Thunder : public IWeather{
public:
    void set_weather(Field* field, weather_zone* zone) override;
};


#endif //MY_GAME_THUNDER_H
