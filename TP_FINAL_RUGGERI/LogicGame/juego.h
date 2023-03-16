#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "LogicGame/mapa.h"
#include "LogicGame/gestor.h"
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
struct ShipsSave{
    char Barco;
    int Posx;
    int Posy;
    char Ori;
};
typedef struct ShipsSave NShips;
struct PosPlayer{
    int x;
    int y;
};
typedef struct PosPlayer Npos;
struct SaveGame{
    char nombre[100];
    int  SizeMap;
    int  CantShip;
};
typedef struct SaveGame NSave;
class Inicio;
class juego
{
private:
    //int cont;
    int ships;
    int BarcosPuestos;
    int contShip1;
    int contShip2;
    mapa Player1;
    mapa Player2;
    gestor listadoPlayer1;
    gestor listadoPlayer2;
    char* nombrePartida;
    bool impact;
    std::map<std::pair<int,int>, std::pair<char,int>> map;
    std::map<std::pair<int,int>, std::pair<char,int>> map2;
public:
    juego();
    juego(std::string, int, int);
    void Saveinf(std::string, int, int);
    void generateMaps(std::string, int, bool);
    char tipo(int);
    int tipoJuego();
    void battle(int, int, bool, bool = true);
    mapa &Pl(bool);
    gestor &Listado(bool);
    bool ingreso(int para, std::string Barco = "" ,int Coorx = 0, int CoorY = 0,char orientacion = '\0');
    bool ingresoShips2(gestor &listado, mapa &Map, gestor &listado2, mapa &Map2,int CantBarcos,int para, std::string Barco = "" ,int Coorx = 0, int CoorY = 0,char orientacion = '\0');
    void ingresoCarga(int coorX, int coorY, char Ori, char Bar, bool state);
    void generate(int, int, char, char);
    void generate2(int, int, char, char);
    void generacionArchivo();
    void GeneracionMapa();
    char* getnombrePartida() const;
    void setnombrePartida(std::string);
    bool getimpact();
    void setContadores(bool = true, int = 0);
    int getContadores(bool);
    ~juego();
};

#endif // JUEGO_H
