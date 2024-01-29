#include "ControladorUsuario.h"

ControladorUsuario::ControladorUsuario(){}



void ControladorUsuario::iniciarSesion(string nick, string pass){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    Sesion* sesion = Sesion::getSesion();
    Usuario* user;

    if(mu->member(nick)){
        user = (*mu).find(nick);
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

void ControladorUsuario::registro(string nick, string nombre, string pass, string email, string pfp, pqxx::connection c){
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();

    DtFechaHora* dtFechaHora = new DtFechaHora();
    dtFechaHora->setFechaHoraActual();

    bool admin = false;
    if(mu->getUsuarios().empty()){
        admin = true;
    }

    if(!mu->member(nick)){
        Usuario* user = new Usuario(nick, nombre, pass, email, pfp, dtFechaHora, admin);
        mu->add(user);

        pqxx::work txn(c);

        txn.exec_params("INSERT INTO usuario (nick, nombre, pass, email, pfp, fecha_insc, admin) VALUES ($1, $2, $3, $4, $5, to_custom_type($6, $7, $8, $9, $10, $11), $12)", nick, nombre, pass, email, pfp, dtFechaHora->getDia(), dtFechaHora->getMes(), dtFechaHora->getAnio(), dtFechaHora->getHora(), dtFechaHora->getMinuto(), dtFechaHora->getSegundo(), admin);

        txn.commit();
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