#ifndef ICONTROLADORJUEGO
#define ICONTROLADORJUEGO
#include <windows.h>
#include <string>
#include <iostream>
#include "Juego.h"
#include "DtJuego.h"

using namespace std; 

class IControladorJuego{
    private:
    public:
        //virtual void seleccionarJuego(string idJuego) = 0;
        virtual void seleccionarJuego(int idJuego) = 0;
        virtual void recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string>directoriosData) = 0;
        virtual void agregarJuego() = 0;
        virtual list<DtJuego*> verJuegosBackupeadosPorJugador(string nick) = 0;
        virtual list<DtJuego*> listarJuegos() = 0;
};

#endif