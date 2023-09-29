#include "Configuracion.h"

Configuracion::Configuracion(){}

Configuracion::Configuracion(string idConfig, string directorioBackup, DtFechaHora* fechaCreacion){
    this->idConfig = idConfig;
    this->directorioBackup = directorioBackup;
    this->fechaCreacion = fechaCreacion;
}

void Configuracion::setIdConfig(string idConfig){
    this->idConfig = idConfig;
}
string Configuracion::getIdConfig(){
    return idConfig;
}

void Configuracion::setDirectorioBackup(string directorioBackup){
    this->directorioBackup = directorioBackup;
}

string Configuracion::getDirectorioBackup(){
    return this->directorioBackup;
}

void Configuracion::setFechaCreacion(DtFechaHora* fechaCreacion){
    this->fechaCreacion = fechaCreacion;
}

DtFechaHora* Configuracion::getFechaCreacion(){
    return fechaCreacion;
}

Configuracion::~Configuracion(){}