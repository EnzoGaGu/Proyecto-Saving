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

    cout << seleccionado;

    const char *ruta = seleccionado.c_str();

    char *ultimoSeparador = strrchr(ruta, '/');

    cout << *ruta; 

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

        this->directorioLocal = directorio;
        this->nombreArchivo = nombreA;

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

    if(conReemplazo){
        fs::remove(this->directorioBackup + "/" + this->nombreArchivo);
        //fs::create_directory(this->directorioBackup);
        cout << directorioBackup;
    }

    //replace(directorioBackup.begin(), directorioBackup.end(), '\\', '/');

    string ogPath = this->directorioLocal + "/" + this->nombreArchivo;
    string newPath = this->directorioBackup + "/" + this->nombreArchivo;

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
}

//Crea un objeto de clase Data, y lo almacena en el usuario que inició sesión
void ControladorData::crearVirtualData(int idJuego, string nombreData, string comentariosJugador, DtFechaHora* fechaCreacionData, EnumFuente plataforma, EnumTipoDato tipoDato){
    ManejadorJuego* mj = ManejadorJuego::getInstancia();

    Juego* juego = mj->find(idJuego);
    int idData; 

    Sesion* sesion = Sesion::getSesion();
    Usuario* user = sesion->getUsuario();

    if(!user->listData().empty()){
        idData = user->listData().back()->getIdData() + 1;
    }
    else{
        idData = 0; 
    }

    Data* newData = new Data(idData, juego, nombreData, this->directorioLocal, this->directorioBackup, comentariosJugador, fechaCreacionData, plataforma, tipoDato);

    user->addData(newData);
}

ControladorData::~ControladorData(){}