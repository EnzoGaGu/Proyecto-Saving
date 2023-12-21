#include "DtData.h"

DtData::DtData(){}

DtData::DtData(int idData, Juego* juego, string nombreData, list<string> directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato){
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

int DtData::getIdData(){
    return this->idData;
}

Juego* DtData::getJuego(){
    return this->juego;
}

string DtData::getNombreData(){
    return this->nombreData;
}

list<string> DtData::getDirectorioLocal(){
    return this->directorioLocal;
}

string DtData::getDirectorioCloud(){
    return this->directorioCloud;
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



ostream& operator <<(ostream& salida,const DtData& a) {
	cout << "ID: " << a.idData << endl;
    cout << "Nombre: " << a.nombreData << endl; 
    cout << "Nombre del juego: " << a.juego->getNombre() << endl;
    cout << "Comentarios del jugador: " << a.comentariosJugador << endl;
    cout << "Plataforma de los datos: " << a.plataformaFuente << endl; 
    cout << "Tipo de datos: " << a.tipoDato << endl; 


    cout << "Directorio local de los archivos: " << endl; 
    for(const string directorio : a.directorioLocal){
        cout << "   =>" << directorio << endl; 
    }

    cout << "Directorio del backup: " << a.directorioCloud << endl;
    cout << "Fecha de creación/última modificación: " << (*a.fechaUltModificacion) << endl; 

	return salida;
}