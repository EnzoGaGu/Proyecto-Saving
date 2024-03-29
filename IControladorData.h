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
#include <pqxx/pqxx>
#include "DtFechaHora.h"
#include "enumTipoDato.h"
#include "enumFuente.h"
#include "DtData.h"

using namespace std; 

class IControladorData{
    private:
    public:
        virtual list<string> encontrarArchivosPorJuego(int idJuego, EnumTipoDato tipoDato) = 0;
        virtual string encontrarArchivo(string directorio, string archivo) = 0;
        virtual void seleccionarDirectorioLocal(string seleccionado) = 0;
        virtual bool disponibilidadNombreData(string nombreData) = 0;
        virtual void crearCarpetaBackup(string directorioBackup, int idJuego, string nombreData, bool conReemplazo) = 0;
        virtual void backupearDatos(bool conReemplazo) = 0;
        virtual void crearVirtualData(int idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato, bool conReemplazo, pqxx::work& txn) = 0; 
        virtual void actualizarFechaVirutalData(int idData, pqxx::work& txn) = 0;
        virtual list<DtData*> verVirtualData(EnumTipoDato tipoDato) = 0;
        virtual list<DtData*> verVirtualDataCompleta() = 0;
        virtual bool archivosDesactualizados(int idData) = 0;
};

#endif