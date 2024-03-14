#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

Sesion* Sesion::getSesion(){
    if (instancia == NULL)
    {
        instancia = new Sesion();
    }
    return instancia;
}

void Sesion::setUsuario(Usuario* usuarioActual, pqxx::work& txn){
    this->usuarioActual = usuarioActual;
    this->usuarioActual->getDataFromDB(txn);
}

Usuario* Sesion::getUsuario(){
    return this->usuarioActual;
}

Sesion::~Sesion(){}