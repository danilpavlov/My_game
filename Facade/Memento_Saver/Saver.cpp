//
// Created by Даниил Павлов on 23.10.2022.
//

#include "Saver.h"
#define ALL_FILES_ARE_OPEN saveFiles.hero_x_pos_file.is_open() && saveFiles.hero_y_pos_file.is_open() && saveFiles.xp_file.is_open() && saveFiles.hp_file.is_open() && saveFiles.hero_level_file.is_open() && saveFiles.field_level_file.is_open() && saveFiles.field_file.is_open()

void Saver::save(Field *main_filed) {

    clear_all_files();

    Singleton_Hero* hero = Singleton_Hero::getInstance();
    open_all_files();
    if (ALL_FILES_ARE_OPEN) {
        saveFiles.hero_x_pos_file << hero->get_hero_position(Singleton_Hero::x);
        saveFiles.hero_y_pos_file << hero->get_hero_position(Singleton_Hero::y);

        saveFiles.xp_file << hero->get_hero_attribute(Singleton_Hero::experience);
        saveFiles.hp_file << hero->get_hero_attribute(Singleton_Hero::health_points);
        saveFiles.hero_level_file << hero->get_hero_attribute(Singleton_Hero::level);

        saveFiles.field_level_file << main_filed->get_level();

        for (int i = 0; i < main_filed->get_y(); i++){

            for (int j = 0; j < main_filed->get_x(); j++){
                switch(main_filed->get_field()[i][j].get_state()) {
                    case Cell::EMPTY:
                        saveFiles.field_file << '0';
                        break;
                    case Cell::HERO:
                        saveFiles.field_file << '1';
                        break;
                    case Cell::WALL:
                        saveFiles.field_file << '2';
                        break;
                    case Cell::HEAL:
                        saveFiles.field_file << '3';
                        break;
                    case Cell::XP:
                        saveFiles.field_file << '4';
                        break;
                    case Cell::ENEMY:
                        saveFiles.field_file << '5';
                        break;
                    case Cell::TELEPORT:
                        saveFiles.field_file << '6';
                        break;
                    case Cell::WIN:
                        saveFiles.field_file << '7';
                        break;
                    case Cell::REFRESHER_OF_EVENTS:
                        saveFiles.field_file << '8';
                        break;
                    case Cell::PUMPKIN_HEAD:
                        saveFiles.field_file << '9';
                        break;
                    case Cell::GHOST_HEAD:
                        saveFiles.field_file << 'G';
                        break;
                    case Cell::DRUG:
                        saveFiles.field_file << 'D';
                        break;
                    case Cell::HEAL_POTION:
                        saveFiles.field_file << 'H';
                        break;
                    case Cell::DAGGER:
                        saveFiles.field_file << 'S';
                        break;
                    case Cell::MAGIC_GLOVE:
                        saveFiles.field_file << 'Q';
                        break;
                }
            }
        }
    }else if (!ALL_FILES_ARE_OPEN){
        throw std::exception();
    }


    close_all_files();
}

void Saver::restore(Memento *memento, Field *main_field) {

    Singleton_Hero* hero = Singleton_Hero::getInstance();

    open_all_files();
    if (ALL_FILES_ARE_OPEN) {

        hero->set_hero_attribute(Singleton_Hero::health_points, memento->hero_attribute(Singleton_Hero::health_points));
        hero->set_hero_attribute(Singleton_Hero::experience, memento->hero_attribute(Singleton_Hero::experience));
        hero->set_hero_attribute(Singleton_Hero::level, memento->hero_attribute(Singleton_Hero::level));

        hero->set_hero_position(Singleton_Hero::x, memento->hero_position(Singleton_Hero::x));
        hero->set_hero_position(Singleton_Hero::y, memento->hero_position(Singleton_Hero::y));

        main_field->set_field(memento->get_field());
        main_field->set_level(memento->field_level());


    }else{
        throw std::exception();
    }

    close_all_files();


}

void Saver::open_all_files() {

    saveFiles.field_file.open(saveFiles.field_path, std::ios::app);
    saveFiles.field_level_file.open(saveFiles.field_level_path, std::ios::app);

    saveFiles.hero_level_file.open(saveFiles.hero_level_path, std::ios::app);
    saveFiles.hp_file.open(saveFiles.hp_path, std::ios::app);
    saveFiles.xp_file.open(saveFiles.xp_path, std::ios::app);

    saveFiles.hero_x_pos_file.open(saveFiles.hero_x_pos_path, std::ios::app);
    saveFiles.hero_y_pos_file.open(saveFiles.hero_y_pos_path, std::ios::app);
}

void Saver::close_all_files() {

    saveFiles.field_file.close();
    saveFiles.field_level_file.close();

    saveFiles.hero_level_file.close();
    saveFiles.hp_file.close();
    saveFiles.xp_file.close();

    saveFiles.hero_x_pos_file.close();
    saveFiles.hero_y_pos_file.close();
}

void Saver::clear_all_files() {
    std::fstream clear_field_file(saveFiles.field_path, std::ios::out);
    clear_field_file.close();

    std::fstream clear_field_level_file(saveFiles.field_level_path, std::ios::out);
    clear_field_level_file.close();

    std::fstream clear_hero_level_file(saveFiles.hero_level_path, std::ios::out);
    clear_hero_level_file.close();

    std::fstream clear_hp_file(saveFiles.hp_path, std::ios::out);
    clear_hp_file.close();

    std::fstream clear_xp_file(saveFiles.xp_path, std::ios::out);
    clear_xp_file.close();

    std::fstream clear_hero_x_file(saveFiles.hero_x_pos_path, std::ios::out);
    clear_hero_x_file.close();

    std::fstream clear_hero_y_file(saveFiles.hero_y_pos_path, std::ios::out);
    clear_hero_y_file.close();
}

Memento *Saver::save_current_memento() {
    return new Memento_Save();
}
