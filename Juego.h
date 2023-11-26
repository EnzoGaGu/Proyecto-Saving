#ifndef JUEGO
#define JUEGO
#include <string>
#include <list>
#include "DtFechaHora.h"
#include "enumPlataforma.h"

class Juego{
    private:
        string idJuego;
        string nombre;
        EnumPlataforma plataforma;
        string imgLink; 
        string desc;
        list<string> extensionesData;
        list<string> directoriosData;
    public:
        Juego();
        Juego(string idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> extensionesData, list<string> directoriosData);
        void setIdJuego(string idJuego);
        string getIdJuego();
        void setNombre(string nombre);
        string getNombre();
        void setPlataforma(EnumPlataforma plataforma);
        EnumPlataforma getPlataforma();
        void setImgLink(string imgLink);
        string getImgLink();
        void setDesc(string desc);
        string getDesc();
        void setExtensionesData(list<string> extensionesData);
        list<string> getExtensionesData();
        void setDirectoriosData(list<string> directoriosData);
        list<string> getDirectoriosData();
        ~Juego();
};


#endif