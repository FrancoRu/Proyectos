#ifndef BARCO_H
#define BARCO_H
#include <iostream>


class barco{
private:
    std::string nombre;
    int health;
    int posX;
    int posY;
    char Lorientacion;
    int cant;
public:
    barco (int, int, char);
    barco();
    virtual void danio(int, int)=0;
    virtual bool muerto()=0;
    void golpe(int, int);
    bool EsMuerto();
    int POSX();
    int POSY();
    char LOR();
    int size();
    void setCoordenadas(int, int, char);
    bool coordenadas(int, int);
    void addName(std::string, int);
    void setHP();
    std::string getNombre();
    ~barco();
    void mostrarVector();
};

#endif // BARCO_H
