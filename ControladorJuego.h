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
        string nombreJuego;
        EnumPlataforma plataforma;
        string imgLink;
        string desc;
        list<string> archivosData;
        list<string> directoriosData; 
    public:
        ControladorJuego();
        void seleccionarJuego(string idJuego);
        void recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string>directoriosData);
        void agregarJuego();
        list<DtJuego*> listarJuegos();
        ~ControladorJuego();
};

#endif