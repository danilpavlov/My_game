//
// Created by Даниил Павлов on 04.11.2022.
//

#include "Weather_Wrapper.h"

Weather_Wrapper::Weather_Wrapper() {
    zone = new weather_zone;

    possible_weather.push_back(new Fog);
    possible_weather.push_back(new Freeze);
    possible_weather.push_back(new Thunder);
}

void Weather_Wrapper::set_zone(int x1, int x2, int y1, int y2) {
    zone->x1 = x1;
    zone->x2 = x2;
    zone->y1 = y1;
    zone->y2 = y2;
}

void Weather_Wrapper::cause_the_weather(Field *field, int random_weather_grasper) {
    possible_weather[random_weather_grasper % possible_weather.size()]->set_weather(field, zone);
}

void Weather_Wrapper::remove_the_weather(Field *field) {
    std::vector<std::vector<Cell>> tmp_field = field->get_field();

    for (int i = zone->y1; i < zone->y2; i++){

        for (int j = zone->x1; j < zone->x2; j++){
            tmp_field[i][j].set_weather(Cell::NONE);
        }
    }

    field->set_field(tmp_field);
}

std::chrono::time_point<std::chrono::system_clock> Weather_Wrapper::get_start_time() {
    return start_time;
}

void Weather_Wrapper::set_start_time() {
    start_time = std::chrono::system_clock::now();
}

Weather_Wrapper::~Weather_Wrapper() {
    possible_weather.clear();
    delete zone;
}

int Weather_Wrapper::possible_weather_amount() {
    return possible_weather.size();
}

