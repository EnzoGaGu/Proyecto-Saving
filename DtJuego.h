#ifndef DTJUEGO
#define DTJUEGO
#include <string>
#include <list>
#include <map>
#include "DtFechaHora.h"
#include "Configuracion.h"
#include "enumPlataforma.h"
#include "ManejadorEnums.h"

class DtJuego{
    private:
        int idJuego;
        string nombre;
        EnumPlataforma plataforma;
        string imgLink; 
        string desc;
        list<string> archivosData;
        list<string> archivosConfig;
        list<string> directoriosData;
    public:
        DtJuego();
        DtJuego(int idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> archivosConfig, list<string> directoriosData);
        int getIdJuego();
        string getNombre();
        EnumPlataforma getPlataforma();
        string getImgLink();
        string getDesc();
        list<string> getArchivosData();
        list<string> getArchivosConfig();
        list<string> getDirectoriosData();
        ~DtJuego();

        friend ostream& operator <<(ostream&,const DtJuego&);//sobrecarga de <<
};

#endif