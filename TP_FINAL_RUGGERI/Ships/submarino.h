#ifndef SUBMARINO_H
#define SUBMARINO_H
#include "barco.h"

class submarino:public barco{
    std::string nombre = "submarino";
    int HP = 3;
public:
    submarino();
    submarino(int, int, char);
    void danio(int, int);
    bool muerto();
    ~submarino(){};
};

#endif // SUBMARINO_H
