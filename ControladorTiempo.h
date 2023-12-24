#ifndef CONTROLADORTIEMPO
#define CONTROLADORTIEMPO
#include "IControladorTiempo.h"


class ControladorTiempo : public IControladorTiempo{
    private: 
    public: 
        ControladorTiempo();
        DtFechaHora* fechaHoraActual();
        DtFechaHora* fechaModificacionArchivo(string ruta);
        ~ControladorTiempo();
};

#endif