#ifndef CONTROLADORJUEGO
#define CONTROLADORJUEGO
#include "IControladorJuego.h"
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
        void seleccionarJuego(int idJuego);
        void recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string>directoriosData);
        void agregarJuego();
        list<DtJuego*> verJuegosBackupeadosPorJugador(string nick);
        list<DtJuego*> listarJuegos();
        ~ControladorJuego();
};

#endif