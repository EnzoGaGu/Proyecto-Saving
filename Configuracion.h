#ifndef CONFIGURACION
#define CONFIGURACION
#include "DtFechaHora.h"

class Configuracion{
    private:
        string idConfig;
        string directorioBackup;
        DtFechaHora* fechaCreacion;
    public:
        Configuracion();
        Configuracion(string idConfig, string directorioBackup, DtFechaHora* fechaCreacion);
        void setIdConfig(string idConfig);
        string getIdConfig();
        void setDirectorioBackup(string directorioBackup);
        string getDirectorioBackup();
        void setFechaCreacion(DtFechaHora* fechaCreacion);
        DtFechaHora* getFechaCreacion();
        ~Configuracion();
};

#endif