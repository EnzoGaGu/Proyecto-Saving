#include "Data.h"

Data::Data(){}

Data::Data(int idData, int idJuego, string nombreData, list<string> directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato, bool conHistorial){
    this->idData = idData;
    this->idJuego = idJuego;
    this->nombreData = nombreData;
    this->directorioLocal = directorioLocal;
    this->directorioCloud = directorioCloud;
    this->comentariosJugador = comentariosJugador;
    this->fechaUltModificacion = fechaUltModificacion;
    this->plataformaFuente = plataformaFuente;
    this->tipoDato = tipoDato;
    this->conHistorial = conHistorial;
}

int Data::getIdData(){
    return this->idData;
}

void Data::setIdData(int idData){
    this->idData = idData;
}

int Data::getJuego(){
    return this->idJuego;
}

void Data::setJuego(int idJuego){
    this->idJuego = idJuego;
}

string Data::getNombreData(){
    return this->nombreData;
}

void Data::setNombreData(string nombreData){
    this->nombreData = nombreData;
}

list<string> Data::getDirectorioLocal(){
    return this->directorioLocal;
}

void Data::setDirectorioLocal(list<string> directorioLocal){
    this->directorioLocal = directorioLocal;
}

string Data::getDirectorioCloud(){
    return this->directorioCloud;
}

void Data::setDirectorioCloud(string directorioCloud){
    this->directorioCloud = directorioCloud;
}

string Data::getComentariosJugador(){
    return this->comentariosJugador;
}

void Data::setComentariosJugador(string comentariosJugador){
    this->comentariosJugador = comentariosJugador;
}

DtFechaHora* Data::getFechaUltModificacion(){
    return this->fechaUltModificacion;
}

void Data::setFechaUltModificacion(DtFechaHora* fechaUltModificacion){
    this->fechaUltModificacion = fechaUltModificacion;
}

void Data::setPlataformaFuente(EnumFuente plataformaFuente){
    this->plataformaFuente = plataformaFuente;
}

EnumFuente Data::getPlataformaFuente(){
    return this->plataformaFuente;
}

EnumTipoDato Data::getTipoDato(){
    return this->tipoDato;
}

void Data::setTipoDato(EnumTipoDato tipoDato){
    this->tipoDato = tipoDato;
}

bool Data::getConHistorial(){
    return this->conHistorial;
}

void Data::setConHistorial(bool conHistorial){
    this->conHistorial = conHistorial; 
}

Data::~Data(){}