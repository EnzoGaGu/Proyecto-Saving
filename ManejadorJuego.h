#ifndef MANEJADORJUEGO
#define MANEJADORJUEGO
#include <list>
#include <iostream>
#include <pqxx/pqxx>
#include "Juego.h"
#include "Fabrica.h"
#include "ManejadorEnums.h"

using namespace std; 

class ManejadorJuego{
    private:
        list<Juego*> juegos;
        ManejadorJuego();
        static ManejadorJuego* instancia;
    public:
        static ManejadorJuego* getInstancia();
        void getFromDB(pqxx::work& txn); 
        void add(Juego* juego, pqxx::work& txn);
        bool member(int idJuego);
        Juego* find(int idJuego);
        void remove(int idJuego);
        void modify(int idJuego, string nombre, string imgLink, string desc, pqxx::work& txn);
        list<Juego*> listar();
        ~ManejadorJuego();
};

#endif