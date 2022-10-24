//
// Created by Даниил Павлов on 29.09.2022.
//

#include "ISubject.h"

void ISubject::Notify(Message *message, int key) {
    for (int i = 0; i < list_observer_.size(); i++){
        list_observer_[i]->update(message->get_message(key));
    }
}

