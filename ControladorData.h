#ifndef CONTROLADORDATA
#define CONTROLADORDATA
#include <string>
#include "IControladorData.h"
#include "DtFechaHora.h"
#include "enumTipoDato.h"

using namespace std;

class ControladorData : public IControladorData{
    private:
        string idData;
        string path;
        string directorioLocal;
        string directorioBackup;
    public:
        ControladorData();
        void encontrarArchivo(string directorio, string extension);
        void crearCarpetaBackup(string directorioBackup, string nombreJuego, DtFechaHora* fecha, EnumTipoDato tipoDato, bool conReemplazo);
        void backupearDatosConReemplazo();
        void backupearDatosSinReemplazo();
        ~ControladorData();
};

#endif