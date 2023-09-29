#ifndef MEMCARD
#define MEMCARD
#include <list>
#include <string>
#include "PartidaGuardada.h"
#include "enumTipo.h"
#include "DtJuego.h"


class MemCard : public PartidaGuardada{
    private: 
        list<DtJuego*> juegosAlmacenados;
    public: 
        MemCard();
        MemCard(string idPartida, string nombreJuego, string nombrePartida, string directorio, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumTipo tipo, list<DtJuego*> juegosAlmacenados);
        void setJuegosAlmacenados(list<DtJuego*> juegosAlmacenados);
        list<DtJuego*> getJuegosAlmacenados();
};

#endif