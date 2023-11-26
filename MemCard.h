#ifndef MEMCARD
#define MEMCARD
#include <list>
#include <string>
#include "Data.h"
#include "enumPlataforma.h"
#include "DtJuego.h"


class MemCard : public Data{
    private: 
        list<DtJuego*> juegosAlmacenados;
    public: 
        MemCard();
        MemCard(string idData, Juego juego, string nombreData, string directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato, list<DtJuego*> juegosAlmacenados);
        void setJuegosAlmacenados(list<DtJuego*> juegosAlmacenados);
        list<DtJuego*> getJuegosAlmacenados();
};

#endif