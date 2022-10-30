//
// Created by Даниил Павлов on 29.10.2022.
//

#ifndef MY_GAME_DRUG_H
#define MY_GAME_DRUG_H
#include "../Interfaces/IConsumable.h"

class Drug : public IConsumable{
public:
    void use() override;
    std::string get_icon() override;
    bool is_empty() override;
};


#endif //MY_GAME_DRUG_H
