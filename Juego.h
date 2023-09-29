#ifndef JUEGO
#define JUEGO
#include <string>
#include <map>
#include "DtFechaHora.h"
#include "enumTipo.h"
#include "PartidaGuardada.h"
#include "Configuracion.h"
#include "enumPlataforma.h"

class Juego{
    private:
        string idJuego;
        string nombre;
        string nombreCarpetaGuardado;
        DtFechaHora* fechaUltAct;
        string directorioLocal;
        EnumPlataforma plataforma;
        string imgLink; 
        string desc;
        map<string, PartidaGuardada*> partidasGuardadas;
        map<string, Configuracion*> configuraciones;
    public:
        Juego();
        Juego(string idJuego, string nombre, string nombreCarpetaGuardado, DtFechaHora* fechaUltAct, string directorioLocal, EnumPlataforma plataforma, string imgLink, string desc);
        void setIdJuego(string idJuego);
        string getIdJuego();
        void setNombre(string nombre);
        string getNombre();
        void setNombreCarpetaGuardado(string nombreCarpetaGuardado);
        string getNombreCarpetaGuardado();
        void setFechaUltAct(DtFechaHora* fechaUltAct);
        DtFechaHora* getFechaUltAct();
        void setDirectorioLocal(string directorioLocal);
        string getDirectorioLocal();
        void setPlataforma(EnumPlataforma plataforma);
        EnumPlataforma getPlataforma();
        void addPartidaGuardada(PartidaGuardada* partida);
        PartidaGuardada* findPartidaGuardada(string idPartida);
        void removePartidaGuardada(string idPartida);
        void addConfiguracion(Configuracion* config);
        Configuracion* findConfiguracion(string idConfig);
        void removeConfiguracion(string idConfig);
        ~Juego();
};


#endif