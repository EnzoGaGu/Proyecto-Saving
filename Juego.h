#ifndef JUEGO
#define JUEGO
#include <string>
#include <list>
#include "DtFechaHora.h"
#include "enumPlataforma.h"

class Juego{
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
        Juego();
        Juego(int idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> archivosConfig, list<string> directoriosData);
        void setIdJuego(int idJuego);
        int getIdJuego();
        void setNombre(string nombre);
        string getNombre();
        void setPlataforma(EnumPlataforma plataforma);
        EnumPlataforma getPlataforma();
        void setImgLink(string imgLink);
        string getImgLink();
        void setDesc(string desc);
        string getDesc();
        void setArchivosData(list<string> archivosData);
        list<string> getArchivosData();
        void setArchivosConfig(list<string> archivosConfig);
        list<string> getArchivosConfig();
        void setDirectoriosData(list<string> directoriosData);
        list<string> getDirectoriosData();
        ~Juego();
};


#endif