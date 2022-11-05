//
// Created by Даниил Павлов on 04.11.2022.
//

#ifndef MY_GAME_WEATHER_WRAPPER_H
#define MY_GAME_WEATHER_WRAPPER_H
#include "Concrete_Weather/Fog.h"
#include "Concrete_Weather/Freeze.h"
#include "Concrete_Weather/Thunder.h"

#include <chrono>
#define WEATHER_TIME 9

class Weather_Wrapper {
public:
    Weather_Wrapper();

    void set_zone(int x1, int x2, int y1, int y2);

    void cause_the_weather(Field* field, int random_weather_grasper);
    void remove_the_weather(Field* field);

    std::chrono::time_point<std::chrono::system_clock> get_start_time();
    void set_start_time();

    int possible_weather_amount();

    ~Weather_Wrapper();
private:
    std::vector <IWeather*> possible_weather;
    weather_zone* zone;
    std::chrono::time_point<std::chrono::system_clock> start_time;
};


#endif //MY_GAME_WEATHER_WRAPPER_H
