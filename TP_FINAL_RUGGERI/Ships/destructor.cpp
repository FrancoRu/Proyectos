<<<<<<< HEAD
#include "destructor.h"

destructor::destructor():barco(){}
destructor::destructor(int POSX, int POSY, char OR):barco(POSX, POSY, OR){
    addName(this->nombre, this->HP);
}

void destructor::danio(int coorX, int coorY){
    this->golpe(coorX, coorY);
}

bool destructor::muerto(){
    return this->EsMuerto();
}

destructor::~destructor(){}
=======
#include "destructor.h"

destructor::destructor():barco(){}
destructor::destructor(int POSX, int POSY, char OR):barco(POSX, POSY, OR){
    addName(this->nombre, this->HP);
}

void destructor::danio(int coorX, int coorY){
    this->golpe(coorX, coorY);
}

bool destructor::muerto(){
    return this->EsMuerto();
}

destructor::~destructor(){}
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
