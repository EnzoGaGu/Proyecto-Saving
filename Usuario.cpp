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

void Usuario::addData(Data* data){
    this->dataAgregada.push_back(data);
}

Data* Usuario::findData(int idData){
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

bool Usuario::memberData(int idData){
    bool exists = false;

    list<Data*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        if((*it)->getIdData() == idData){
            exists = true;
        }
    }
    return exists;
}

DtData* Usuario::getDtData(int idData){
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

list<DtData*> Usuario::listData(){
    list<DtData*> lista;

    list<Data*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        DtData* data = new DtData((*it)->getIdData(), (*it)->getJuego(), (*it)->getNombreData(), (*it)->getDirectorioLocal(), (*it)->getDirectorioCloud(), (*it)->getComentariosJugador(), (*it)->getFechaUltModificacion(), (*it)->getPlataformaFuente(), (*it)->getTipoDato());
        lista.push_back(data);
    }

    return lista;
}

void Usuario::removeData(int idData){
    Data* forRemove; 

    if(memberData(idData) == true){
        list<Data*>::iterator it;
        for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
            if((*it)->getIdData() == idData){
                
            }
        }
    }
}

Usuario::~Usuario(){}