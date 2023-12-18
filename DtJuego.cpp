#include "DtJuego.h"


DtJuego::DtJuego(){}

DtJuego::DtJuego(string idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> extensionesData, list<string> directoriosData){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->plataforma = plataforma;
    this->imgLink = imgLink;
    this->desc = desc;
    this->extensionesData = extensionesData;
    this->directoriosData = directoriosData;
}


string DtJuego::getIdJuego(){
    return this->idJuego;
}

string DtJuego::getNombre(){
    return this->nombre;
}

EnumPlataforma DtJuego::getPlataforma(){
    return this->plataforma; 
}

string DtJuego::getImgLink(){
    return this->imgLink;
}

string DtJuego::getDesc(){
    return this->desc;
}

list<string> DtJuego::getExtensionesData(){
    return this->extensionesData;
}

list<string> DtJuego::getDirectoriosData(){
    return this->directoriosData;
}


DtJuego::~DtJuego(){}


ostream& operator <<(ostream& salida,const DtJuego& a) {
	cout << "Nombre " << a.nombre << endl;
	return salida;
}