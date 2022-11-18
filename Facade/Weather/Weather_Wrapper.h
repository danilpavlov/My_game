//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_WEATHER_WRAPPER_H
#define MY_GAME_WEATHER_WRAPPER_H
#include "Concrete_Weather/Fog.h"
#include "Concrete_Weather/Freeze.h"
#include "Concrete_Weather/Fire.h"
#include "Concrete_Weather/Move_Blocker.h"
#include "Concrete_Weather/Random_Mover.h"

class Weather_Wrapper {
public:
    Weather_Wrapper();

    void roll_the_dice_for_weather(Field* field);

    ~Weather_Wrapper();
private:
    std::vector <IWeather*> possible_weather;
    weather_zone* zone;
    bool is_weather_right_now;

    void set_zone(Field*);

    void cause_the_weather(Field* field, int random_weather_grasper);
    void remove_the_weather(Field* field);

};


#endif //MY_GAME_WEATHER_WRAPPER_H
