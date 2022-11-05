//
// Created by Даниил Павлов on 05.11.2022.
//

#include "Move_Blocker.h"

void Move_Blocker::set_weather(Field *field, weather_zone *zone) {
    std::vector<std::vector<Cell>> tmp_field = field->get_field();

    for (int i = zone->y1; i < zone->y2; i++){

        for (int j = zone->x1; j < zone->x2; j++){
            tmp_field[i][j].set_weather(Cell::MOVE_BLOCKER);
        }
    }

    field->set_field(tmp_field);
}
