#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO
#include <list>
#include <iostream>
#include <pqxx/pqxx>
#include "Fabrica.h"
#include "Usuario.h"

using namespace std;

class ManejadorUsuario{
    private:
        ManejadorUsuario();
        static ManejadorUsuario* instancia;
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        void add(Usuario* usuario, pqxx::work& txn);
        bool member(string nick, pqxx::work& txn);
        Usuario* find(string nick, pqxx::work& txn); 
        void remove(string nick, pqxx::work& txn);
        ~ManejadorUsuario();
};


#endif