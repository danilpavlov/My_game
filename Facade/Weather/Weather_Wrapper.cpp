//
// Created by Даниил Павлов on 04.11.2022.
//

#include "Weather_Wrapper.h"

Weather_Wrapper::Weather_Wrapper() {
    zone = new weather_zone;

    possible_weather.push_back(new Fog);
    possible_weather.push_back(new Freeze);
    possible_weather.push_back(new Fire);
    possible_weather.push_back(new Move_Blocker);

    is_weather_right_now = false;
}

void Weather_Wrapper::set_zone(Field* ground) {
    int random_x1, random_x2, random_y1, random_y2, tmp_1, tmp_2;

    tmp_1 = std::rand() % ground->get_x();
    tmp_2 = std::rand() % ground->get_x();
    random_x1 = std::min(tmp_1, tmp_2);
    random_x2 = std::max(tmp_1, tmp_2);

    zone->x1 = random_x1;
    zone->x2 = random_x2;

    tmp_1 = std::rand() % ground->get_y();
    tmp_2 = std::rand() % ground->get_y();
    random_y1 = std::min(tmp_1, tmp_2);
    random_y2 = std::max(tmp_1, tmp_2);

    zone->y1 = random_y1;
    zone->y2 = random_y2;
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

Weather_Wrapper::~Weather_Wrapper() {
    possible_weather.clear();
    delete zone;
}


void Weather_Wrapper::roll_the_dice_for_weather(Field* ground) {

    if (!is_weather_right_now && (std::rand() % 1000 > 960)) {
        set_zone(ground);
        cause_the_weather(ground, std::rand() % possible_weather.size());
        is_weather_right_now = true;

    }else if (is_weather_right_now &&  (std::rand() % 1000 > 990)){
        remove_the_weather(ground);
        is_weather_right_now = false;
    }
}


