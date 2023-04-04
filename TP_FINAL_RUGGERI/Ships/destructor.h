<<<<<<< HEAD
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
=======
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
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
