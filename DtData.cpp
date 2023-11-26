#include "DtData.h"

DtData::DtData(){}

DtData::DtData(string idData, Juego juego, string nombreData, string directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato){
    this->idData = idData;
    this->juego = juego;
    this->nombreData = nombreData;
    this->directorioLocal = directorioLocal;
    this->directorioCloud = directorioCloud;
    this->comentariosJugador = comentariosJugador;
    this->fechaUltModificacion = fechaUltModificacion;
    this->plataformaFuente = plataformaFuente;
    this->tipoDato = tipoDato;
}

string DtData::getIdData(){
    return this->idData;
}

Juego DtData::getJuego(){
    return this->juego;
}

string DtData::getNombreData(){
    return this->nombreData;
}

string DtData::getDirectorioLocal(){
    return this->directorioLocal;
}

string DtData::getDirectorioCloud(){
    return this->directorioLocal;
}

string DtData::getComentariosJugador(){
    return this->comentariosJugador;
}

DtFechaHora* DtData::getFechaUltModificacion(){
    return this->fechaUltModificacion;
}

EnumFuente DtData::getPlataformaFuente(){
    return this->plataformaFuente;
}

EnumTipoDato DtData::getTipoDato(){
    return this->tipoDato;
}

DtData::~DtData(){}