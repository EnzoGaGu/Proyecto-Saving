#include "Juego.h"


Juego::Juego(){}

Juego::Juego(int idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> archivosConfig, list<string> directoriosData){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->plataforma = plataforma;
    this->imgLink = imgLink;
    this->desc = desc;
    this->archivosData = archivosData;
    this->archivosConfig = archivosConfig; 
    this->directoriosData = directoriosData;
}

void Juego::setIdJuego(int idJuego){
    this->idJuego = idJuego;
}

int Juego::getIdJuego(){
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

void Juego::setArchivosData(list<string> archivosData){
    this->archivosData = archivosData;
}

list<string> Juego::getArchivosData(){
    return this->archivosData;
}

void Juego::setArchivosConfig(list<string> archivosConfig){
    this->archivosConfig = archivosConfig; 
}

list<string> Juego::getArchivosConfig(){
    return this->archivosConfig;
}

void Juego::setDirectoriosData(list<string> directoriosData){
    this->directoriosData = directoriosData;
}

list<string> Juego::getDirectoriosData(){
    return this->directoriosData;
}

Juego::~Juego(){}