#include "Data.h"

Data::Data(){}

Data::Data(int idData, Juego* juego, string nombreData, string directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato){
    this->idData = idData;
    this->juego = juego;
    this->nombreData = nombreData;
    this->directorioLocal = directorioLocal;
    this->directorioCloud = directorioCloud;
    this->comentariosJugador = comentariosJugador;
    this->fechaUltModificacion = fechaUltModificacion;
    this->plataformaFuente = plataformaFuente;
    this->tipoDato = tipoDato;
}

int Data::getIdData(){
    return this->idData;
}

void Data::setIdData(int idData){
    this->idData = idData;
}

Juego* Data::getJuego(){
    return this->juego;
}

void Data::setJuego(Juego* juego){
    this->juego = juego;
}

string Data::getNombreData(){
    return this->nombreData;
}

void Data::setNombreData(string nombreData){
    this->nombreData = nombreData;
}

string Data::getDirectorioLocal(){
    return this->directorioLocal;
}

void Data::setDirectorioLocal(string directorioLocal){
    this->directorioLocal = directorioLocal;
}

string Data::getDirectorioCloud(){
    return this->directorioLocal;
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

Data::~Data(){}