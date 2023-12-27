#ifndef ICONTROLADORDATA
#define ICONTROLADORDATA
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <winbase.h>
#include <list>
#include <algorithm>
#include <chrono>
#include <ctime>
#include "IControladorTiempo.h"
#include "ControladorTiempo.h"
#include "DtFechaHora.h"
#include "enumTipoDato.h"
#include "enumFuente.h"
#include "DtData.h"

using namespace std; 

class IControladorData{
    private:
    public:
        virtual list<string> encontrarArchivosPorJuego(int idJuego) = 0;
        virtual string encontrarArchivo(string directorio, string archivo) = 0;
        virtual void seleccionarDirectorioLocal(string seleccionado) = 0;
        virtual bool disponibilidadNombreData(string nombreData) = 0;
        virtual void crearCarpetaBackup(string directorioBackup, int idJuego, string nombreData, bool conReemplazo) = 0;
        virtual void backupearDatos(bool conReemplazo) = 0;
        virtual void crearVirtualData(int idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato) = 0;
        virtual list<DtData*> verVirtualData(EnumTipoDato tipoDato) = 0;
};

#endif