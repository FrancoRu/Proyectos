#include "mapa.h"
int mapa::pruebaBarco()
{
    return this->pruebaBarcos;
}

//void mapa::setContMovEsp(int contador){
    //this->contMov = contador;
//}

mapa::mapa(){
    this-> TamNxN = 0;
    this-> cantBarcos = 0;
    this-> life = true;
    this->pruebaBarcos = 0;
}

void mapa::SetMapa(int X, std::string name){
    char** aux2 = new char*[X];
    int** auxiliar = new int*[X];
    for(int i=0; i<X; i++){
        aux2[i] = new char[X];
        auxiliar[i] = new int[X];
    }
    for(int i=0; i<X; i++){
        for(int j=0; j<X; j++){
            aux2[i][j] = '-';
            auxiliar[i][j] = 0;
            this->MovPo.push_back(std::pair(i+1,j+1));
            this->MovIA.push_back(std::pair(i+1,j+1));
        }
    }
    this->mapPrueba = auxiliar;
    this->nombre = name;
    this->mapGame = aux2;
    this->TamNxN = X;
    this->ContJugadas = 0;
}



bool mapa::CombatRoom(mapa &enemy, gestor &listado,int coorX, int coorY,bool state){
    bool band = false;
    this->jugadas.push_back(std::pair(coorX, coorY));
    this->ContJugadas++;
    if(pruebadisparo(coorX, coorY, enemy)){
        modificacionGame(coorX, coorY, 'X');
        if(enemy.search(coorX, coorY, listado))band = true;
    }else modificacionGame(coorX, coorY, 'O');
    if(listado.sizeShip()==0){
        enemy.life = false;
    }
    if(state){
       for(int i=0; i<listado.sizeShip(); i++){
          if(listado.showList(i)->size() == 1){
             move(listado.showList(i), enemy);
          }
       }
    }
    for(int i=0; i<tamanio(); i++){
        for(int j=0; j<tamanio(); j++){
            if(enemy.mapi2()[i][j] == 9){
                modificacionGame(i+1,j+1,'X');
            }
        }
    }
    return band;
}


bool mapa::addShips(barco *Barco, gestor& Gestor){
     if(verify(Barco)){
        add(Barco);
        Gestor.addBarcos(Barco);
        this->pruebaBarcos++;
        return true;
     } else return false;
}
bool mapa::verify(barco *Barco){
    int cont = 0;
    int max = this->TamNxN;
    int x = Barco->POSX()-1;
    int y = Barco->POSY()-1;
    int tam = Barco->size();
    char ori = Barco->LOR();
    switch(ori){
       case 'V':
           if(x+tam<=max){
               for(int i=x-1; i<x+tam+1; i++){
                   if((i>=0)&&(i<max)){
                       for(int j = y-1; j<y+2; j++){
                            if(j<0||j>max-1) cont++;
                            else{
                               if(this->mapPrueba[i][j]==0)cont++;
                               else cont-=tam;
                            }
                        }
                    }else cont+=3;
                }
            }
        break;
        case 'H':
        if(y+tam<=max){
                for(int i=y-1; i<y+tam+1; i++){
                    if((i>=0)&&(i<max)){
                        for(int j = x-1; j<x+2; j++){
                            if(j<0||j>max-1)cont++;
                            else{
                                if(this->mapPrueba[j][i]==0)cont++;
                                else cont-=tam;
                            }
                        }
                    }else cont+=3;
                }
            }
        break;
    }
    return cont==(tam+2)*3;
}

void mapa::add(barco *Barco){
    int  type = Barco->size();
    for(int i=0; i<Barco->size(); i++){
        if(Barco->LOR() == 'V')modificacionPlay2(Barco->POSX()+i, Barco->POSY(), type);
        else modificacionPlay2(Barco->POSX(), Barco->POSY()+i, type);
    }
    this->cantBarcos++;

}
void mapa::modificacionPlay2(int posx, int posy,int tam){
    this->mapPrueba[posx-1][posy-1] = tam;
}
bool mapa::search(int coorX, int coorY,gestor& listado){
    bool band = false;
        for(int i=0; i<listado.sizeShip(); i++){
            if(listado.showList(i)->coordenadas(coorX,coorY)){
                   listado.showList(i)->danio(coorX, coorY);
                   if(!listado.showList(i)->muerto()){
                       if(listado.showList(i)->size()==1){
                           this->Mov.push_back(std::pair(coorX,coorY));
                       }
                       destroyed(listado.showList(i));
                       listado.deleteShip(i);

                   }
                   i = listado.sizeShip()+1;
                   band =  true;
            }
        }
    return band;
}

char **mapa::mapi(){
    return this->mapGame;
}

int **mapa::mapi2(){
    return this->mapPrueba;
}


std::vector<std::pair<int, int> > mapa::getVec(bool state){
    return (state) ? this->jugadas : this->Mov;
}

void mapa::destroyed(barco * Ships){
    int x = Ships->POSX();
    int y = Ships->POSY();
    char ori = Ships->LOR();
    int tam = Ships->size();
    switch(ori){
    case 'V':
        for(int i= x; i<x+tam; i++){
            modificacionPlay2(i, y, 9);
        }
        break;
    case 'H':
        for(int i = y; i<y+tam; i++){
            modificacionPlay2(x, i, 9);
        }
        break;
    }
}

void mapa::move(barco* Lancha, mapa& enemy){
    int rango;
    int antX, antY;
    int contExit = 0;
    int i=0;
    genNuevoVector(enemy);
    std::pair<int, int> jug;
    char Lori = Lancha->LOR();
    antX = Lancha->POSX();
    antY = Lancha->POSY();
    rango = enemy.rangoMovimiento(true);
    bool band = false;
    do{
       i = rand()%rango;
       jug = enemy.getMovimiento(i, true);
       if(this->mapGame[jug.first-1][jug.second-1]=='-'&&enemy.mapi2()[jug.first-1][jug.second-1]<1){
           Lancha->setCoordenadas(jug.first, jug.second, Lori);
           if(enemy.verify(Lancha)) band = true;
       }
       contExit++;
    }while(!band&&contExit<1000000);
    if(band){
        enemy.modificacionPlay2(antX, antY, 0);
        enemy.modificacionPlay2(jug.first, jug.second, 1);
    }else{
        Lancha->setCoordenadas(antX, antY, Lori);
        enemy.modificacionPlay2(antX, antY, 1);
    }
}


void mapa::modificacionGame(int coorX, int coorY, char car){
    this->mapGame[coorX-1][coorY-1] = car;
}

bool mapa::looser(){
    return this->life;
}
int mapa::cantship(){
    return this->cantBarcos;
}

bool mapa::pruebadisparo(int coorX, int coorY, mapa Enemy){
    if((coorX>0&&coorX<=this->TamNxN)&&(coorY>0&&coorY<=this->TamNxN)) return Enemy.mapi2()[coorX-1][coorY-1]!=0;
    else return false;
}

int &mapa::getJugadas(){
    return this->ContJugadas;
}

void mapa::deletevec(bool state){
    state ? this->jugadas.clear() : this->Mov.clear();
}
std::vector<std::pair<int, int> > mapa::getMovPo(bool state){
    return state ? this->MovPo : this->MovIA;
}

int mapa::rangoMovimiento(bool state){
    return state ? this->MovPo.size() : this->MovIA.size();
}

void mapa::DelMovimientoVec(int indice, bool state){
    state ? this->MovPo.erase( this->MovPo.begin()+indice) :
            this->MovIA.erase(this->MovIA.begin()+indice);
}

std::pair<int, int> mapa::getMovimiento(int indice, bool state){
    std::pair<int, int> x;
    state ? x = this->MovPo[indice] : x = this->MovIA[indice];
    return x;
}

void mapa::genNuevoVector(mapa &enemy){
    enemy.getVec(true).clear();
    int MAX = this->TamNxN;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            if(this->mapGame[i][j]=='-'){
                enemy.getVec(true).push_back(std::make_pair(i+1,j+1));
            }
        }
    }
}

void mapa::Eliminarmapas(){
    for(int i=0; i<this->TamNxN; i++){
        delete [] this->mapGame[i];
        delete [] this->mapPrueba[i];
    }
    delete [] this->mapPrueba;
    delete [] this->mapGame;
}

std::string mapa::getName()
{
    return this->nombre;
}


int mapa::tamanio(){
    return this->TamNxN;
}
mapa::~mapa(){}
