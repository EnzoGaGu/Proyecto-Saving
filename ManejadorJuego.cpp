#include "ManejadorJuego.h"

ManejadorJuego* ManejadorJuego::instancia=NULL;

ManejadorJuego::ManejadorJuego(){}

ManejadorJuego* ManejadorJuego::getInstancia(){
    if (instancia==NULL){
        instancia = new ManejadorJuego();
    }
    return instancia;
}


void ManejadorJuego::getFromDB(pqxx::work& txn){
    ManejadorEnums* me = ManejadorEnums::getInstancia();
    string sql = "SELECT * FROM juego";

    pqxx::result result(txn.exec(sql));


    for(const auto& row : result){
        Juego* game = new Juego();


        game->setIdJuego(row["id_juego"].as<int>());
        game->setNombre(row["nombre"].as<string>());

        string plataforma = row["plataforma"].as<string>();
        EnumPlataforma enumPlat = me->stringToPlataforma(plataforma);
        game->setPlataforma(enumPlat);

        game->setImgLink(row["img_link"].as<string>());
        game->setDesc(row["descripcion"].as<string>());

        string archivos_data = row["archivos_data"].as<string>();

        list<string> archivosData;
        // Elimina los caracteres especiales y el corchete al principio y al final
        archivos_data = archivos_data.substr(1, archivos_data.size() - 2);
        
        istringstream iss(archivos_data);
        string token;
        char delimiter = ',';

        while (getline(iss, token, delimiter)) {
            // Elimina las comillas y espacios alrededor del nombre de archivo
            size_t start = token.find('\'');
            size_t end = token.find_last_of('\'');
            archivosData.push_back(token.substr(start + 1, end - start - 1));
        }

        game->setArchivosData(archivosData);


        string directorios_data = row["directoriosdata"].as<string>();
        
        list<string> directoriosData;

        directorios_data = directorios_data.substr(1, directorios_data.size() - 2);

        istringstream issd(directorios_data);

        while(getline(issd, token, delimiter)){
            size_t start = token.find('\'');
            size_t end = token.find_last_of('\'');
            directoriosData.push_back(token.substr(start+1, end-start-1));
        }

        game->setDirectoriosData(directoriosData);

        this->juegos.push_back(game);
    }

    txn.abort();
}

void ManejadorJuego::add(Juego* juego, pqxx::work& txn){
    ManejadorEnums* me = ManejadorEnums::getInstancia();
    juegos.push_back(juego);

    string archivos, directorios; 

    list<string> archivosJuego = juego->getArchivosData(); 
    list<string> directoriosJuego = juego->getDirectoriosData(); 

    list<string>::iterator it; 

    archivos = '{';

    for(it=archivosJuego.begin();it!=archivosJuego.end(); it++){
        archivos += "'" + (*it) + "',";
    }
    archivos.back()= '}';

    directorios = '{';
    for(it=directoriosJuego.begin();it!=directoriosJuego.end(); it++){
        directorios += "'" + (*it) + "',";
    }
    directorios.back() = '}';

    string plat = me->plataformaToString(juego->getPlataforma());

    txn.exec_params("INSERT INTO juego (id_juego, nombre, plataforma, img_link, descripcion, archivos_data, directoriosdata) VALUES ($1, $2, $3, $4, $5, $6, $7)", juego->getIdJuego(), juego->getNombre(), plat, juego->getImgLink(), juego->getDesc(), archivos, directorios);

    txn.commit();
    //cout << "Ingresado con éxito";
}

bool ManejadorJuego::member(int idJuego){
    bool member = false;
    list<Juego*>::iterator it;
    for(it=this->juegos.begin(); it!=this->juegos.end(); it++){
        if((*it)->getIdJuego() == idJuego){
            member = true;
        }
    }
    return member;
}

Juego* ManejadorJuego::find(int idJuego){
    Juego* juego = NULL;
    list<Juego*>::iterator it;
    for(it=this->juegos.begin(); it!=this->juegos.end(); it++){
        if((*it)->getIdJuego() == idJuego){
            juego = (*it);
        }
    }
    return juego;
}

void ManejadorJuego::remove(int idJuego){
    Juego* juego;

    list<Juego*>::iterator it;
    for(it=juegos.begin(); it!=juegos.end(); it++){
        if((*it)->getIdJuego() == idJuego){
            juego = (*it);
            juegos.remove(*it);
            delete juego;
        }
    }
}

list<Juego*> ManejadorJuego::listar(){
    return this->juegos;
}

ManejadorJuego::~ManejadorJuego(){}