#ifndef CONTROLADORDATA
#define CONTROLADORDATA
#include <string>
#include "IControladorData.h"
#include "DtFechaHora.h"
#include "enumTipoDato.h"
#include "ManejadorJuego.h"
#include "Sesion.h"
#include "Data.h"
#include <sys/stat.h>
//#include <dirent.h>
#include <fstream>
#include <winbase.h>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

class ControladorData : public IControladorData{
    private:
        string idData;
        string nombreArchivo;
        string directorioLocal;
        string directorioBackup;
        Data* newData;
    public:
        ControladorData();
        void encontrarArchivo(string directorio, string archivo);
        void crearCarpetaBackup(string directorioBackup, string nombreJuego, DtFechaHora* fecha, EnumTipoDato tipoDato, bool conReemplazo);
        void backupearDatos(bool conReemplazo);
        void crearVirtualData(string idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato);
        ~ControladorData();
};

#endif