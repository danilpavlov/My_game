//
// Created by Даниил Павлов on 25.10.2022.
//

#ifndef MY_GAME_CARETAKER_H
#define MY_GAME_CARETAKER_H
#include "Saver.h"
#include <vector>

class Caretaker {
public:
    Caretaker(Saver* new_saver);

    ~Caretaker();

    void backup();
    void load_game(Field* field);

private:
    std::vector <Memento*> mementos_;
    Saver* saver_;
};


#endif //MY_GAME_CARETAKER_H
