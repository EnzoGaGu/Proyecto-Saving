#ifndef DTPARTIDAGUARDADA
#define DTPARTIDAGUARDADA
#include <string>
#include "DtFechaHora.h"
#include "EnumTipo.h"

using namespace std;

class DtPartidaGuardada{
    private:
        string idPartida;                                       //Identificador de la partida. Para separar las diferentes versiones de una misma
        string nombreJuego; 
        string directorio;                                       //Dirección del archivo en el sistema
        DtFechaHora* fechaUltModificacion; 
        EnumTipo tipo; 
    public:
        DtPartidaGuardada();
        DtPartidaGuardada(string idPartida, string nombreJuego, string directorio, DtFechaHora* fechaUltModificacion, EnumTipo tipo);
        string getIdPartida();
        string getNombreJuego();
        string getDirectorio();
        DtFechaHora* getFechaUltModificacion();
        EnumTipo getTipo();
        ~DtPartidaGuardada();
};


#endif