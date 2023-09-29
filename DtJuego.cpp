#include "DtJuego.h"


DtJuego::DtJuego(){}

DtJuego::DtJuego(string idJuego, string nombre, string nombreCarpetaGuardado, DtFechaHora* fechaUltAct, string directorioLocal, map<string, PartidaGuardada*> partidasGuardadas){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->nombreCarpetaGuardado = nombreCarpetaGuardado;
    this->fechaUltAct = fechaUltAct;
    this->directorioLocal = directorioLocal;
    this->partidasGuardadas = partidasGuardadas;
}

string DtJuego::getIdJuego(){
    return this->idJuego;
}

string DtJuego::getNombre(){
    return this->nombre;
}

string DtJuego::getNombreCarpetaGuardado(){
    return this->nombreCarpetaGuardado;
}

DtFechaHora* DtJuego::getFechaUltAct(){
    return this->fechaUltAct;
}

string DtJuego::getDirectorioLocal(){
    return this->directorioLocal;
}

EnumPlataforma DtJuego::getPlataforma(){
    return this->plataforma; 
}

DtJuego::~DtJuego(){}


ostream& operator <<(ostream& salida,const DtJuego& a) {
	cout << "Nombre " << a.nombre << endl;
	return salida;
}