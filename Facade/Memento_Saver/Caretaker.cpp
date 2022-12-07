//
// Created by Даниил Павлов on 25.10.2022.
//

#include "Caretaker.h"

void Caretaker::backup() {
    if (!this->mementos_.empty()){
        mementos_.pop_back();
    } 
    this->mementos_.push_back(this->saver_->save_current_memento());
}

void Caretaker::load_game(Field* field) {
    saver_->restore(mementos_[0], field);
}

Caretaker::~Caretaker() {
    for (auto m : mementos_) delete m;
}

Caretaker::Caretaker(Saver *saver) {
    saver_ = saver;
}






