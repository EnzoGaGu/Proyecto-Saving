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
        int idData;                                             //Identificador de la partida. Para separar las diferentes versiones de una misma
        Juego* juego; 
        string nombreData;
        list<string> directorioLocal;                                       //Dirección del archivo en el sistema
        string directorioCloud;
        string comentariosJugador;
        DtFechaHora* fechaUltModificacion; 
        EnumFuente plataformaFuente;  
        EnumTipoDato tipoDato;
    public:
        DtData();
        DtData(int idData, Juego* juego, string nombreData, list<string> directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato);
        int getIdData();
        Juego* getJuego();
        string getNombreData();
        list<string> getDirectorioLocal();
        string getDirectorioCloud();
        string getComentariosJugador();
        DtFechaHora* getFechaUltModificacion();
        EnumFuente getPlataformaFuente();
        EnumTipoDato getTipoDato();
        ~DtData();

        friend ostream& operator <<(ostream&,const DtData&);//sobrecarga de <<
};


#endif