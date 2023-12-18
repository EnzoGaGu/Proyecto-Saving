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

void ControladorUsuario::registro(string nick, string nombre, string pass, string email, string pfp){
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
    }
    else{
        throw invalid_argument("El nickname ya existe.");
    }
}

void ControladorUsuario::modificarUsuario(string nick, string nombre, string pass, string email, string pfp){
    
}

ControladorUsuario::~ControladorUsuario(){}