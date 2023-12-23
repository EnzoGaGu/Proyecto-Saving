#include "DtUsuario.h"

DtUsuario::DtUsuario(){}

DtUsuario::DtUsuario(string nick, string nombre, string pass, string email, string pfp, DtFechaHora* fechaInsc, bool admin, list<DtData*> dataAgregada){
    this->nick = nick;
    this->nombre = nombre;
    this->pass = pass;
    this->email = email;
    this->pfp = pfp; 
    this->fechaInsc = fechaInsc; 
    this->admin = admin;
    this->dataAgregada = dataAgregada;
}

string DtUsuario::getNick(){
    return this->nick;
}

string DtUsuario::getNombre(){
    return this->nombre;
}

string DtUsuario::getPass(){
    return this->pass;
}

string DtUsuario::getEmail(){
    return this->email;
}

string DtUsuario::getPfp(){
    return this->pfp;
}

DtFechaHora* DtUsuario::getFechaInsc(){
    return this->fechaInsc;
}

bool DtUsuario::getAdmin(){
    return this->admin;
}

DtData* DtUsuario::findData(int idData){
    if(memberData(idData) == true){
        list<DtData*>::iterator it;
        for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
            if((*it)->getIdData() == idData){
                return (*it);
            }
        }
    }
    else{
        return NULL;
    }
    return NULL;
}

bool DtUsuario::memberData(int idData){
    bool exists = false;

    list<DtData*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        if((*it)->getIdData() == idData){
            exists = true;
        }
    }
    return exists;
}

list<DtData*> DtUsuario::listData(){
    return this->dataAgregada;
}

DtUsuario::~DtUsuario(){}