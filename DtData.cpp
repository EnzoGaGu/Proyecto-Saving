#include "DtData.h"

DtData::DtData(){}

DtData::DtData(int idData, int idJuego, string nombreData, list<string> directorioLocal, string directorioCloud, string comentariosJugador, DtFechaHora* fechaUltModificacion, EnumFuente plataformaFuente, EnumTipoDato tipoDato, bool conHistorial){
    this->idData = idData;
    this->idJuego = idJuego;
    this->nombreData = nombreData;
    this->directorioLocal = directorioLocal;
    this->directorioCloud = directorioCloud;
    this->comentariosJugador = comentariosJugador;
    this->fechaUltModificacion = fechaUltModificacion;
    this->plataformaFuente = plataformaFuente;
    this->tipoDato = tipoDato;
    this->conHistorial = conHistorial; 
}

int DtData::getIdData(){
    return this->idData;
}

int DtData::getJuego(){
    return this->idJuego;
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


bool DtData::getConHistorial(){
    return this->conHistorial;
}

DtData::~DtData(){}



ostream& operator <<(ostream& salida,const DtData& a) {
    ManejadorEnums* me = ManejadorEnums::getInstancia();

	cout << "ID: " << a.idData << endl;
    cout << "Nombre: " << a.nombreData << endl; 
    cout << "Id del juego: " << a.idJuego << endl;
    cout << "Comentarios del jugador: " << a.comentariosJugador << endl;
    cout << "Plataforma de los datos: " << me->fuenteToString(a.plataformaFuente) << endl; 
    cout << "Tipo de datos: " << me->tipoDatoToString(a.tipoDato) << endl; 


    cout << "Directorio local de los archivos: " << endl; 
    for(const string directorio : a.directorioLocal){
        cout << "   =>" << directorio << endl; 
    }

    cout << "Directorio del backup: " << a.directorioCloud << endl;
    cout << "Fecha de creación/última modificación: " << (*a.fechaUltModificacion) << endl; 
    cout << "Con historial: "; 
    if(a.conHistorial){
        cout << "Sí" << endl;
    }else{
        cout << "No" << endl; 
    }

	return salida;
}