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
