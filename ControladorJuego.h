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
        list<string> archivosConfig;
        list<string> directoriosData; 
    public:
        ControladorJuego();
        string nombreDeJuego(int idJuego);
        void inicializar(pqxx::work& txn);
        void recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> archivosConfig, list<string>directoriosData);
        void agregarJuego(pqxx::work& txn);
        list<DtJuego*> verJuegosBackupeadosPorJugador(string nick, pqxx::connection c);
        list<DtJuego*> listarJuegos();
        void modificarDatosJuego(int idJuego, string nombre, string imgLink, string desc, pqxx::work& txn);
        ~ControladorJuego();
};

#endif