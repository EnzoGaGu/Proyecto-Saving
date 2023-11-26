#include "MemCard.h"

MemCard::MemCard(){
}

MemCard::MemCard(string idData, Juego juego, string nombreData, string directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato, list<DtJuego*> juegosAlmacenados):Data(idData, juego, nombreData, directorioLocal, directorioCloud, comentariosJugador, fechaUltModificacion, plataformaFuente, tipoDato){
    this->juegosAlmacenados = juegosAlmacenados;
}

void MemCard::setJuegosAlmacenados(list<DtJuego*> juegosAlmacenados){
    this->juegosAlmacenados = juegosAlmacenados;
}

list<DtJuego*> MemCard::getJuegosAlmacenados(){
    return juegosAlmacenados;
}