#include "crucero.h"

crucero::crucero():barco(){}

crucero::crucero(int POSX, int POSY, char OR):barco(POSX, POSY, OR){
    addName(this->nombre, this->HP);
}

void crucero::danio(int coorX, int coorY){
    this->golpe(coorX, coorY);
}

bool crucero::muerto(){
    return this->EsMuerto();
}

crucero::~crucero(){}
