#ifndef DTJUEGO
#define DTJUEGO
#include <string>
#include <map>
#include "DtFechaHora.h"
#include "enumTipo.h"
#include "PartidaGuardada.h"
#include "enumPlataforma.h"

class DtJuego{
    private:
        string idJuego;
        string nombre;
        string nombreCarpetaGuardado;
        DtFechaHora* fechaUltAct;
        string directorioLocal;
        EnumPlataforma plataforma;
        map<string, PartidaGuardada*> partidasGuardadas;
    public:
        DtJuego();
        DtJuego(string idJuego, string nombre, string nombreCarpetaGuardado, DtFechaHora* fechaUltAct, string directorioLocal, map<string, PartidaGuardada*> partidasGuardadas);
        string getIdJuego();
        string getNombre();
        string getNombreCarpetaGuardado();
        DtFechaHora* getFechaUltAct();
        string getDirectorioLocal();
        EnumPlataforma getPlataforma();
        ~DtJuego();

        friend ostream& operator <<(ostream&,const DtJuego&);//sobrecarga de << , para mostrar la clase DtFechaHora
};

#endif