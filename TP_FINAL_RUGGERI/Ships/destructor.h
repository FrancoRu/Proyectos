#ifndef DESTRUCTOR_H
#define DESTRUCTOR_H
#include "barco.h"

class destructor:public barco
{
private:
    std::string nombre = "destructor";
    int HP = 4;
public:
    destructor();
    destructor(int, int, char);
    void danio(int, int);
    bool muerto();
    ~destructor();
};

#endif // DESTRUCTOR_H
