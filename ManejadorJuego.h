#ifndef MANEJADORJUEGO
#define MANEJADORJUEGO
#include <list>
#include "Juego.h"

class ManejadorJuego{
    private:
        list<Juego*> juegos;
        ManejadorJuego();
        static ManejadorJuego* instancia;
    public:
        static ManejadorJuego* getInstancia();
        void add(Juego* juego);
        bool member(string idJuego);
        Juego* find(string idJuego);
        void remove(string idJuego);
        ~ManejadorJuego();
};

#endif