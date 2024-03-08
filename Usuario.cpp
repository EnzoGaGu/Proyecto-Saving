#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string nick, string nombre, string pass, string email, string pfp, DtFechaHora* fechaInsc, bool admin){
    this->nick = nick;
    this->nombre = nombre;
    this->pass = pass;
    this->email = email;
    this->pfp = pfp; 
    this->fechaInsc = fechaInsc; 
    this->admin = admin;
}

void Usuario::setNick(string nick){
    this->nick = nick;
}

string Usuario::getNick(){
    return this->nick;
}

void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}

string Usuario::getNombre(){
    return this->nombre;
}

void Usuario::setPass(string pass){
    this->pass = pass;
}

string Usuario::getPass(){
    return this->pass;
}

void Usuario::setEmail(string email){
    this->email = email;
}

string Usuario::getEmail(){
    return this->email;
}

void Usuario::setPfp(string pfp){
    this->pfp = pfp;
}

string Usuario::getPfp(){
    return this->pfp;
}

void Usuario::setFechaInsc(DtFechaHora* fechaInsc){
    this->fechaInsc = fechaInsc;
}

DtFechaHora* Usuario::getFechaInsc(){
    return this->fechaInsc;
}

void Usuario::setAdmin(bool admin){
    this->admin = admin;
}

bool Usuario::getAdmin(){
    return this->admin;
}

void Usuario::getDataFromDB(pqxx::work& txn){
    string sql = "SELECT d.* FROM data_agregada da JOIN data d ON da.id_data = d.id_data JOIN usuario u ON da.id_usuario = u.id_usuario WHERE u.id_usuario = " + this->nick;
    Fabrica* factory = Fabrica::getInstancia();
    IControladorTiempo* IConT = factory->getControladorTiempo();

    IControladorEnums* IConE = factory->getControladorEnums();

    pqxx::result result(txn.exec(sql));

    for(const auto& row : result){
        Data* info = new Data();

        info->setIdData(row["id_data"].as<int>());
        info->setJuego(row["id_juego"].as<int>());
        info->setNombreData(row["nombre_data"].as<string>());
        
        string directorio_local = row["directorio_local"].as<string>();

        list<string> directoriosLocales;

        directorio_local = directorio_local.substr(1, directorio_local.size() - 2);

        istringstream iss(directorio_local);
        string token; 
        char delimiter = ',';

        while(getline(iss, token, delimiter)){
            size_t start = token.find('\'');
            size_t end = token.find_last_of('\'');
            directoriosLocales.push_back(token.substr(start + 1, end - start - 1));
        }

        info->setDirectorioLocal(directoriosLocales);
        
        
        info->setDirectorioCloud(row["directorio_cloud"].as<string>());
        info->setComentariosJugador(row["comentarios_jugador"].as<string>());

        string fecha_ult_mod = row.at("fecha_ult_modificacion").c_str();
        DtFechaHora* fechaHora = IConT->PostgreToDt(fecha_ult_mod);
        info->setFechaUltModificacion(fechaHora);

        string pFuente = row["plataforma_fuente"].as<string>();
        EnumFuente ePFuente = IConE->stringToFuente(pFuente);
        info->setPlataformaFuente(ePFuente);

        string tDato = row["tipo_dato"].as<string>();
        EnumTipoDato eTDato = IConE->stringToTipoDato(tDato);
        info->setTipoDato(eTDato);
        
        info->setConHistorial(row["con_historial"].as<bool>());

        this->dataAgregada.push_back(info);
    }
}

void Usuario::addData(Data* data, pqxx::work& txn){
    this->dataAgregada.push_back(data);

    Fabrica* factory = Fabrica::getInstancia();
    IControladorEnums* IConE = factory->getControladorEnums();
    
    string directorios; 

    list<string> directorioLocal = data->getDirectorioLocal();

    list<string>::iterator it; 

    directorios = '{';

    for(it=directorioLocal.begin();it!=directorioLocal.end(); it++){
        directorios += "'" + (*it) + "',";
    }
    
    directorios.back() = '}';

    string pFuente = IConE->fuenteToString(data->getPlataformaFuente());
    string tipoDato = IConE->tipoDatoToString(data->getTipoDato());

    txn.exec_params("INSERT INTO data (id_data, id_juego, nombre_data, directorio_local, directorio_cloud, comentarios_jugador, fecha_ult_modificacion, plataforma_fuente, tipo_dato, con_historial) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10)", data->getIdData(), data->getJuego(), data->getNombreData(), directorios, data->getDirectorioCloud(), data->getComentariosJugador(), data->getFechaUltModificacion(), pFuente, tipoDato, data->getConHistorial());
    txn.commit();
}

Data* Usuario::findData(int idData){
    if(memberData(idData) == true){
        list<Data*>::iterator it;
        for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
            if((*it)->getIdData() == idData){
                return (*it);
            }
        }
    }
    else{
        return NULL;
    }
}

bool Usuario::memberData(int idData){
    bool exists = false;

    list<Data*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        if((*it)->getIdData() == idData){
            exists = true;
        }
    }
    return exists;
}

DtData* Usuario::getDtData(int idData){
    Data* data = findData(idData);
    DtData* dtData; 

    if(data!=NULL){
        dtData = new DtData(data->getIdData(), data->getJuego(), data->getNombreData(), data->getDirectorioLocal(), data->getDirectorioCloud(), data->getComentariosJugador(), data->getFechaUltModificacion(), data->getPlataformaFuente(), data->getTipoDato(), data->getConHistorial());
    }
    else{
        dtData = NULL;
    }

    return dtData;
}

list<DtData*> Usuario::listData(){
    list<DtData*> lista;

    list<Data*>::iterator it;
    for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
        DtData* data = new DtData((*it)->getIdData(), (*it)->getJuego(), (*it)->getNombreData(), (*it)->getDirectorioLocal(), (*it)->getDirectorioCloud(), (*it)->getComentariosJugador(), (*it)->getFechaUltModificacion(), (*it)->getPlataformaFuente(), (*it)->getTipoDato(), (*it)->getConHistorial());
        lista.push_back(data);
    }

    return lista;
}

void Usuario::removeData(int idData){
    Data* forRemove; 

    if(memberData(idData) == true){
        list<Data*>::iterator it;
        for(it=this->dataAgregada.begin(); it!=this->dataAgregada.end(); it++){
            if((*it)->getIdData() == idData){
                
            }
        }
    }
}

Usuario::~Usuario(){}