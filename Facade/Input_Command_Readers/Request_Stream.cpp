//
// Created by Даниил Павлов on 07.10.2022.
//

#include "Request_Stream.h"
#define tab ""

Request_Stream::Request_Stream() {
    display_adapter = new Display_Wrapper;
    mediator = new Mediator;
    message = new System_Messages;
}



Request_Stream::chosen_stream Request_Stream::request_user() {
    system("clear");

    display_adapter->show_request_file_control();
    mediator->move_request(GUI_Display::NO);
    display_adapter->show_alucard();

    int mover = 0;
    bool quit = false;
    while (!quit) {
        if (kbhit()) {

            switch (getchar()) {

                case 's':
                case 'S':
                    system("clear");
                    std::cout << '\a';

                    display_adapter->static_show_request_file_control();

                    if (fmod(mover, 2) == 0) {
                        mediator->move_request(GUI_Display::YES);
                    } else {
                        mediator->move_request(GUI_Display::NO);
                    }

                    display_adapter->show_alucard();


                    mover += 1;
                    break;
                case 'W':
                case 'w':
                    system("clear");
                    std::cout << '\a';

                    display_adapter->static_show_request_file_control();


                    if (fmod(mover, 2) == 0) {
                        mediator->move_request(GUI_Display::YES);
                    } else {
                        mediator->move_request(GUI_Display::NO);
                    }

                    display_adapter->show_alucard();

                    mover -= 1;
                    break;
                case '\n':
                    system("clear");
                    display_adapter->static_show_request_file_control();

                    switch (mediator->get_menu_type()) {
                        case GUI_Display::YES:
                            Notify(message, System_Messages::FILE_CONTROL);
                            return Request_Stream::FILE;
                        case GUI_Display::NO:
                            Notify(message, System_Messages::STANDART_CONTROL);
                            return Request_Stream::STANDART;
                        default:
                            quit = true;
                            break;
                    }

                default:
                    break;
            }

        }
    }


}

Request_Stream::~Request_Stream() {
    delete mediator;
    delete display_adapter;
}

void Request_Stream::Attach(IObserver *observer) {
    list_observer_.push_back(observer);
}

void Request_Stream::Detach(IObserver *observer) {
    list_observer_.erase(std::remove(list_observer_.begin(), list_observer_.end(), observer), list_observer_.end());
}


