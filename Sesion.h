#ifndef SESION
#define SESION
#include <string>
#include "Usuario.h"

using namespace std;

class Sesion{
    private:
        static Sesion* instancia;
        Sesion();
        Usuario* usuarioActual;
    public:
        static Sesion* getSesion();
        void setUsuario(Usuario*);
        Usuario* getUsuario();
        ~Sesion();
};

#endif