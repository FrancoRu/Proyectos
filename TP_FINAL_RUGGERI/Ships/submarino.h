<<<<<<< HEAD
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
=======
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
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
