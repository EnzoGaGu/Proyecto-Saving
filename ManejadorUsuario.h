#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO
#include <list>
#include <iostream>
#include "Usuario.h"

using namespace std;

class ManejadorUsuario{
    private:
        list<Usuario*> usuarios;
        ManejadorUsuario();
        static ManejadorUsuario* instancia;
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        void add(Usuario* usuario);
        bool member(string nick);
        Usuario* find(string nick); 
        void remove(string nick);
        ~ManejadorUsuario();
};


#endif