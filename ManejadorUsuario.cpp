#include "ManejadorUsuario.h"

ManejadorUsuario * ManejadorUsuario::instancia=NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia==NULL){
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

list<Usuario*> ManejadorUsuario::getUsuarios(){
    list<Usuario*> usuarios; 
    return usuarios;
}


void ManejadorUsuario::add(Usuario* usuario, pqxx::work& txn){

    txn.exec_params("INSERT INTO usuario (nick, nombre, pass, email, pfp, fecha_insc, admin) VALUES ($1, $2, $3, $4, $5, to_custom_type($6, $7, $8, $9, $10, $11), $12)", usuario->getNick(), usuario->getNombre(), usuario->getPass(), usuario->getEmail(), usuario->getPfp(), usuario->getFechaInsc()->getDia(), usuario->getFechaInsc()->getMes(), usuario->getFechaInsc()->getAnio(), usuario->getFechaInsc()->getHora(), usuario->getFechaInsc()->getMinuto(), usuario->getFechaInsc()->getSegundo(), usuario->getAdmin());
    txn.commit();
}


bool ManejadorUsuario::member(string nick, pqxx::work& txn){
    bool member = false;
    
    string sql = "SELECT nick, nombre, pass, email, pfp, fecha_insc, admin FROM usuario WHERE nick = '" + nick + "'";

    pqxx::result result(txn.exec(sql));

    if(!result.empty()){
        member = true; 
    }

    return member;
}

Usuario* ManejadorUsuario::find(string nick, pqxx::work& txn){
    Usuario* usuario = NULL;
    Fabrica* factory = Fabrica::getInstancia();
    IControladorTiempo* IConT = factory->getControladorTiempo();

    string sql = "SELECT nick, nombre, pass, email, pfp, fecha_insc, admin FROM usuario WHERE nick = '" + nick + "'";

    pqxx::result result(txn.exec(sql));

    for (const auto& row : result) {
        usuario = new Usuario();

        usuario->setNick(row["nick"].as<string>());

        usuario->setNombre(row["nombre"].as<string>());
        usuario->setPass(row["pass"].as<string>());
        usuario->setEmail(row["email"].as<string>());
        usuario->setPfp(row["pfp"].as<string>());
        // Transformar la fecha de inscripción en un objeto DtFechaHora

        string fecha_insc_str = row.at("fecha_insc").c_str();

        DtFechaHora* fechaHora = IConT->PostgreToDt(fecha_insc_str);
        usuario->setFechaInsc(fechaHora);

        usuario->setAdmin(row["admin"].as<bool>());
    }


    return usuario;
}


void ManejadorUsuario::remove(string nick, pqxx::work& txn){
    string sql = "DELETE FROM usuario WHERE nick = '" + nick + "'";

    txn.exec(sql);

    /*
    
    Falta eliminación de tuplas en tabla de Data 
    
    */




    if(!this->member(nick, txn)){
        cout << "Usuario removido con éxito" << endl; 
    }
    else{
        cout << "Error al remover el usuario" << endl; 
    }
}


ManejadorUsuario::~ManejadorUsuario(){}