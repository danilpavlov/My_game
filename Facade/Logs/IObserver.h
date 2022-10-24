//
// Created by Даниил Павлов on 29.09.2022.
//

#ifndef MY_GAME_IOBSERVER_H
#define MY_GAME_IOBSERVER_H
#include <string>



class IObserver {
public:
    virtual ~IObserver(){};
    virtual void update(std::string message) = 0;
};


#endif //MY_GAME_IOBSERVER_H
