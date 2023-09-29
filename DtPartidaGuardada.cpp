#include "DtPartidaGuardada.h"

DtPartidaGuardada::DtPartidaGuardada(){}

DtPartidaGuardada::DtPartidaGuardada(string idPartida, string nombreJuego, string directorio, DtFechaHora* fechaUltModificacion, EnumTipo tipo){
    this->idPartida = idPartida;
    this->nombreJuego = nombreJuego;
    this->directorio = directorio;
    this->fechaUltModificacion = fechaUltModificacion;
    this->tipo = tipo;
}

string DtPartidaGuardada::getIdPartida(){
    return this->idPartida;
}

string DtPartidaGuardada::getNombreJuego(){
    return this->nombreJuego;
}

string DtPartidaGuardada::getDirectorio(){
    return this->directorio;
}

DtFechaHora* DtPartidaGuardada::getFechaUltModificacion(){
    return this->fechaUltModificacion;
}

EnumTipo DtPartidaGuardada::getTipo(){
    return this->tipo;
}

DtPartidaGuardada::~DtPartidaGuardada(){}