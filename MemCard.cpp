#include "MemCard.h"

MemCard::MemCard(){
}

MemCard::MemCard(string idPartida, string nombreJuego, string nombrePartida, string directorio, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumTipo tipo, list<DtJuego*> juegosAlmacenados):PartidaGuardada(idPartida, nombreJuego, nombrePartida, directorio, comentariosJugador, fechaUltModificacion, tipo){
    this->juegosAlmacenados = juegosAlmacenados;
}

void MemCard::setJuegosAlmacenados(list<DtJuego*> juegosAlmacenados){
    this->juegosAlmacenados = juegosAlmacenados;
}

list<DtJuego*> MemCard::getJuegosAlmacenados(){
    return juegosAlmacenados;
}