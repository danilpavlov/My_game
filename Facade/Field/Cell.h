//
// Created by Даниил Павлов on 16.09.2022.
//

#ifndef MY_GAME_CELL_H
#define MY_GAME_CELL_H

class Cell {
public:
    enum cell_state{HERO, EMPTY, WALL, HEAL, XP, TELEPORT, ENEMY, WIN, REFRESHER_OF_EVENTS, GHOST_HEAD, PUMPKIN_HEAD, HEAL_POTION, DRUG, DAGGER, MAGIC_GLOVE};
    enum cell_event{NO_EVENT, POSITIVE_EVENT, NEGATIVE_EVENT, GLOBAL_EVENT, ITEM};

    enum weather_status{NONE, FREEZE, FIRE, FOG, MOVE_BLOCKER, RANDOM_MOVER};

    cell_state get_state() const{
        return state_now;
    }

    void set_state(cell_state new_state){
        state_now = new_state;
    };

    cell_event get_event() const{
        return event_now;
    }

    void set_event(cell_event new_event){
        event_now = new_event;
    }

    weather_status get_weather() const{
        return weather_now;
    }

    void set_weather(weather_status new_weather_status){
        weather_now = new_weather_status;
    }


    Cell(cell_state, cell_event, weather_status);



private:
    cell_state state_now;
    cell_event event_now;
    weather_status weather_now;

};



#endif //MY_GAME_CELL_H
