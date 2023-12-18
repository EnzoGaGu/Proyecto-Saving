#include "ManejadorJuego.h"

ManejadorJuego* ManejadorJuego::instancia=NULL;

ManejadorJuego::ManejadorJuego(){}

ManejadorJuego* ManejadorJuego::getInstancia(){
    if (instancia==NULL){
        instancia = new ManejadorJuego();
    }
    return instancia;
}

void ManejadorJuego::add(Juego* juego){
    juegos.push_back(juego);
}

bool ManejadorJuego::member(string idJuego){
    bool member = false;
    list<Juego*>::iterator it;
    for(it=this->juegos.begin(); it!=this->juegos.end(); it++){
        if((*it)->getIdJuego() == idJuego){
            member = true;
        }
    }
    return member;
}

Juego* ManejadorJuego::find(string idJuego){
    Juego* juego = NULL;
    list<Juego*>::iterator it;
    for(it=this->juegos.begin(); it!=this->juegos.end(); it++){
        if((*it)->getIdJuego() == idJuego){
            juego = (*it);
        }
    }
    return juego;
}

void ManejadorJuego::remove(string idJuego){
    Juego* juego;

    list<Juego*>::iterator it;
    for(it=juegos.begin(); it!=juegos.end(); it++){
        if((*it)->getIdJuego() == idJuego){
            juego = (*it);
            juegos.remove(*it);
            delete juego;
        }
    }
}

list<Juego*> ManejadorJuego::listar(){
    return this->juegos;
}

ManejadorJuego::~ManejadorJuego(){}