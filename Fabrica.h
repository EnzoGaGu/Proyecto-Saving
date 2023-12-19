#ifndef FABRICA
#define FABRICA
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "IControladorJuego.h"
#include "ControladorJuego.h"
#include "IControladorData.h"
#include "ControladorData.h"


class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();

        IControladorUsuario* getControladorUsuario();        
        IControladorJuego* getControladorJuego();
        IControladorData* getControladorData();

        ~Fabrica();
};

#endif