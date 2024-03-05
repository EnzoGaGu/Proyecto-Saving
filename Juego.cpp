#include "Juego.h"


Juego::Juego(){}

Juego::Juego(int idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> directoriosData){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->plataforma = plataforma;
    this->imgLink = imgLink;
    this->desc = desc;
    this->archivosData = archivosData;
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

void Juego::setDirectoriosData(list<string> directoriosData){
    this->directoriosData = directoriosData;
}

list<string> Juego::getDirectoriosData(){
    return this->directoriosData;
}

string Juego::plataformaToString(){
    switch(this->plataforma){
        case EnumPlataforma::WINDOWS:
            return "WINDOWS";
        case EnumPlataforma::LINUX:
            return "LINUX";
        case EnumPlataforma::ANDROID:
            return "ANDROID";
        case EnumPlataforma::PS1:
            return "PS1";
        case EnumPlataforma::PS2:
            return "PS2";
        case EnumPlataforma::GAMECUBE:
            return "GAMECUBE";
        case EnumPlataforma::XBOX:
            return "XBOX";
    }
    return "";
}

void Juego::stringToPlataforma(string plataforma){
    if(plataforma == "WINDOWS"){
        this->plataforma = EnumPlataforma::WINDOWS;
    }
    else if(plataforma == "LINUX"){
        this->plataforma = EnumPlataforma::LINUX;
    }
    else if(plataforma == "ANDROID"){
        this->plataforma = EnumPlataforma::ANDROID;
    }
    else if(plataforma == "PS1"){
        this->plataforma = EnumPlataforma::PS1;
    }
    else if(plataforma == "PS2"){
        this->plataforma = EnumPlataforma::PS2;
    }
    else if(plataforma == "GAMECUBE"){
        this->plataforma = EnumPlataforma::GAMECUBE;
    }
    else if(plataforma == "XBOX"){
        this->plataforma = EnumPlataforma::XBOX;
    }
}

Juego::~Juego(){}