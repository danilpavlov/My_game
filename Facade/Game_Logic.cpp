//
// Created by Даниил Павлов on 18.09.2022.
//

#include "Game_Logic.h"
#define TAB "\t\t\t\t\t\t\t"

Game_Logic::Game_Logic() {
    consoleLogger_ = new Console_Logger;
    fileLogger_ = new File_Logger;

    fileLogger_->clear();

    ground = new Field;

    display_wrapper = new Display_Wrapper;

    this->hero = Singleton_Hero::getInstance();

    this->ground->create_2D_field();

    mediator = new Mediator(ground);

    command_wrapper = new Command_Wrapper;

    request_input_stream = new Request_Stream;

    game_saver = new Saver;
    caretaker = new Caretaker(game_saver);
    caretaker->backup();

    inventory = new Inventory;
}


void Game_Logic::start_new_game() {
    switch(current_level) {
        case Game_Logic::FIRST:
            system("afplay Music/Joy_Division__Disorder.mp3 &");
            break;
        case Game_Logic::SECOND:
            system("afplay Music/Slint__Nosferatu_Man.mp3 &");
            break;
        default:
            break;
    }
    char dynamic_message_color[] = { 0x1b, '[', '3', '8',';','5',';','1', '6', '6', 'm',0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);

    while (true) {

        if (kbhit()) {
            switch (command_wrapper->read_user_symbol()) {
                case Command_Wrapper::MOVE_UP:

                    system("clear");
                    display_wrapper->in_game_intro();

                    mediator->move_hero(Mediator::UP, ground, inventory);

                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::MOVE_LEFT:
                    system("clear");
                    display_wrapper->in_game_intro();

                    mediator->move_hero(Mediator::LEFT, ground, inventory);

                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::MOVE_RIGHT:
                    system("clear");
                    display_wrapper->in_game_intro();

                    mediator->move_hero(Mediator::RIGHT, ground, inventory);

                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::MOVE_DOWN:
                    system("clear");
                    display_wrapper->in_game_intro();

                    mediator->move_hero(Mediator::DOWN, ground, inventory);

                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::QUIT:

                    system("clear");

                    end = true;
                    quit = true;
                    break;

                case Command_Wrapper::LOG_STREAM:
                    logging_setter += 1;

                    if (fmod(logging_setter, 4) == 0){
                        Attach_all_to(fileLogger_);
                        Detach_all_from(consoleLogger_);

                        display_wrapper->set_logging(0);
                        system("clear");
                        display_wrapper->in_game_intro();
                        display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    }else if (fmod(logging_setter, 4) == 1){
                        Detach_all_from(fileLogger_);
                        Attach_all_to(consoleLogger_);

                        display_wrapper->set_logging(1);
                        system("clear");
                        display_wrapper->in_game_intro();
                        display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    }else if (fmod(logging_setter, 4) == 2){
                        Attach_all_to(fileLogger_);

                        display_wrapper->set_logging(2);
                        system("clear");
                        display_wrapper->in_game_intro();
                        display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    }else if (fmod(logging_setter, 4) == 3){
                        Detach_all_from(consoleLogger_);
                        Detach_all_from(fileLogger_);

                        display_wrapper->set_logging(3);
                        system("clear");
                        display_wrapper->in_game_intro();
                        display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    }
                    break;

                case Command_Wrapper::SAVE:
                    std::cout << dynamic_message_color << "\tGame Was Saved!" << normal <<std::endl;
                    caretaker->backup();
                    game_saver->save(ground);
                    break;

                case Command_Wrapper::SWITCH_EQUIPMENT:
                    system("clear");
                    display_wrapper->in_game_intro();

                    inventory->switch_equipment();

                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::SWITCH_CONSUMABLE:
                    system("clear");
                    display_wrapper->in_game_intro();

                    inventory->switch_consumable();
                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::USE_CONSUMABLE:
                    system("clear");
                    display_wrapper->in_game_intro();

                    inventory->use_consumable();
                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::DROP_EQUIPMENT:
                    system("clear");
                    display_wrapper->in_game_intro();

                    inventory->throw_out( inventory->get_equipment_slots() [inventory->get_equipment_switcher()%3] );
                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                case Command_Wrapper::DROP_CONSUMABLE:
                    system("clear");
                    display_wrapper->in_game_intro();

                    inventory->throw_out( inventory->get_consumable_slots() [inventory->get_consumable_switcher()%3] );
                    display_wrapper->draw(ground, consoleLogger_, current_level, inventory);
                    break;

                default:
                    break;

            }
            ///// END SWITCH-CASE :)

            if (hero->is_hero_won()){
                system("killall afplay");
                system("afplay Music/The_Smiths__This_Charming_Man.mp3 &");
                inventory->clear_inventory();
                display_wrapper->print_victory(TAB);


                while(true){
                    if (kbhit()){
                        system("killall afplay");
                        system("afplay Music/Have_A_Nice_Life__Bloodhail.mp3 &");

                        system("clear");
                        display_wrapper->in_game_intro();
                        mediator->move_level_choice(GUI_Display::BACK);

                        break;
                    }
                }

                break;
            }else if (!hero->is_alive()){
                system("killall afplay");
                system("afplay Music/1-1.mp3 &");
                inventory->clear_inventory();
                display_wrapper->print_lose(true, TAB);

                while(true){
                    if (kbhit()){
                        system("killall afplay");
                        system("afplay Music/Have_A_Nice_Life__Bloodhail.mp3 &");

                        system("clear");
                        display_wrapper->in_game_intro();
                        mediator->move_level_choice(GUI_Display::BACK);

                        break;
                    }
                }

                break;
            }

        }
        hero->set_hero_attribute(Singleton_Hero::level, hero->get_hero_attribute(Singleton_Hero::experience)/7);
        if (end){
            end_choice = true;
            break;
        }
    }


}


void Game_Logic::start_main_menu() {

    request_user_about_input_stream();

    intro();

    system("afplay Music/Have_A_Nice_Life__Bloodhail.mp3 &");


    int mover = 0;
    display_wrapper->in_game_intro();
    mediator->move_menu(GUI_Display::NEW_GAME);
    display_wrapper->print_devil(TAB);
    while (!quit){


        if (kbhit()){

            switch (command_wrapper->read_user_symbol()){
                case Command_Wrapper::MOVE_DOWN:
                    system("clear");
                    std::cout << '\a';
                    display_wrapper->in_game_intro();

                    if ( fmod(fmod(mover, 3) + 3, 3) == 0){
                        mediator->move_menu(GUI_Display::LOAD_GAME);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 1){
                        mediator->move_menu(GUI_Display::QUIT);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 2){
                        mediator->move_menu(GUI_Display::NEW_GAME);
                    }
                    display_wrapper->print_devil(TAB);


                    mover += 1;
                    break;
                case Command_Wrapper::MOVE_UP:
                    system("clear");
                    std::cout << '\a';
                    display_wrapper->in_game_intro();

                    if ( fmod(fmod(mover, 3) + 3, 3) == 0){
                        mediator->move_menu(GUI_Display::QUIT);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 1){
                        mediator->move_menu(GUI_Display::NEW_GAME);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 2){
                        mediator->move_menu(GUI_Display::LOAD_GAME);
                    }
                    display_wrapper->print_devil(TAB);

                    mover -= 1;
                    break;
                case Command_Wrapper::ENTER:
                    system("clear");
                    display_wrapper->in_game_intro();

                    switch (mediator->get_menu_type()){
                        case GUI_Display::NEW_GAME:

                            start_user_level_choice();
                            break;
                        case GUI_Display::LOAD_GAME:
                            try {
                                ground->clear_field();
                                hero->set_hero_to_default(0, 0);
                                caretaker->load_game(ground);
                                mediator->set_field(ground);
                                system("killall afplay");

                                current_level = static_cast<levels>(ground->get_level() - 1);
                                Game_Logic::start_new_game();
                            }catch (std::exception){
                                display_wrapper->print_cant_load();
                            }

                            break;
                        case GUI_Display::QUIT:
                            quit = true;
                            break;
                    }
                default:
                    break;
            }
        }
    }
    system("clear");

}

void Game_Logic::intro() {
    display_wrapper->show_intro();
}

void Game_Logic::Attach_all_to(IObserver *observer) {
    mediator->Attach(observer);
    request_input_stream->Attach(observer);
}

void Game_Logic::Detach_all_from(IObserver *observer) {
    mediator->Detach(observer);
    request_input_stream->Detach(observer);

}

void Game_Logic::request_user_about_input_stream() {
    Attach_all_to(fileLogger_);
    Detach_all_from(consoleLogger_);

    system("afplay Music/in_the_flash.mp3 &");
    Request_Stream::chosen_stream choice;
    choice = request_input_stream->request_user();
    display_wrapper->show_alucard();

    if (choice == Request_Stream::STANDART){
        command_wrapper->make_standart_input();
    }else if (choice == Request_Stream::FILE){
        command_wrapper->make_file_input();
    }
    system("killall afplay");

}


Game_Logic::~Game_Logic() {
    delete display_wrapper;
    delete mediator;
    delete hero;
    delete consoleLogger_;
    delete fileLogger_;
    delete request_input_stream;


}

void Game_Logic::generate_level(levels current_level_) {
    switch(current_level_){
        case levels::FIRST:
            levelContext.set_strategy(std::make_unique<Level_One>(ground));
            levelContext.create_new_level(ground);
            break;
        case levels::SECOND:
            levelContext.set_strategy(std::make_unique<Level_Two>(ground));
            levelContext.create_new_level(ground);
            break;
    }
}

void Game_Logic::start_user_level_choice() {

    mediator->move_level_choice(GUI_Display::BACK);
    int mover = 0;
    end_choice = false;

    while(!end_choice){

        if (kbhit()){

            switch (command_wrapper->read_user_symbol()) {
                case Command_Wrapper::MOVE_DOWN:
                    system("clear");
                    std::cout << '\a';
                    display_wrapper->in_game_intro();

                    if ( fmod(fmod(mover, 3) + 3, 3) == 0){
                        mediator->move_level_choice(GUI_Display::FIRST_LEVEL);
                        current_level = Game_Logic::FIRST;
                        ground->clear_field();

                        generate_level(levels::FIRST);
                        display_wrapper->draw_field_only(ground, current_level);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 1){
                        mediator->move_level_choice(GUI_Display::SECOND_LEVEL);
                        current_level = Game_Logic::SECOND;
                        ground->clear_field();

                        generate_level(levels::SECOND);
                        display_wrapper->draw_field_only(ground, current_level);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 2){
                        mediator->move_level_choice(GUI_Display::BACK);
                    }

                    mover += 1;
                    break;
                case Command_Wrapper::MOVE_UP:
                    system("clear");
                    std::cout << '\a';
                    display_wrapper->in_game_intro();

                    if ( fmod(fmod(mover, 3) + 3, 3) == 0){
                        mediator->move_level_choice(GUI_Display::SECOND_LEVEL);

                        current_level = Game_Logic::SECOND;
                        ground->clear_field();

                        generate_level(levels::SECOND);
                        display_wrapper->draw_field_only(ground, current_level);
                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 1){
                        mediator->move_level_choice(GUI_Display::BACK);

                    }else if ( fmod(fmod(mover, 3) + 3, 3) == 2){
                        mediator->move_level_choice(GUI_Display::FIRST_LEVEL);
                        current_level = Game_Logic::FIRST;
                        ground->clear_field();

                        generate_level(levels::FIRST);
                        display_wrapper->draw_field_only(ground, current_level);

                    }

                    mover -= 1;
                    break;
                case Command_Wrapper::ENTER:
                    system("clear");
                    display_wrapper->in_game_intro();

                    switch (mediator->get_menu_type()){
                        case GUI_Display::FIRST_LEVEL:
                            system("killall afplay");
                            ground->set_level(1);
                            mediator->set_field(ground);


                            Game_Logic::start_new_game();
                            break;
                        case GUI_Display::SECOND_LEVEL:
                            system("killall afplay");
                            ground->set_level(2);
                            mediator->set_field(ground);


                            Game_Logic::start_new_game();
                            break;
                        case GUI_Display::BACK:
                            mediator->move_menu(GUI_Display::NEW_GAME);
                            display_wrapper->print_devil(TAB);
                            end_choice = true;
                            break;
                    }
                default:
                    break;
            }
        }
    }
}





