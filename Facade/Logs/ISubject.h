//
// Created by Даниил Павлов on 29.09.2022.
//

#ifndef MY_GAME_ISUBJECT_H
#define MY_GAME_ISUBJECT_H
#include "IObserver.h"
#include "Message/Message.h"
#include "Message/Message Levels/Event_Message.h"
#include "Message/Message Levels/Field_Message.h"
#include "Message/Message Levels/Hero_Moves_Message.h"
#include "Message/Message Levels/Warning_Message.h"
#include <vector>

class ISubject {
public:
    virtual ~ISubject(){};


    virtual void Attach(IObserver* observer) = 0;

    virtual void Detach(IObserver* observer) = 0;

protected:
    std::vector <IObserver *> list_observer_;

    void Notify(Message* message, int key);

};


#endif //MY_GAME_ISUBJECT_H
