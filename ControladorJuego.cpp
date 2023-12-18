#include "ControladorJuego.h"

ControladorJuego::ControladorJuego(){}

void ControladorJuego::seleccionarJuego(string idJuego){

}

list<DtJuego*> ControladorJuego::listarJuegos(){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    list<Juego*> juegos = mj->listar();

    list<DtJuego*> DtJuegos; 

    list<Juego*>::iterator it; 

    for(it = juegos.begin(); it!=juegos.end(); it++){
        DtJuego* DtJ = new DtJuego((*it)->getIdJuego(), (*it)->getNombre(), (*it)->getPlataforma(), (*it)->getImgLink(), (*it)->getDesc(), (*it)->getExtensionesData(), (*it)->getDirectoriosData());
        DtJuegos.push_back(DtJ);
    }

    return DtJuegos;
}

ControladorJuego::~ControladorJuego(){}