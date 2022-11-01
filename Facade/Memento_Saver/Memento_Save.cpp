//
// Created by Даниил Павлов on 23.10.2022.
//

#include "Memento_Save.h"
#include <exception>

std::vector<std::vector<Cell>> Memento_Save::get_field() const {
    std::vector<std::vector<Cell>> field;

    std::string path = "Save/Saved_Field.txt";
    std::ifstream file;
    file.open(path);

    if (!file.is_open()){
        throw std::exception();
    }
    int cell_count = 0;
    int heroes_count = 0;

    for (int i = 0; i < 24; i++){
        std::vector<Cell> tmp;

        for (int j = 0; j < 75; j++){
            char cell_number;
            cell_count++;

            Cell tmp_cell(Cell::EMPTY, Cell::NO_EVENT);
            file >> cell_number;
            switch(cell_number){
                case '1':
                    tmp_cell.set_state(Cell::HERO);
                    heroes_count++;
                    break;
                case '2':
                    tmp_cell.set_state(Cell::WALL);
                    break;
                case '3':
                    tmp_cell.set_state(Cell::HEAL);
                    tmp_cell.set_event(Cell::POSITIVE_EVENT);
                    break;
                case '4':
                    tmp_cell.set_state(Cell::XP);
                    tmp_cell.set_event(Cell::POSITIVE_EVENT);
                    break;
                case '5':
                    tmp_cell.set_state(Cell::ENEMY);
                    tmp_cell.set_event(Cell::NEGATIVE_EVENT);
                    break;
                case '6':
                    tmp_cell.set_state(Cell::TELEPORT);
                    tmp_cell.set_event(Cell::NEGATIVE_EVENT);
                    break;
                case '7':
                    tmp_cell.set_state(Cell::WIN);
                    tmp_cell.set_event(Cell::GLOBAL_EVENT);
                    break;
                case '8':
                    tmp_cell.set_state(Cell::REFRESHER_OF_EVENTS);
                    tmp_cell.set_event(Cell::GLOBAL_EVENT);
                    break;
                case '9':
                    tmp_cell.set_state(Cell::PUMPKIN_HEAD);
                    tmp_cell.set_event(Cell::ITEM);
                    break;
                case 'G':
                    tmp_cell.set_state(Cell::GHOST_HEAD);
                    tmp_cell.set_event(Cell::ITEM);
                    break;
                case 'D':
                    tmp_cell.set_state(Cell::DRUG);
                    tmp_cell.set_event(Cell::ITEM);
                case 'H':
                    tmp_cell.set_state(Cell::HEAL_POTION);
                    tmp_cell.set_event(Cell::ITEM);
                    break;
                default:
                    break;
            }
            tmp.push_back(tmp_cell);
        }
        field.push_back(tmp);
    }

    if (heroes_count != 1 || cell_count != (75*24)){
        throw std::exception();
    }


    return field;
}

int Memento_Save::hero_position(Singleton_Hero::coordinates coordinate) const {
    int position;
    std::string path;
    std::ifstream file;

    switch(coordinate){
        case Singleton_Hero::x:
            path = "Save/Saved_Hero_X.txt";
            break;
        case Singleton_Hero::y:
            path = "Save/Saved_Hero_Y.txt";
            break;
        default:
            break;
    }
    assert(path == "Save/Saved_Hero_X.txt" || path == "Save/Saved_Hero_Y.txt");
    file.open(path);

    if (file.is_open()){
        file >> position;
    }else{
        throw std::exception();
    }

    if (path == "Save/Saved_Hero_X.txt" && (position > 75 || position < 0)){
        throw std::exception();
    }else if (path == "Save/Saved_Hero_Y.txt" && (position > 24 || position < 0)){
        throw std::exception();
    }

    return position;
}

int Memento_Save::hero_attribute(Singleton_Hero::hero_attributes attribute) const {
    int attribute_amount;

    std::ifstream file;
    std::string path;

    switch (attribute) {
        case Singleton_Hero::level:
            path = "Save/Saved_Hero_Level.txt";
            break;
        case Singleton_Hero::health_points:
            path = "Save/Saved_HP.txt";
            break;
        case Singleton_Hero::experience:
            path = "Save/Saved_XP.txt";
            break;
        default:
            break;
    }
    assert(path == "Save/Saved_Hero_Level.txt" || path == "Save/Saved_HP.txt" || path == "Save/Saved_XP.txt");
    file.open(path);

    if (file.is_open()) {
        file >> attribute_amount;
    }else{
        throw std::exception();
    }

    if (attribute_amount > 9 && path == "Save/Saved_HP.txt"){
        throw std::exception();
    }else if (attribute_amount < 1 && path == "Save/Saved_HP.txt"){
        throw std::exception();
    }else if (attribute_amount < 0 && (path == "Save/Saved_Hero_Level.txt" || path == "Save/Saved_XP.txt") ){
        throw std::exception();
    }

    file.close();
    return attribute_amount;
}

int Memento_Save::field_level() const {
    int level;
    std::string path = "Save/Saved_Field_Level.txt";
    std::ifstream file;

    file.open(path);
    if (!file.is_open()){
        throw std::exception();
    }

    file >> level;

    if (level == 2 || level == 1) {
        file.close();
    }else{
        throw std::exception();
    }
    return level;
}
