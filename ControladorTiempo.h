#ifndef CONTROLADORTIEMPO
#define CONTROLADORTIEMPO
#include "IControladorTiempo.h"


class ControladorTiempo : public IControladorTiempo{
    private: 
    public: 
        ControladorTiempo();
        DtFechaHora* fechaHoraActual();
        DtFechaHora* fechaModificacionArchivo(string ruta);
        DtFechaHora* PostgreToDt(string fecha);
        ~ControladorTiempo();
};

#endif