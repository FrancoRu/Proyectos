#include "juego.h"
juego::juego(){}

juego::juego(std::string nombre, int SizeMap, int Ships){
    generateMaps(nombre, SizeMap, true);
    generateMaps("Maquina", SizeMap, false);
    this->ships = Ships;
    this->BarcosPuestos = 0;
    this->impact = false;
    Saveinf(nombre, SizeMap, Ships);

}

void juego::Saveinf(std::string name, int tam, int cShips){
    NSave Jugador;
    std::fstream archi("saveGame/juego.bin", std::ios::out|std::ios::trunc|std::ios::binary);
    std::fstream archi2("juego.txt", std::ios::out|std::ios::trunc);
    if(archi.is_open()){
        strcpy_s(Jugador.nombre, name.c_str());
        Jugador.CantShip = cShips;
        Jugador.SizeMap = tam;
        archi.write(reinterpret_cast<char*>(&Jugador), sizeof(NSave));
        archi2<<"Nombre: "<<name<<std::endl;
        archi2<<"Tamaño: "<<tam<<std::endl;
        archi2<<"Cantidad de barcos: "<<cShips<<std::endl;
    }
    archi.close();
    archi2.close();
}

void juego::generateMaps(std::string nombre , int SizeMap, bool state){
    (state) ? Player1.SetMapa(SizeMap, nombre) : Player2.SetMapa(SizeMap, nombre);
}
bool juego::ingresoShips2(gestor &listado, mapa &Map, gestor &listado2, mapa &Map2,
     int CantBarcos,int para, std::string Barco, int Coorx, int CoorY, char orientacion)
{
    bool bandera = false;
    char Orientacion;
    int character;
    int coordenadaX;
    int coordenadaY;
    int opcion;
    if(para == 0){
        switch(Barco[0]){
        case 'P' : opcion = 1;
            break;
        case 'D' : opcion = 2;
            break;
        case 'S' : opcion = 3;
            break;
        case 'C': opcion = 4;
            break;
        case 'L': opcion = 5;
            break;
        }
        if(Map.addShips(listado.verificacion(opcion, Coorx, CoorY, orientacion), listado)){
            generate(Coorx, CoorY, orientacion, Barco[0]);
            generate2(Coorx, CoorY, orientacion, Barco[0]);
            while(!bandera){
                coordenadaX = 1+rand()%Map.tamanio();
                coordenadaY = 1+rand()%Map.tamanio();
                character = 1+rand()%1000;
                (character%2==0) ? Orientacion = 'V': Orientacion = 'H';
                if(Map2.addShips(listado2.verificacion(opcion, coordenadaX, coordenadaY, orientacion), listado2)){
                    generate(coordenadaX, coordenadaY, Orientacion, Barco[0]);
                    generate2(coordenadaX, coordenadaY, Orientacion, Barco[0]);
                    bandera = true;
                }
            }
        }
    }else{
        int j = 0, i = this->BarcosPuestos;
        if(para == 1){
            while(i<CantBarcos&&j<Map.tamanio()*100){
                opcion = 1+rand()%(5);
                coordenadaX = 1+rand()%Map.tamanio();
                coordenadaY = 1+rand()%Map.tamanio();
                character = 1+rand()%1000;
                (character%2==0) ? Orientacion = 'V': Orientacion = 'H';
                if(Map.addShips(listado.verificacion(opcion, coordenadaX, coordenadaY, Orientacion), listado)){
                    generate(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                    generate2(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                    coordenadaX = 1+rand()%Map.tamanio();
                    coordenadaY = 1+rand()%Map.tamanio();
                    while(!Map2.addShips(listado2.verificacion(opcion, coordenadaX, coordenadaY, Orientacion), listado2)){
                        coordenadaX = 1+rand()%Map.tamanio();
                        coordenadaY = 1+rand()%Map.tamanio();
                        character = 1+rand()%1000;
                        (character%2==0) ? Orientacion = 'V': Orientacion = 'H';
                    }
                    generate(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                    generate2(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                    i++;
                }
                j++;
            }
        }else if(para == 2){
            switch(Barco[0]){
            case 'P' : opcion = 1;
                break;
            case 'D' : opcion = 2;
                break;
            case 'S' : opcion = 3;
                break;
            case 'C': opcion = 4;
                break;
            case 'L': opcion = 5;
                break;
            }
            while(!bandera){
                coordenadaX = 1+rand()%Map.tamanio();
                coordenadaY = 1+rand()%Map.tamanio();
                character = 1+rand()%1000;
                (character%2==0) ? Orientacion = 'V': Orientacion = 'H';
                if(Map.addShips(listado.verificacion(opcion, coordenadaX, coordenadaY, Orientacion), listado)){
                    generate(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                    generate2(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                    while(!bandera){
                        coordenadaX = 1+rand()%Map.tamanio();
                        coordenadaY = 1+rand()%Map.tamanio();
                        character = 1+rand()%1000;
                        (character%2==0) ? Orientacion = 'V': Orientacion = 'H';
                        if(Map2.addShips(listado2.verificacion(opcion, coordenadaX, coordenadaY, Orientacion), listado2)){
                            generate(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                            generate2(coordenadaX, coordenadaY, Orientacion, tipo(opcion));
                            bandera = true;
                        }
                    }
                }
            }
        }
    }
    return bandera;
}

void juego::ingresoCarga(int coorX, int coorY, char Ori, char Bar, bool state){
   int opcion;
   switch(Bar){
   case 'P' : opcion = 1;
       break;
   case 'D' : opcion = 2;
       break;
   case 'S' : opcion = 3;
       break;
   case 'C': opcion = 4;
       break;
   case 'L': opcion = 5;
       break;
   }
   generate(coorX, coorY, Ori, Bar);
   generate2(coorX, coorY, Ori, Bar);
   barco* nuevo = Listado(state).verificacion(opcion, coorX, coorY, Ori);
   Pl(state).add(nuevo);
   Listado(state).addBarcos(nuevo);
}

void juego::generate(int x, int y, char Ori, char Bar){
    std::fstream archi("saveGame/juego.bin", std::ios::out|std::ios::app|std::ios::binary);
    NShips posiciones;
    if(archi.is_open()){
        posiciones.Posx = x;
        posiciones.Posy = y;
        posiciones.Barco = Bar;
        posiciones.Ori = Ori;
        archi.write(reinterpret_cast<char*>(&posiciones), sizeof(NShips));
    }
    archi.close();
}

void juego::generate2(int x, int y, char Ori, char Bar){
    std::fstream archi("juego.txt", std::ios::out|std::ios::app);
    if(archi.is_open()){
        archi<<"Posicion X: "<<x<<std::endl;
        archi<<"Posicion Y: "<<y<<std::endl;
        archi<<"Orientacion: "<<Ori<<std::endl;
        archi<<"Barco: "<<Bar<<std::endl;
    }
    archi.close();
}

void juego::GeneracionMapa(){
    int tam = this->Player1.tamanio();
    char** mapG = this->Player1.mapi();
    int** mapP = this->Player1.mapi2();
    char** mapG2 = this->Player2.mapi();
    int** mapP2 = this->Player2.mapi2();
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            this->map[std::pair(i+1, j+1)] = std::pair(mapG[i][j], mapP[i][j]);
            this->map2[std::pair(i+1, j+1)] = std::pair(mapG2[i][j], mapP2[i][j]);
        }
    }
    generacionArchivo();
}

bool juego::getimpact(){
    return this->impact;
}

void juego::setContadores(bool state,int tam){
    state ? this->contShip1 = tam : this->contShip2 = tam;
}

int juego::getContadores(bool state){
    return state ? this->contShip1 : this->contShip2;
}

void juego::generacionArchivo(){
    std::ofstream archi("MovEsp.bin", std::ios::out|std::ios::binary);
    std::fstream archi2("jugadas.bin",std::ios::out|std::ios::trunc|std::ios::binary);
    std::ofstream archi3("RevisionMovGuardados.txt", std::ios::out|std::ios::binary);
    std::ofstream archi4("LanchasDestruidas.bin", std::ios::out|std::ios::trunc|std::ios::binary);
    int contador = Pl(true).getJugadas()+Pl(false).getJugadas();
    archi2.write(reinterpret_cast<char*>(&contador), sizeof(int));
    archi3<<"Jugadas: "<<contador<<std::endl;
    int cont = 0;
    Npos posicionAc;
    if(archi.is_open()){
        archi3<<"Movimientos Player: "<<std::endl;
        for(auto it : this->map){
            if(it.second.second==1){
                posicionAc.x = it.first.first;
                posicionAc.y = it.first.second;
                archi.write(reinterpret_cast<char*>(&posicionAc), sizeof(Npos));
                cont++;
                archi3<<"X: "<<posicionAc.x<<" -> Y: "<<posicionAc.y<<std::endl;
            }
        }
        archi3<<"Cantidad de lanchas aliadas: "<<cont<<std::endl;
        archi2.write(reinterpret_cast<char*>(&cont), sizeof(int));
        cont = 0;
        archi3<<"Movimientos Maquinas: "<<std::endl;
        for(auto it : this->map2){
            if(it.second.second==1){
                posicionAc.x = it.first.first;
                posicionAc.y = it.first.second;
                archi.write(reinterpret_cast<char*>(&posicionAc), sizeof(Npos));
                cont++;
                archi3<<"X: "<<posicionAc.x<<" -> Y: "<<posicionAc.y<<std::endl;
            }
        }
        archi3<<"Cantidad de lanchas enemigas: "<<cont<<std::endl;

        archi2.write(reinterpret_cast<char*>(&cont), sizeof(int));
    }
    cont = 0;
    if(archi4.is_open()){
        for(auto it: this->Pl(false).getVec(false)){
            posicionAc.x = it.first;
            posicionAc.y = it.second;
            archi4.write(reinterpret_cast<char*>(&posicionAc), sizeof(Npos));
            cont++;
        }
        archi2.write(reinterpret_cast<char*>(&cont), sizeof(int));
        cont = 0;
        for(auto it: this->Pl(true).getVec(false)){
            posicionAc.x = it.first;
            posicionAc.y = it.second;
            archi4.write(reinterpret_cast<char*>(&posicionAc), sizeof(Npos));
            cont++;
        }
        archi2.write(reinterpret_cast<char*>(&cont), sizeof(int));
    }
    archi4.close();
    archi2.close();
    archi.close();
    archi3.close();
}

char juego::tipo(int tipo){
    char aux = '\0';
    switch(tipo){
    case 1: aux = 'P';
        break;
    case 2: aux = 'D';
        break;
    case 3: aux = 'S';
        break;
    case 4: aux = 'C';
        break;
    case 5: aux = 'L';
        break;
    }
    return aux;
}

void juego::battle(int coorx, int coory, bool state, bool esp){
    this->impact = false;
    setContadores(!state, Listado(!state).sizeShip());
    Pl(state).CombatRoom(Pl(!state), Listado(!state), coorx, coory, esp);
    if(getContadores(!state)== Listado(!state).sizeShip()+1){
        this->impact = true;
    }
}

mapa &juego::Pl(bool state){
    return (state) ? this->Player1:this->Player2;
}

gestor &juego::Listado(bool state){
    return (state) ? this->listadoPlayer1 : this->listadoPlayer2;
}

bool juego::ingreso(int para, std::string Barco,int Coorx, int CoorY ,char orientacion){
    bool band = false;
    if(ingresoShips2(this->listadoPlayer1, this->Player1, this->listadoPlayer2, this->Player2, ships, para, Barco, Coorx, CoorY, orientacion)){
        this->BarcosPuestos++;
        band = true;
    }
    return band;
}
juego::~juego(){
    this->Player1.Eliminarmapas();
    this->Player2.Eliminarmapas();
    this->listadoPlayer1.Eliminarlistados();
    this->listadoPlayer2.Eliminarlistados();
}

