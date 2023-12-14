#ifndef DATA
#define DATA
#include <string>
#include "DtFechaHora.h"
#include "enumFuente.h"
#include "enumTipoDato.h"
#include "Juego.h"

using namespace std;

class Data{
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
        Data();
        Data(string idData, Juego juego, string nombreData, string directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato);
        string getIdData();
        void setIdData(string idData);
        Juego getJuego();
        void setJuego(Juego juego);
        string getNombreData();
        void setNombreData(string nombreData);
        string getDirectorioLocal();
        void setDirectorioLocal(string directorioLocal);
        string getDirectorioCloud();
        void setDirectorioCloud(string directorioCloud);
        string getComentariosJugador();
        void setComentariosJugador(string comentariosJugador);
        DtFechaHora* getFechaUltModificacion();
        void setFechaUltModificacion(DtFechaHora* fechaUltModificacion);
        EnumFuente getPlataformaFuente();
        void setPlataformaFuente(EnumFuente plataformaFuente);
        EnumTipoDato getTipoDato();
        void setTipoDato(EnumTipoDato tipoDato);
        ~Data();
};


#endif