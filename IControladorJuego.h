#ifndef ICONTROLADORJUEGO
#define ICONTROLADORJUEGO
#include <string>
#include "IControladorJuego.h"
#include "Juego.h"
#include "ManejadorJuego.h"

using namespace std; 

class IControladorJuego{
    private:
    public:
        virtual void seleccionarJuego(string idJuego) = 0;
};

#endif