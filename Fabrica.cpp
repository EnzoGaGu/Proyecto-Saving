#include "Fabrica.h"

Fabrica *Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

Fabrica * Fabrica::getInstancia(){
    if (instancia == NULL){
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorUsuario* Fabrica::getControladorUsuario(){
    return new ControladorUsuario();
}

Fabrica::~Fabrica(){}