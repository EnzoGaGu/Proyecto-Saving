#ifndef CONTROLADORJUEGO
#define CONTROLADORJUEGO
#include <string>
#include "IControladorJuego.h"
#include "Juego.h"
#include "DtJuego.h"
#include "ManejadorJuego.h"

using namespace std; 

class ControladorJuego: public IControladorJuego{
    private:
        string idJuego;
    public:
        ControladorJuego();
        void seleccionarJuego(string idJuego);
        list<DtJuego*> listarJuegos();
        ~ControladorJuego();
};

#endif