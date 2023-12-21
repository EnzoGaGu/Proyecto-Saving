#include "ControladorData.h"


ControladorData::ControladorData(){}


//Busca en el sistema todos los archivos posibles de un juego específico. Recorre todas las carpetas guardadas
list<string> ControladorData::encontrarArchivosPorJuego(int idJuego){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();
    Juego* juego = mj->find(idJuego);

    list<string> directoriosEncontrados; 

    int cont = 0; 

    string directorio; 

    if(!juego->getArchivosData().empty() && !juego->getDirectoriosData().empty()){
        list<string>::iterator it; 
        list<string>::iterator iter;
        list<string> directoriosData = juego->getDirectoriosData();
        list<string> archivosData = juego->getArchivosData();

        for(it = directoriosData.begin(); it != directoriosData.end(); it++){
            for(iter = archivosData.begin(); iter != archivosData.end(); iter++){
                directorio = encontrarArchivo((*it), (*iter));
                if(directorio != ""){
                    directoriosEncontrados.push_back(directorio);
                }
            }
        }
    }
    else{
        string msg = "El juego no tiene todos los datos necesarios registrados";
        directoriosEncontrados.push_back(msg);
    }
    return directoriosEncontrados;
}


//Comprueba que un archivo exista en el sistema. Si lo hace, retorna un string con la ruta de éste.
//Si no, retorna un string vacío
string ControladorData::encontrarArchivo(string directorio, string archivo){
    struct stat sb; 

    //cout << directorio; 
    if(stat(directorio.c_str(), &sb) == 0){
        string dirArchivo = directorio + "/" + archivo; 

        if(fs::exists(dirArchivo)){
            ifstream archivoA(dirArchivo);

            if(archivoA.good()){
                archivoA.close();
                return dirArchivo; 
            }
            archivoA.close();
        }
    }
    return "";
}



//Se le pasa la ruta del archivo que el usuario quiere backupear. El trabajo de la función es separar
//dicho string en carpeta y nombre de archivo, y guardarlos en las variables correspondientes del controlador.
void ControladorData::seleccionarDirectorioLocal(string seleccionado){
    string directorioLocal, nombreArchivo; 

    const char *ruta = seleccionado.c_str();

    char *ultimoSeparador = strrchr(ruta, '/');

    if(ultimoSeparador != NULL){
        int posicionSeparador = ultimoSeparador - seleccionado.c_str();

        //Crear arrays del largo necesario
        char rutaDirectorio[posicionSeparador + 1];
        char nombreArchivo[strlen(ruta) - posicionSeparador];

        //Copiar el directorio
        strncpy(rutaDirectorio, ruta, posicionSeparador);
        rutaDirectorio[posicionSeparador] = '\0';

        string directorio(rutaDirectorio);

        //Copiar el nombre del archivo
        strcpy(nombreArchivo, ultimoSeparador + 1);

        string nombreA(nombreArchivo);

        this->directorioLocal.push_back(directorio);
        this->nombreArchivo.push_back(nombreA);
        this->directorioLocalCompleto.push_back(seleccionado);
    }
    else{
        cout << "La ruta no contiene un separador válido" << endl; 
    }
}


//Comprueba si las carpetas necesarias para realizar el backup existen en la ruta dada por el usuario, y guarda la dirección en el controlador. Si éstas no están presentes, las crea.
//Tiene en cuenta si el usuario está queriendo hacer un backup con o sin historial.
void ControladorData::crearCarpetaBackup(string directorioBackup, int idJuego, DtFechaHora* fecha, EnumTipoDato tipoDato, bool conReemplazo){
    struct stat sb;
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    replace(directorioBackup.begin(), directorioBackup.end(), '\\', '/');

    string nombreJuego = mj->find(idJuego)->getNombre();

    string directorioJuego = directorioBackup + "/" + nombreJuego;
    string reem = directorioJuego + "/Reemplazo";
    string noReem = directorioJuego + "/SinReemplazo"; 
    string directorioCompleto; 
    bool exit = false;
    int count = 0; 

    while(!exit){
        if(stat(directorioBackup.c_str(), &sb)==0){
            if(stat(directorioJuego.c_str(), &sb) != 0){
                fs::create_directory(directorioJuego.c_str());

                fs::create_directory(reem.c_str());
                fs::create_directory(noReem.c_str());             
            }
            else{
                cout << "La carpeta de backup para este juego ya existe. Continuando." << endl; 
            }

            if(!conReemplazo){

                if(fs::is_empty(noReem)){
                    directorioCompleto = noReem + "/0";

                    fs::create_directory(directorioCompleto.c_str());
                }
                else{
                    fs::path p1 { noReem };

                    for (auto& p : fs::directory_iterator(p1))
                    {
                        ++count;
                    }

                    string folder = "/" + count;


                    directorioCompleto = noReem + folder; 
                }

                fs::create_directory(directorioCompleto.c_str());
                this->directorioBackup = directorioCompleto;
                exit = true; 
            }
            else{
                this->directorioBackup = reem.c_str();
                exit = true; 
            }
        }
        else{
            fs::create_directory(directorioBackup.c_str());
        }
    }
    
}


//Backupea el archivo especificado en la función SeleccionarArchivoLocal, en la carpeta elegida en CrearCarpetaBackup.
//Tiene en cuenta si el usuario quiere reemplazar o no.
void ControladorData::backupearDatos(bool conReemplazo){

    list<string>::iterator it = this->nombreArchivo.begin();

    for(const string directorio : this->directorioLocal){


        if(conReemplazo){
            fs::remove(this->directorioBackup + "/" + *it);
            //fs::create_directory(this->directorioBackup);
        }

        //replace(directorioBackup.begin(), directorioBackup.end(), '\\', '/');

        string ogPath = directorio + "/" + *it;
        string newPath = this->directorioBackup + "/" + *it;

        ifstream ogFile(ogPath, ios::binary);

        if(!ogFile){
            cerr << "Error al abrir el archivo a backupear." << endl; 
        }
        else{
            ofstream newFile(newPath, ios::binary);
            if(!newFile){
                cerr << "Error al crear el archivo backup." << endl;
            }
            else{
                newFile << ogFile.rdbuf();
                ogFile.close();
                newFile.close();

                cout << "Archivo copiado exitosamente." << endl; 
            }
        }

        if(it!=this->nombreArchivo.end()){
            advance(it, 1);
        }

        //cout << *it; 
    }

}

//Crea un objeto de clase Data, y lo almacena en el usuario que inició sesión
void ControladorData::crearVirtualData(int idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    Juego* juego = mj->find(idJuego);
    int idData; 
    bool encontrado; 

    Sesion* sesion = Sesion::getSesion();
    Usuario* user = sesion->getUsuario();
    list<DtData*> userData = user->listData();

    if(!userData.empty()){
        list<DtData*>::iterator it; 
        for(it=userData.begin(); it!=userData.end(); it++){
            if(this->directorioBackup == (*it)->getDirectorioCloud()){
                user->findData((*it)->getIdData())->setFechaUltModificacion(fechaCreacionData);

                encontrado = true; 
            }
        }
        if(!encontrado){
            idData = user->listData().back()->getIdData() + 1;
        }
    }
    else{
        idData = 0; 
    }



    if(!encontrado){
        Data* newData = new Data(idData, juego, nombreData, this->directorioLocalCompleto, this->directorioBackup, comentariosJugador, fechaCreacionData, plataforma, tipoDato);
        user->addData(newData);
    }
    
    this->directorioBackup.clear();
    this->directorioLocal.clear();
    this->directorioLocalCompleto.clear();
}


list<DtData*> ControladorData::verVirtualData(EnumTipoDato tipoDato){
    Sesion* sesion = Sesion::getSesion();
    Usuario* user = sesion->getUsuario();

    list<DtData*> allData = user->listData();

    list<DtData*> selectedData; 

    list<DtData*>::iterator it; 
    for(it=allData.begin();it!=allData.end(); it++){
        if((*it)->getTipoDato() == tipoDato){
            cout << "Tipo de dato en user: " << (*it)->getTipoDato() << endl;
            cout << "Tipo de dato dado: " << tipoDato << endl; 
            cout << (*(*it)); 

            selectedData.push_back((*it));
        }
    }

    return selectedData;
}

ControladorData::~ControladorData(){}