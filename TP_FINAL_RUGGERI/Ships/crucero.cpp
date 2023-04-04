<<<<<<< HEAD
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
=======
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
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
