#ifndef CONTROLADORDATA
#define CONTROLADORDATA
//#include <string>
#include "IControladorData.h"
#include "DtFechaHora.h"
#include "enumTipoDato.h"
#include "ManejadorJuego.h"
#include "Sesion.h"
#include "Data.h"
#include <sys/stat.h>
//#include <dirent.h>
//#include <fstream>
//#include <winbase.h>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

class ControladorData : public IControladorData{
    private:
        int idData;
        list<string> nombreArchivo;
        list<string> directorioLocal;
        list<string> directorioLocalCompleto; 
        string directorioBackup;
        Data* newData;
    public:
        ControladorData();
        list<string> encontrarArchivosPorJuego(int idJuego, EnumTipoDato tipoDato);
        string encontrarArchivo(string directorio, string archivo);
        void seleccionarDirectorioLocal(string seleccionado);
        bool disponibilidadNombreData(string nombreData);
        void crearCarpetaBackup(string directorioBackup, int idJuego, string nombreData, bool conReemplazo);
        void backupearDatos(bool conReemplazo);
        void crearVirtualData(int idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato, bool conReemplazo, pqxx::work& txn);
        void actualizarFechaVirutalData(int idData, pqxx::work& txn);
        list<DtData*> verVirtualData(EnumTipoDato tipoDato);
        list<DtData*> verVirtualDataCompleta();
        bool archivosDesactualizados(int idData);
        ~ControladorData();
};

#endif