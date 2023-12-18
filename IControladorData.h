#ifndef ICONTROLADORDATA
#define ICONTROLADORDATA

class IControladorData{
    private:
    public:
        virtual list<string> encontrarArchivosPorJuego(int idJuego) = 0;
        virtual string encontrarArchivo(string directorio, string archivo) = 0;
        virtual void seleccionarDirectorioLocal(string seleccionado) = 0;
        virtual void crearCarpetaBackup(string directorioBackup, int idJuego, DtFechaHora* fecha, EnumTipoDato tipoDato, bool conReemplazo) = 0;
        virtual void backupearDatos(bool conReemplazo) = 0;
        virtual void crearVirtualData(int idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato) = 0;
};

#endif