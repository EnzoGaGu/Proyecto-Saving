#include "ManejadorUsuario.h"

ManejadorUsuario * ManejadorUsuario::instancia=NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia==NULL){
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

list<Usuario*> ManejadorUsuario::getUsuarios(){
    return usuarios;
}

void ManejadorUsuario::add(Usuario* Usuario){
    usuarios.push_back(Usuario);
}

bool ManejadorUsuario::member(string nick){
    bool member = false;
    list<Usuario*>::iterator it;
    for (it=usuarios.begin(); it!=usuarios.end(); it++){
        if ((*it)->getNick() == nick) 
            member = true; 
    }
    return member;
}

Usuario* ManejadorUsuario::find(string nick){
    Usuario* ret = NULL;
    list<Usuario*>::iterator it = usuarios.begin();
    for(it=usuarios.begin(); it!=usuarios.end(); it++) {
        if((*it)->getNick() == nick){
            ret = (*it);
        }   
    }
    return ret;
}

void ManejadorUsuario::remove(string nick){
    Usuario* usuario;

    list<Usuario*>::iterator it;
    for(it=usuarios.begin(); it!=usuarios.end(); it++){
        if((*it)->getNick() == nick){
            usuario = (*it);
            usuarios.remove(*it);
            delete usuario;
        }
    }
}

ManejadorUsuario::~ManejadorUsuario(){}