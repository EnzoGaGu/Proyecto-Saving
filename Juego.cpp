#include "Juego.h"


Juego::Juego(){}

Juego::Juego(string idJuego, string nombre, string nombreCarpetaGuardado, DtFechaHora* fechaUltAct, string directorioLocal, EnumPlataforma plataforma, string imgLink, string desc){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->nombreCarpetaGuardado = nombreCarpetaGuardado;
    this->fechaUltAct = fechaUltAct;
    this->directorioLocal = directorioLocal;
    this->plataforma = plataforma;
    this->imgLink = imgLink;
    this->desc = desc;
}

void Juego::setIdJuego(string idJuego){
    this->idJuego = idJuego;
}

string Juego::getIdJuego(){
    return this->idJuego;
}

void Juego::setNombre(string nombre){
    this->nombre = nombre;
}

string Juego::getNombre(){
    return this->nombre;
}

void Juego::setNombreCarpetaGuardado(string nombreCarpetaGuardado){
    this->nombreCarpetaGuardado = nombreCarpetaGuardado;
}

string Juego::getNombreCarpetaGuardado(){
    return this->nombreCarpetaGuardado;
}

void Juego::setFechaUltAct(DtFechaHora* fechaUltAct){
    this->fechaUltAct = fechaUltAct;
}

DtFechaHora* Juego::getFechaUltAct(){
    return this->fechaUltAct;
}

void Juego::setDirectorioLocal(string directorioLocal){
    this->directorioLocal = directorioLocal;
}

string Juego::getDirectorioLocal(){
    return this->directorioLocal;
}

void Juego::setPlataforma(EnumPlataforma plataforma){
    this->plataforma = plataforma;
}

EnumPlataforma Juego::getPlataforma(){
    return this->plataforma; 
}

void Juego::addPartidaGuardada(PartidaGuardada* partida){
    this->partidasGuardadas.insert({partida->getIdPartida(), partida});
}

PartidaGuardada* Juego::findPartidaGuardada(string idPartida){
    PartidaGuardada* partida;
    partida = this->partidasGuardadas.find(idPartida)->second;
    return partida;
}

void Juego::removePartidaGuardada(string idPartida){
    this->partidasGuardadas.erase(idPartida);
}

void Juego::addConfiguracion(Configuracion* config){
    this->configuraciones.insert({config->getIdConfig(), config});
}

Configuracion* Juego::findConfiguracion(string idConfig){
    Configuracion* config; 
    config = this->configuraciones.find(idConfig)->second;
    return config;
}

void Juego::removeConfiguracion(string idConfig){
    this->configuraciones.erase(idConfig);
}

Juego::~Juego(){}