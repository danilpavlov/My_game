#include "Field.h"
#include "Cell.h"
#include <iostream>
#include <vector>
#define TAB_PUSH std::cout << "  ";
#define MARIO_TAB ""

Field::Field(int x, int y):x(x), y(y) {
//    message = new Message;
}

Field::Field(){
    x = 75;     // Аргументы по умолчанию
    y = 24;
//    message = new Message;
}


void Field::create_2D_field() {
    //  Данный метод создан для того, чтобы сгенерировать игровой поле, путем заполнения 2Д вектора ПУСТЫМИ клетками
//    Notify(Message::FIELD, Message::NEW_FIELD_GENERATED);

    for (int i = 0; i < y; i++){
        std::vector<Cell> tmp;  // Создаем вектор, определяющий количество столбцов

        for (int j = 0; j < x; j++){

            Cell tmp_cell(Cell::EMPTY, Cell::NO_EVENT);  // Делаем клетку ПУСТОЙ
            tmp.push_back(tmp_cell);    // Заносим клетку в вектор

        }
        field_2d.push_back(tmp);    // Заносим вектор в 2Д вектор (поле)
    }

}

std::vector<std::vector<Cell> > Field::get_field() {
    return field_2d;
}


void Field::set_field(std::vector<std::vector<Cell> > new_field) {
    field_2d = new_field;
}

int Field::count_enemies() {
    int enemies_amount = 0;

    for (int i = 0; i < y; i++){

        for (int j = 0; j < x; j++){
            if (field_2d[i][j].get_state() == Cell::ENEMY){
                enemies_amount += 1;
            }
        }
    }
    return enemies_amount;
}

Field::Field(const Field & obj) {
    y = obj.y;
    x = obj.x;
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    for (int i = 0; i <= y + 1; i++)
    {
        std::vector<Cell> tmp;
        for (int j = 0; j <= x + 1; j++)
        {
            if (i == 0 && j == 0){

                hero->set_hero_position(Singleton_Hero::x, 0);  // Определяем позиции X и Y у героя
                hero->set_hero_position(Singleton_Hero::y, 0);

                Cell tmp_cell(Cell::HERO, Cell::NO_EVENT);  // Делаем клетку ГЕРОЕМ
                tmp.push_back(tmp_cell);    // Заносим клетку в вектор
            }else {
                Cell tmp_cell(Cell::EMPTY, Cell::NO_EVENT);  // Делаем клетку ПУСТОЙ
                tmp.push_back(tmp_cell);    // Заносим клетку в вектор
            }

        }
        field_2d.push_back(tmp);
    }
}

Field &Field::operator=(const Field &) {
    for (auto row : this->field_2d) {
        this->field_2d.clear();
    }
    Singleton_Hero* hero = Singleton_Hero::getInstance();
    field_2d.clear();
    for (int i = 0; i <= y + 1; i++)
    {
        std::vector<Cell> tmp;
        for (int j = 0; j <= x + 1; j++)
        {
                Cell tmp_cell(Cell::EMPTY, Cell::NO_EVENT);  // Делаем клетку ПУСТОЙ
                tmp.push_back(tmp_cell);    // Заносим клетку в вектор

        }
        field_2d.push_back(tmp);
    }
    return *this;
}

Field::Field(Field && obj) {
    std::swap(this->y, obj.y);
    std::swap(this->x, obj.x);
    std::swap(this->field_2d, obj.field_2d);
}

Field &Field::operator=(Field && obj) {
    if (this != &obj) {
        std::swap(this->y, obj.y);
        std::swap(this->x, obj.x);
        std::swap(this->field_2d, obj.field_2d);
    }
    return *this;
}

void Field::clear_field() {
    for (int i = 0; i < y; i++){

        for (int j = 0; j < x; j++){

            field_2d[i][j].set_state(Cell::EMPTY);
            field_2d[i][j].set_event(Cell::NO_EVENT);

        }
    }


}

void Field::set_level(int new_level) {
    level = new_level;
}




















