#ifndef CONTROLADORJUEGO
#define CONTROLADORJUEGO
#include "IControladorJuego.h"
#include "ManejadorUsuario.h"
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
        void inicializar(pqxx::work& txn);
        void recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string>directoriosData);
        void agregarJuego(pqxx::work& txn);
        list<DtJuego*> verJuegosBackupeadosPorJugador(string nick, pqxx::connection c);
        list<DtJuego*> listarJuegos();
        ~ControladorJuego();
};

#endif