//
// Created by Даниил Павлов on 30.10.2022.
//

#ifndef MY_GAME_NO_EQUIPMENT_H
#define MY_GAME_NO_EQUIPMENT_H
#include "../Interfaces/IEquipment.h"

class No_Equipment : public IEquipment{
public:
    void put_on() override;
    std::string get_icon() override;
    bool is_empty() override;
};


#endif //MY_GAME_NO_EQUIPMENT_H
