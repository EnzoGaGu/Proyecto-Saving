#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string nick, string nombre, string pass, string email, string pfp, DtFechaHora* fechaInsc, bool admin){
    this->nick = nick;
    this->nombre = nombre;
    this->pass = pass;
    this->email = email;
    this->pfp = pfp; 
    this->fechaInsc = fechaInsc; 
    this->admin = admin;
}

void Usuario::setNick(string nick){
    this->nick = nick;
}

string Usuario::getNick(){
    return this->nick;
}

void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}

string Usuario::getNombre(){
    return this->nombre;
}

void Usuario::setPass(string pass){
    this->pass = pass;
}

string Usuario::getPass(){
    return this->pass;
}

void Usuario::setEmail(string email){
    this->email = email;
}

string Usuario::getEmail(){
    return this->email;
}

void Usuario::setPfp(string pfp){
    this->pfp = pfp;
}

string Usuario::getPfp(){
    return this->pfp;
}

void Usuario::setFechaInsc(DtFechaHora* fechaInsc){
    this->fechaInsc = fechaInsc;
}

DtFechaHora* Usuario::getFechaInsc(){
    return this->fechaInsc;
}

void Usuario::setAdmin(bool admin){
    this->admin = admin;
}

bool Usuario::getAdmin(){
    return this->admin;
}

Usuario::~Usuario(){}