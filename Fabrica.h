#ifndef FABRICA
#define FABRICA
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();

        IControladorUsuario* getControladorUsuario();        

        ~Fabrica();
};

#endif