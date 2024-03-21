#include "ControladorJuego.h"

ControladorJuego::ControladorJuego(){}


void ControladorJuego::inicializar(pqxx::work& txn){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();
    mj->getFromDB(txn);
}

string ControladorJuego::nombreDeJuego(int idJuego){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();
    Juego* juegoSel = mj->find(idJuego);
    return juegoSel->getNombre();
}

//Recopila datos de un juego a agregar dados por el usuario, y los guarda en el controlador.
void ControladorJuego::recopilarDatos(string nombre, EnumPlataforma plataforma, string imgLink, string desc, list<string> archivosData, list<string> archivosConfig, list<string> directoriosData){
    this->nombreJuego = nombre;
    this->plataforma = plataforma;
    this->imgLink = imgLink; 
    this->desc = desc;
    this->archivosData = archivosData;
    this->archivosConfig = archivosConfig; 
    this->directoriosData = directoriosData;
}

//Agrega un juego a la lista global, utilizando los datos almacenados en el controlador
void ControladorJuego::agregarJuego(pqxx::work& txn){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();
    int idJuego = 0;

    if(!mj->listar().empty()){
        idJuego = mj->listar().back()->getIdJuego() + 1;
    }

    Juego* juego = new Juego(idJuego, this->nombreJuego, this->plataforma, this->imgLink, this->desc, this->archivosData, this->archivosConfig, this->directoriosData);

    mj->add(juego, txn);
}


list<DtJuego*> ControladorJuego::verJuegosBackupeadosPorJugador(string nick, pqxx::connection c){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();

    pqxx::work txn(c);

    Usuario* user = mu->find(nick, txn);

    list<DtJuego*> juegos;
    list<DtData*> dataUser;

    if(user!=NULL){
        dataUser = user->listData();
        list<DtData*>::iterator it; 
        for(it=dataUser.begin();it!=dataUser.end(); it++){
            /*
            DtJuego* datosJuego = new DtJuego((*it)->getJuego()->getIdJuego(), (*it)->getJuego()->getNombre(), (*it)->getJuego()->getPlataforma(), (*it)->getJuego()->getImgLink(), (*it)->getJuego()->getDesc(), (*it)->getJuego()->getArchivosData(), (*it)->getJuego()->getDirectoriosData());
            juegos.push_back(datosJuego);
            */
        }
    }
    return juegos;
}


//Devuelve una lista de todos los juegos almacenados en el sistema
list<DtJuego*> ControladorJuego::listarJuegos(){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    list<Juego*> juegos = mj->listar();

    list<DtJuego*> DtJuegos; 

    list<Juego*>::iterator it; 

    for(it = juegos.begin(); it!=juegos.end(); it++){
        DtJuego* DtJ = new DtJuego((*it)->getIdJuego(), (*it)->getNombre(), (*it)->getPlataforma(), (*it)->getImgLink(), (*it)->getDesc(), (*it)->getArchivosData(), (*it)->getArchivosConfig(), (*it)->getDirectoriosData());
        DtJuegos.push_back(DtJ);
    }

    return DtJuegos;
}

void ControladorJuego::modificarDatosJuego(int idJuego, string nombre, string imgLink, string desc, pqxx::work& txn){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    mj->modify(idJuego, nombre, imgLink, desc, txn);
}

ControladorJuego::~ControladorJuego(){}