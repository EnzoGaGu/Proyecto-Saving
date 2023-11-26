#ifndef DTDATA
#define DTDATA
#include <string>
#include "DtFechaHora.h"
#include "EnumFuente.h"
#include "enumTipoDato.h"
#include "Juego.h"

using namespace std;

class DtData{
    private:
        string idData;                                             //Identificador de la partida. Para separar las diferentes versiones de una misma
        Juego juego; 
        string nombreData;
        string directorioLocal;                                       //Dirección del archivo en el sistema
        string directorioCloud;
        string comentariosJugador;
        DtFechaHora* fechaUltModificacion; 
        EnumFuente plataformaFuente;  
        EnumTipoDato tipoDato;
    public:
        DtData();
        DtData(string idData, Juego juego, string nombreData, string directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato);
        string getIdData();
        Juego getJuego();
        string getNombreData();
        string getDirectorioLocal();
        string getDirectorioCloud();
        string getComentariosJugador();
        DtFechaHora* getFechaUltModificacion();
        EnumFuente getPlataformaFuente();
        EnumTipoDato getTipoDato();
        ~DtData();
};


#endif