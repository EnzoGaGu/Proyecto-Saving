#ifndef FABRICA
#define FABRICA
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "IControladorJuego.h"
#include "ControladorJuego.h"
#include "IControladorData.h"
#include "ControladorData.h"
#include "IControladorTiempo.h"
#include "ControladorTiempo.h"
#include "IControladorEnums.h"
#include "ControladorEnums.h"


class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();

        IControladorUsuario* getControladorUsuario();        
        IControladorJuego* getControladorJuego();
        IControladorData* getControladorData();
        IControladorTiempo* getControladorTiempo();
        IControladorEnums* getControladorEnums();

        ~Fabrica();
};

#endif