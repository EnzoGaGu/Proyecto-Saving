#include "DtUsuario.h"

DtUsuario::DtUsuario(){}

DtUsuario::DtUsuario(string nick, string nombre, string pass, string email, string pfp, DtFechaHora* fechaInsc, bool admin){
    this->nick = nick;
    this->nombre = nombre;
    this->pass = pass;
    this->email = email;
    this->pfp = pfp; 
    this->fechaInsc = fechaInsc; 
    this->admin = admin;
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

Data* DtUsuario::findData(string idData){
    if(memberData(idData) == true){
        list<Data*>::iterator it;
        for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
            if((*it)->getIdData() == idData){
                return (*it);
            }
        }
    }
    else{
        return NULL;
    }
}

bool DtUsuario::memberData(string idData){
    bool exists = false;

    list<Data*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        if((*it)->getIdData() == idData){
            exists = true;
        }
    }
    return exists;
}

DtData* DtUsuario::getDtData(string idData){
    Data* data = findData(idData);
    DtData* dtData; 

    if(data!=NULL){
        dtData = new DtData(data->getIdData(), data->getJuego(), data->getNombreData(), data->getDirectorioLocal(), data->getDirectorioCloud(), data->getComentariosJugador(), data->getFechaUltModificacion(), data->getPlataformaFuente(), data->getTipoDato());
    }
    else{
        dtData = NULL;
    }

    return dtData;
}

list<DtData*> DtUsuario::listData(){
    list<DtData*> lista;

    list<Data*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        DtData* data = new DtData((*it)->getIdData(), (*it)->getJuego(), (*it)->getNombreData(), (*it)->getDirectorioLocal(), (*it)->getDirectorioCloud(), (*it)->getComentariosJugador(), (*it)->getFechaUltModificacion(), (*it)->getPlataformaFuente(), (*it)->getTipoDato());
        lista.push_back(data);
    }

    return lista;
}

DtUsuario::~DtUsuario(){}