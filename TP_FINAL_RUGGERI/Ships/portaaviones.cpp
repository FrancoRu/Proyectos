#include "portaaviones.h"

portaAviones::portaAviones():barco(){}
portaAviones::portaAviones(int POSX, int POSY, char OR):barco(POSX, POSY, OR){
    addName(this->nombre, this->HP);
}

void portaAviones::danio(int coorX, int coorY){
    this->golpe(coorX, coorY);
}

bool portaAviones::muerto(){
    return this->EsMuerto();
}


