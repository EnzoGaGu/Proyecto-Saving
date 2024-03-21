#include "DtJuego.h"


DtJuego::DtJuego(){}

DtJuego::DtJuego(int idJuego, string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> archivosConfig, list<string> directoriosData){
    this->idJuego = idJuego;
    this->nombre = nombre; 
    this->plataforma = plataforma;
    this->imgLink = imgLink;
    this->desc = desc;
    this->archivosData = archivosData;
    this->archivosConfig = archivosConfig; 
    this->directoriosData = directoriosData;
}


int DtJuego::getIdJuego(){
    return this->idJuego;
}

string DtJuego::getNombre(){
    return this->nombre;
}

EnumPlataforma DtJuego::getPlataforma(){
    return this->plataforma; 
}

string DtJuego::getImgLink(){
    return this->imgLink;
}

string DtJuego::getDesc(){
    return this->desc;
}

list<string> DtJuego::getArchivosData(){
    return this->archivosData;
}

list<string> DtJuego::getArchivosConfig(){
    return this->archivosConfig;
}

list<string> DtJuego::getDirectoriosData(){
    return this->directoriosData;
}


DtJuego::~DtJuego(){}


ostream& operator <<(ostream& salida,const DtJuego& a) {
    ManejadorEnums* me = ManejadorEnums::getInstancia();
    
	cout << "ID: " << a.idJuego << endl;
    cout << "Nombre: " << a.nombre << endl;
    cout << "Plataforma: " << me->plataformaToString(a.plataforma) << endl;
    cout << "Descripción: " << a.desc << endl;


    cout << "Directorios locales: " << endl; 
    for(const string directorio : a.directoriosData){
        cout << "   =>" << directorio << endl; 
    }

    cout << "Nombres de archivos de partidas guardadas: " << endl; 
    for(const string archivo : a.archivosData){
        cout << "   =>" << archivo << endl; 
    }

    cout << "Nombres de archivos de configuración: " << endl; 
    for(const string archivo : a.archivosConfig){
        cout << "   =>" << archivo << endl; 
    }

	return salida;
}