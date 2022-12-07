//
// Created by Даниил Павлов on 26.11.2022.
//

#ifndef MY_GAME_BUFF_TABLE_H
#define MY_GAME_BUFF_TABLE_H
#include "IBuff.h"
#include <vector>

/* Singleton Class of Buff Table, which keeps track of buff states*/
class Buff_Table {
private:
    static Buff_Table* instance;
    std::vector <IBuff*> buffs_;
public:
    static Buff_Table* getInstance();

    void activate_buffs_of_type(IBuff::type some_type);

    void add_buff(IBuff* buff);
    void remove_buff(IBuff::part part_to_remove);

    std::vector<IBuff*> get_buffs();

};


#endif //MY_GAME_BUFF_TABLE_H
