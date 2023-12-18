#include "ControladorJuego.h"

ControladorJuego::ControladorJuego(){}

void ControladorJuego::seleccionarJuego(int idJuego){

}


//Devuelve una lista de todos los juegos almacenados en el sistema
list<DtJuego*> ControladorJuego::listarJuegos(){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    list<Juego*> juegos = mj->listar();

    list<DtJuego*> DtJuegos; 

    list<Juego*>::iterator it; 

    for(it = juegos.begin(); it!=juegos.end(); it++){
        DtJuego* DtJ = new DtJuego((*it)->getIdJuego(), (*it)->getNombre(), (*it)->getPlataforma(), (*it)->getImgLink(), (*it)->getDesc(), (*it)->getArchivosData(), (*it)->getDirectoriosData());
        DtJuegos.push_back(DtJ);
    }

    return DtJuegos;
}

//Recopila datos de un juego a agregar dados por el usuario, y los guarda en el controlador.
void ControladorJuego::recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string>directoriosData){
    this->nombreJuego = nombre;
    this->plataforma = plataforma;
    this->imgLink = imgLink; 
    this->desc = desc;
    this->archivosData = archivosData;
    this->directoriosData = directoriosData;
}


void ControladorJuego::agregarJuego(){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

}

ControladorJuego::~ControladorJuego(){}