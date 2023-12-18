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
        int idJuego;
        string nombre;
        EnumPlataforma plataforma;
        string imgLink; 
        string desc;
        list<string> archivosData;
        list<string> directoriosData;
    public:
        DtJuego();
        DtJuego(int idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> directoriosData);
        int getIdJuego();
        string getNombre();
        EnumPlataforma getPlataforma();
        string getImgLink();
        string getDesc();
        list<string> getArchivosData();
        list<string> getDirectoriosData();
        ~DtJuego();

        friend ostream& operator <<(ostream&,const DtJuego&);//sobrecarga de << , para mostrar la clase DtFechaHora
};

#endif