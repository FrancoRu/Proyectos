<<<<<<< HEAD
#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H
#include "barco.h"

class portaAviones:public barco{
private:
    std::string nombre = "portaavion";
    int HP = 5;
public:
    portaAviones();
    portaAviones(int, int, char);
    void danio(int, int);
    bool muerto();
    ~portaAviones(){};
};

#endif // PORTAAVIONES_H
=======
#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H
#include "barco.h"

class portaAviones:public barco{
private:
    std::string nombre = "portaavion";
    int HP = 5;
public:
    portaAviones();
    portaAviones(int, int, char);
    void danio(int, int);
    bool muerto();
    ~portaAviones(){};
};

#endif // PORTAAVIONES_H
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
