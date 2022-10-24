//
// Created by Даниил Павлов on 07.10.2022.
//

#ifndef MY_GAME_REQUEST_STREAM_H
#define MY_GAME_REQUEST_STREAM_H
#include <iostream>
#include "../mediator/Mediator.h"
#include "../Display/Display_Wrapper.h"
#include "../../kbhit.h"
#include "Readers/Input_Stream_Reader.h"
#include "Readers/File_Stream_Reader.h"

#include "../Logs/Message/Message.h"
#include "../Logs/Message/Message Levels/System_Messages.h"


class Request_Stream : ISubject{
public:
    enum chosen_stream{STANDART, FILE};

    Request_Stream();
    chosen_stream request_user();

    ~Request_Stream();
    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;
private:
    Display_Wrapper* display_adapter;
    Mediator* mediator;
    Message* message;

};


#endif //MY_GAME_REQUEST_STREAM_H
