#include "submarino.h"

submarino::submarino():barco(){}
submarino::submarino(int POSX, int POSY, char OR):barco(POSX, POSY, OR){
    addName(this->nombre, this->HP);
}

void submarino::danio(int coorX, int coorY){
    int auxi;
    int tam;
    switch(this->LOR()){
    case 'V':
        auxi = this->POSX();
        tam = this->size();
        if(auxi+tam-coorX == 2) this->setHP();
        else this->golpe(coorX, coorY);
        break;
    case 'H':
        auxi = this->POSY();
        tam = this->size();
        if(auxi+tam-coorY == 2) this->setHP();
        else this->golpe(coorX, coorY);
        break;
    }
}

bool submarino::muerto(){
    return this->EsMuerto();
}
