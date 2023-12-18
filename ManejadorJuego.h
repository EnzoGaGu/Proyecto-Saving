#ifndef MANEJADORJUEGO
#define MANEJADORJUEGO
#include <list>
#include <iostream>
#include "Juego.h"

using namespace std; 

class ManejadorJuego{
    private:
        list<Juego*> juegos;
        ManejadorJuego();
        static ManejadorJuego* instancia;
    public:
        static ManejadorJuego* getInstancia();
        void add(Juego* juego);
        bool member(int idJuego);
        Juego* find(int idJuego);
        void remove(int idJuego);
        list<Juego*> listar();
        ~ManejadorJuego();
};

#endif