

#include "gestor.h"
#include <iostream>
gestor::gestor(){
    this->cantidadBarcos = 0;
}

barco *gestor::verificacion(int ver, int coorx, int coory, char Lori){
    barco* aux;
    switch(ver){
        case 1:
            aux = this->OKportaavion(coorx, coory, Lori);
        break;
    case 2:
        aux = this->OKDestructor(coorx, coory, Lori);
        break;
    case 3:
        aux = this->OKSubmarino(coorx, coory, Lori);
        break;
    case 4:
        aux = this->OKCrucero(coorx, coory, Lori);
        break;
    case 5:
        aux = this->OKlanchaCombat(coorx, coory, Lori);
        break;
    }
    return aux;
}

void gestor::addBarcos(barco *Barco){
    barco* *aux = new barco*[this->cantidadBarcos+1];
    for(int i=0; i<this->cantidadBarcos; i++){
        aux[i] = this->listaDeBarcos[i];
    }
    aux[this->cantidadBarcos] = Barco;
    delete [] this->listaDeBarcos;
    this->listaDeBarcos = aux;
    this->cantidadBarcos++;
}

barco* gestor::showList(int indice){
    return this->listaDeBarcos[indice];
}

void gestor::deleteShip(int indice){
    barco* *aux = new barco*[this->cantidadBarcos-1];
    int j = 0;
    for(int i=0; i<this->cantidadBarcos; i++){
        if(i!=indice){
          aux[j] = this->listaDeBarcos[i];
          j++;
        }
    }
    delete [] this->listaDeBarcos;
    this->listaDeBarcos = aux;
    this->cantidadBarcos--;
}

int gestor::sizeShip(){
    return this->cantidadBarcos;
}

barco* gestor::OKportaavion(int coorx , int coory, char Lori){
    barco* portaavion = new portaAviones(coorx, coory, Lori);
    return portaavion;
}
barco* gestor::OKDestructor(int coorx, int coory, char Lori){
    barco* Destructor = new destructor(coorx, coory, Lori);
    return Destructor;
}
barco* gestor::OKCrucero(int coorx, int coory, char Lori){
    barco* Crucero = new crucero(coorx, coory, Lori);
    return Crucero;
}
barco* gestor::OKSubmarino(int coorx, int coory, char Lori){
    barco* Submarino = new submarino(coorx, coory, Lori);
    return Submarino;
}
barco* gestor::OKlanchaCombat(int coorx, int coory, char Lori){
    barco* lanchadeCombat = new lanchaCom(coorx, coory, Lori);
    return lanchadeCombat;
}

void gestor::Eliminarlistados(){
    for(int i=0; i<this->cantidadBarcos; i++){
        delete this->listaDeBarcos[i];
    }
    delete [] this->listaDeBarcos;
}

gestor::~gestor(){}
