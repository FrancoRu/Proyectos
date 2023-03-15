#include "barco.h"
barco::barco(){}

barco::barco( int POSX, int POSY, char ORI){
    posX = POSX;
    posY = POSY;
    Lorientacion = ORI;
}
void barco::addName(std::string _NomBarco, int _HP){
    this->nombre = _NomBarco;
    this->health = _HP;
    this->cant = _HP;
}
bool barco::EsMuerto(){
    return this->health > 0;
}

int barco::POSX(){
    return this->posX;
}

int barco::POSY(){
    return this->posY;
}

char barco::LOR(){
    return this->Lorientacion;
}

int barco::size(){
    return this->cant;
}

void barco::setCoordenadas(int coorX, int coorY, char Lori){
    this->posX = coorX;
    this->posY = coorY;
    this->Lorientacion = Lori;
}

void barco::golpe(int coorX, int coorY){
    int aux;
    switch(this->Lorientacion){
    case 'V':
            aux = this->posX+this->cant-coorX;
            if(aux>0&&aux<6 ) this->health--;
        break;
    case 'H':
            aux = this->posY+this->cant-coorY;
            if(aux>0&&aux<6) this->health--;
        break;
    }
}


bool barco::coordenadas(int coorX, int coorY){
       switch(this->Lorientacion){
       case 'V':
           if(coorY==this->posY){
               if(this->posX+this->cant-coorX>0){//this->posX+this->cant-coorX>0
                   return  true;
               }else{
                   return false;
               }
           }else{
               return  false;
           }
           break;
       case 'H':
           if(coorX == this->posX){
               if(this->posY+this->cant-coorY>0){//this->posY+this->cant-coorY>0
                   return true;
               }else{
                   return false;
               }
           }else{
               return false;
           }
            break;
       } 
}

void barco::setHP(){
    this->health-=3;
}

std::string barco::getNombre(){
    return this->nombre;
}

barco::~barco(){}




