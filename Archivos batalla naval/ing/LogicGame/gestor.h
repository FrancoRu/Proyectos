#ifndef GESTOR_H
#define GESTOR_H
#include "Ships/barco.h"
#include "Ships/crucero.h"
#include "Ships/destructor.h"
#include "Ships/lanchacom.h"
#include "Ships/portaaviones.h"
#include "Ships/submarino.h"
class gestor{
private:
    barco* *listaDeBarcos = nullptr;
    int cantidadBarcos;
public:
    gestor();
    barco* verificacion(int, int, int, char);
    void addBarcos(barco*);
    barco* showList(int);
    void deleteShip(int);
    int sizeShip();
    int listaBarcoSize();
    barco* OKportaavion(int, int, char);
    barco* OKDestructor(int, int, char);
    barco* OKSubmarino(int, int, char);
    barco* OKCrucero(int, int, char);
    barco* OKlanchaCombat(int, int, char);
    void Eliminarlistados();
    ~gestor();
};

#endif // GESTOR_H
