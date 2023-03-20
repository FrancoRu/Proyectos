#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include "Ships/barco.h"
#include "LogicGame/gestor.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <map>
struct movEsp{
    int posx;
    int posy;
};
typedef struct movEsp NMovEsp;
class juego;
class barco;
class mapa
{
private:
    std::vector<std::pair<int , int>> jugadas;
    std::vector<std::pair<int , int>> Mov;
    std::vector<std::pair<int , int>> MovPo;
    std::vector<std::pair<int , int>> MovIA;
    int ContJugadas;
    int contMov;
    char** mapGame;
    int** mapPrueba;
    std::string nombre;
    int TamNxN;
    bool life;
public:
    mapa();
    void SetMapa(int, std::string);
    bool CombatRoom(mapa&, gestor&,int, int, bool state = true);
    bool addShips(barco*, gestor&);
    bool verify(barco*);
    void add(barco*);
    bool search(int, int,gestor&);
    char** mapi();
    int** mapi2();
    std::vector<std::pair<int , int>>  getVec(bool);
    std::vector<std::pair<int , int>> getMovPo(bool);
    void destroyed(barco*);
    void move(barco*, mapa&);
    int tamanio();
    void modificacionPlay2(int, int, int);
    void modificacionGame(int, int, char);
    std::string getName();
    bool looser();
    bool pruebadisparo(int, int, mapa);
    int &getJugadas();
    void deletevec(bool);
    int rangoMovimiento(bool);
    void DelMovimientoVec(int, bool);
    std::pair<int, int> getMovimiento(int, bool);
    void genNuevoVector(mapa &);
    void Eliminarmapas();
    ~mapa();
};

#endif // MAPA_H
