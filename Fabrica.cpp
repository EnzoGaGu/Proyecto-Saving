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

IControladorJuego* Fabrica::getControladorJuego(){
    return new ControladorJuego();
}

IControladorData* Fabrica::getControladorData(){
    return new ControladorData();
}

IControladorTiempo* Fabrica::getControladorTiempo(){
    return new ControladorTiempo();
}

IControladorEnums* Fabrica::getControladorEnums(){
    return new ControladorEnums();
}

Fabrica::~Fabrica(){}