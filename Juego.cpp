#include "Juego.h"


Juego::Juego(){}

Juego::Juego(string idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> extensionesData, list<string> directoriosData){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->plataforma = plataforma;
    this->imgLink = imgLink;
    this->desc = desc;
    this->extensionesData = extensionesData;
    this->directoriosData = directoriosData;
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

void Juego::setPlataforma(EnumPlataforma plataforma){
    this->plataforma = plataforma;
}

EnumPlataforma Juego::getPlataforma(){
    return this->plataforma; 
}

void Juego::setImgLink(string imgLink){
    this->imgLink = imgLink;
}

string Juego::getImgLink(){
    return this->imgLink;
}

void Juego::setDesc(string desc){
    this->desc = desc;
}

string Juego::getDesc(){
    return this->desc;
}

void Juego::setExtensionesData(list<string> extensionesData){
    this->extensionesData = extensionesData;
}

list<string> Juego::getExtensionesData(){
    return this->extensionesData;
}

void Juego::setDirectoriosData(list<string> directoriosData){
    this->directoriosData = directoriosData;
}

list<string> Juego::getDirectoriosData(){
    return this->directoriosData;
}

Juego::~Juego(){}