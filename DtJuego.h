#ifndef DTJUEGO
#define DTJUEGO
#include <string>
#include <list>
#include <map>
#include "DtFechaHora.h"
#include "Configuracion.h"
#include "enumPlataforma.h"

class DtJuego{
    private:
        string idJuego;
        string nombre;
        EnumPlataforma plataforma;
        string imgLink; 
        string desc;
        list<string> extensionesData;
        list<string> directoriosData;
    public:
        DtJuego();
        DtJuego(string idJuego, string nombre, string nombreCarpetaGuardado, DtFechaHora* fechaUltAct, string directorioLocal, EnumPlataforma plataforma, string imgLink, string desc, string extensionArchivoGuardado, string extensionConfig);
        string getIdJuego();
        string getNombre();
        EnumPlataforma getPlataforma();
        string getImgLink();
        string getDesc();
        list<string> getExtensionesData();
        list<string> getDirectoriosData();
        ~DtJuego();

        friend ostream& operator <<(ostream&,const DtJuego&);//sobrecarga de << , para mostrar la clase DtFechaHora
};

#endif