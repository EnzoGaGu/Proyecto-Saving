#ifndef ICONTROLADORJUEGO
#define ICONTROLADORJUEGO
#include <windows.h>
#include <string>
#include <iostream>
#include <pqxx/pqxx>
#include "Juego.h"
#include "DtJuego.h"

using namespace std; 

class IControladorJuego{
    private:
    public:
        //virtual void seleccionarJuego(string idJuego) = 0;
        virtual void inicializar(pqxx::work& txn) = 0;
        virtual void seleccionarJuego(int idJuego) = 0;
        virtual void recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string>directoriosData) = 0;
        virtual void agregarJuego(pqxx::work& txn) = 0;
        virtual list<DtJuego*> verJuegosBackupeadosPorJugador(string nick, pqxx::connection c) = 0;
        virtual list<DtJuego*> listarJuegos() = 0;
};

#endif