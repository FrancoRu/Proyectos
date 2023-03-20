#include "lanchacom.h"

lanchaCom::lanchaCom():barco(){}
lanchaCom::lanchaCom(int POSX, int POSY, char OR):barco(POSX, POSY, OR){
    addName(this->nombre, this->HP);
}

void lanchaCom::danio(int coorX, int coorY){
    this->golpe(coorX, coorY);
}

bool lanchaCom::muerto(){
    return this->EsMuerto();
}




