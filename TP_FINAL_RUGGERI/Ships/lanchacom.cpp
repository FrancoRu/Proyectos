<<<<<<< HEAD
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




=======
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




>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
