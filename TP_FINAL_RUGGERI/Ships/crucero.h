<<<<<<< HEAD
#ifndef CRUCERO_H
#define CRUCERO_H
#include "barco.h"
class crucero:public barco
{
private:
    std::string nombre = "crucero";
    int HP = 3;
public:
    crucero();
    crucero(int, int, char);
    void danio(int, int);
    bool muerto();
    ~crucero();
};

#endif // CRUCERO_H
=======
#ifndef CRUCERO_H
#define CRUCERO_H
#include "barco.h"
class crucero:public barco
{
private:
    std::string nombre = "crucero";
    int HP = 3;
public:
    crucero();
    crucero(int, int, char);
    void danio(int, int);
    bool muerto();
    ~crucero();
};

#endif // CRUCERO_H
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
