#include "PartidaGuardada.h"

PartidaGuardada::PartidaGuardada(){}

PartidaGuardada::PartidaGuardada(string idPartida, string nombreJuego, string nombrePartida, string directorio, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumTipo tipo){
    this->idPartida = idPartida;
    this->nombreJuego = nombreJuego;
    this->nombrePartida = nombrePartida;
    this->directorio = directorio;
    this->comentariosJugador = comentariosJugador;
    this->fechaUltModificacion = fechaUltModificacion;
    this->tipo = tipo;
}

string PartidaGuardada::getIdPartida(){
    return this->idPartida;
}

void PartidaGuardada::setIdPartida(string idPartida){
    this->idPartida = idPartida;
}

string PartidaGuardada::getNombreJuego(){
    return this->nombreJuego;
}

void PartidaGuardada::setNombreJuego(string nombreJuego){
    this->nombreJuego = nombreJuego;
}

string PartidaGuardada::getDirectorio(){
    return this->directorio;
}

void PartidaGuardada::setDirectorio(string directorio){
    this->directorio = directorio;
}

DtFechaHora* PartidaGuardada::getFechaUltModificacion(){
    return this->fechaUltModificacion;
}

void PartidaGuardada::setFechaUltModificacion(DtFechaHora* fechaUltModificacion){
    this->fechaUltModificacion = fechaUltModificacion;
}

void PartidaGuardada::setTipo(EnumTipo tipo){
    this->tipo = tipo;
}

EnumTipo PartidaGuardada::getTipo(){
    return this->tipo;
}

PartidaGuardada::~PartidaGuardada(){}