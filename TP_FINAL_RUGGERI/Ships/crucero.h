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
