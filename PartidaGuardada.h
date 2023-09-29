#ifndef PARTIDAGUARDADA
#define PARTIDAGUARDADA
#include <string>
#include "DtFechaHora.h"
#include "EnumTipo.h"

using namespace std;

class PartidaGuardada{
    private:
        string idPartida;                                       //Identificador de la partida. Para separar las diferentes versiones de una misma
        string nombreJuego; 
        string nombrePartida;
        string directorio;                                       //Dirección del archivo en el sistema
        string comentariosJugador;
        DtFechaHora* fechaUltModificacion; 
        EnumTipo tipo; 
    public:
        PartidaGuardada();
        PartidaGuardada(string idPartida, string nombreJuego, string nombrePartida, string directorio, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumTipo tipo);
        string getIdPartida();
        void setIdPartida(string idPartida);
        string getNombreJuego();
        void setNombreJuego(string nombreJuego);
        string getDirectorio();
        void setDirectorio(string directorio);
        DtFechaHora* getFechaUltModificacion();
        void setFechaUltModificacion(DtFechaHora* fechaUltModificacion);
        void setTipo(EnumTipo tipo);
        EnumTipo getTipo();
        ~PartidaGuardada();
};


#endif