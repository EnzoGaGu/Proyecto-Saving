#include "ControladorUsuario.h"

ControladorUsuario::ControladorUsuario(){}



void ControladorUsuario::iniciarSesion(string nick, string pass, pqxx::work& txn){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Sesion* sesion = Sesion::getSesion();
    Usuario* user;

    if(mu->member(nick, txn)){
        user = (*mu).find(nick, txn);
        if(user->getPass() == pass){
            sesion->setUsuario(user);
        } 
        else{
            throw invalid_argument("La contraseña no es correcta.");
        }
    }
    else{
        throw invalid_argument("El usuario no existe.");
    }
    
}

void ControladorUsuario::registro(string nick, string nombre, string pass, string email, string pfp, pqxx::work& txn){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();

    DtFechaHora* dtFechaHora = new DtFechaHora();
    dtFechaHora->setFechaHoraActual();

    pqxx::result usersSQL(txn.exec("SELECT * FROM usuario"));

    bool admin = false;
    if(usersSQL.empty()){
        admin = true;
    }

    if(!mu->member(nick, txn)){
        Usuario* user = new Usuario(nick, nombre, pass, email, pfp, dtFechaHora, admin);
        mu->add(user, txn);
    }
    else{
        throw invalid_argument("El nickname ya existe.");
    }
}

void ControladorUsuario::modificarUsuario(string nick, string nombre, string pass, string email, string pfp){
    
}

DtUsuario* ControladorUsuario::getDtUsuarioActual(){
    Sesion* sesion = Sesion::getSesion();
    Usuario* user = sesion->getUsuario();

    DtUsuario* DtU = new DtUsuario(user->getNick(), user->getNombre(), user->getPass(), user->getEmail(), user->getPfp(), user->getFechaInsc(), user->getAdmin(), user->listData());

    return DtU;
}

ControladorUsuario::~ControladorUsuario(){}