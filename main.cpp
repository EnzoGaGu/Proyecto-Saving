#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <sys/stat.h>
//#include <dirent.h>
#include <fstream>
#include <winbase.h>
#include <map>
#include <pqxx/pqxx>
//#include <mysql_driver.h>
//#include <mysql_connection.h>
//#include <boost/filesystem.hpp>
#include "DtFechaHora.h"
#include "IControladorUsuario.h"
#include "IControladorJuego.h"
#include "IControladorData.h"
#include "Sesion.h"
#include "Fabrica.h"
#include <winerror.h>
#include <ShlObj.h>
#include <algorithm>
#include <wchar.h>

#pragma comment(lib, "shell32.lib")

using namespace std; 



//char* diagonal = "/";
Fabrica* factory;
IControladorUsuario* iConU;
IControladorJuego* iConJ;
IControladorData* iConD; 
Sesion* sesion;
bool sesionI;
pqxx::connection c("dbname=postgres user=postgres password=admin hostaddr=127.0.0.1 port=5432");

//Precarga usuarios y juegos, para probar el sistema sin necesidad de persistencia.
void precargarDatos();


//Iniciar sesión en el sistema a través de un usuario ya creado.
void IniciarSesion();


//Registrar un nuevo usuario en el sistema. Si no existe ninguno (no se precargaron datos), el primero siempre será admin.
void Registro();


//Agregar un juego al sistema (solo admins).
void agregarJuegoAlSistema();


//Respaldar una partida.
void respaldarDatos();


//Ver los datos respaldados por el usuario que inició sesión
void verRespaldos(int opcion);

//Actualizar todos los respaldos del usuario, comprobando si los archivos de éstos están up-to-date con los del sistema. 
void actualizarRespaldos();

//Comprobar si existe un archivo con el nombre "archivo" en la ruta "directorio".
bool archivoExiste(const char* directorio, string archivo);


//Listar todos los juegos registrados en el sistema. 
void listarJuegos();


//Lista los juegos para los que el usuario tiene algún backup en el sistema. Si un admin ejecuta esta función, puede ver los juegos registrados de otros usuarios.
void verJuegosPorUsuario();


//void copiarArchivoReemplazando(const char* ubIn, const char* ubBackup, string nombreArchivo, const char* nombreJuego, const char* nombreSaved);

//Permite a un admin modificar los datos de un juego ya agregado al sistema
void modificarDatosJuego();


int main(){
    c.set_client_encoding("UTF8");
    // Start a transaction.  In libpqxx, you always work in one.
    if (c.is_open()) {
        std::cout << "Conexión exitosa a la base de datos PostgreSQL" << std::endl;
    } else {
        std::cout << "Error de conexión a la base de datos PostgreSQL" << std::endl;
        return 1;
    }

    factory = Fabrica::getInstancia();
    iConU = factory->getControladorUsuario();
    iConJ = factory->getControladorJuego();
    iConD = factory->getControladorData();
    sesion = Sesion::getSesion();

    pqxx::work txnini(c);
    iConJ->inicializar(txnini);

    int opt;
    sesionI = false; 
    bool salir = false;
    bool cerrar = false;  

    precargarDatos();

    while(sesionI == false && cerrar == false){
        cout << "==================¡Bienvenido!==================" << endl;
        cout << "   1: Iniciar sesión" << endl;
        cout << "   2: Registrarse" << endl;
        cout << "   0: Salir"   << endl;
        cout << "Ingrese una opción: " << endl;
        cin >> opt; 

        switch(opt){
            case 1: 
                IniciarSesion();
            break;
            case 2: 
                Registro();
            break;
            case 0: 
                salir = true; 
                cerrar = true; 
            break; 
            default: 
                cout << "La opción no es válida. Reintente" << endl;  
            break; 
        }    
    }

    if(sesionI == true){
        cout << "Sesión iniciada con éxito." << endl;
        while(salir == false){
            if(!sesion->getUsuario()->getAdmin()){                                          //Si es usuario normal
                cout << "================================================" << endl;
                cout << "   1: Crear respaldo" << endl;
                cout << "   2: Actualizar respaldos" << endl;
                cout << "   3: Ver juegos agregados" << endl;
                cout << "   4: Ver respaldos de partidas" << endl;
                cout << "   5: Ver respaldos de configuraciones" << endl;
                cout << "   6: Ver todos los respaldos" << endl;
                cout << "   7: Subir a la nube" << endl;
                cout << "   8: Descargar de la nube" << endl;
                cout << "   9: Actualizar rutas juego" << endl;
                cout << "   10: Cambiar usuario" << endl;
                cout << "   0: Salir"   << endl;
                cout << "Ingrese una opción: " << endl;
                cin >> opt; 

                switch(opt){
                    case 1: 
                        respaldarDatos();
                    break;
                    case 2: 
                        actualizarRespaldos();
                    break;
                    case 3: 
                        verJuegosPorUsuario();
                    break;
                    case 4: 
                        verRespaldos(0);
                    break;
                    case 5: 
                        verRespaldos(1);
                    break;
                    case 6: 
                    break;
                    case 7:
                    break;
                    case 8: 
                    break;
                    case 9: 
                    break;
                    case 10: 
                    break;
                    case 0:
                        salir = true; 
                        cerrar = true; 
                    break;
                    default:
                        cout << "La opción no es válida. Reintente" << endl; 
                    break;
                }
            }
            else{                                                                          //Si es admin
                cout << "================================================" << endl;
                cout << "   1: Agregar juego al sistema" << endl;
                cout << "   2: Ver juegos en el sistema" << endl;
                cout << "   3: Ver juegos por usuario" << endl;
                cout << "   4: Modificar datos juego" << endl;
                cout << "   5: Ver usuarios" << endl;
                cout << "   6: Cambiar usuario" << endl;
                cout << "   0: Salir"   << endl;
                cout << "Ingrese una opción: " << endl;
                cin >> opt; 

                switch(opt){
                    case 1: 
                        agregarJuegoAlSistema();
                    break;
                    case 2: 
                        listarJuegos();
                    break;
                    case 3: 
                        verJuegosPorUsuario();
                    break;
                    case 4: 
                        modificarDatosJuego();
                    break;
                    case 5: 
                    break; 
                    case 0:
                        salir = true; 
                        cerrar = true; 
                    break;
                    default:
                        cout << "La opción no es válida. Reintente" << endl; 
                    break;
                }
            }
        }
    }
}

void IniciarSesion(){
    string nick, pass; 

    pqxx::work txn(c);

    cout << "Ingrese el nickname: ";
    cin >> nick;     

    cout << "Ingrese la contraseña: ";
    cin >> pass;     

    try{
        iConU->iniciarSesion(nick, pass, txn);
        sesionI = true;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

void Registro(){
    pqxx::work txn(c);
    string nick, nombre, pass, email, pfp; 
    int opt; 

    cout << "Ingrese un nickname: ";
    cin >> nick; 

    cout << "Ingrese un nombre: ";
    cin >> nombre; 

    cout << "Ingrese una contraseña: ";
    cin >> pass; 

    cout << "Ingrese un correo electrónico: ";
    cin >> email; 

    cout << "Ingrese el link de su foto de perfil: ";
    cin >> pfp; 

    try{
        iConU->registro(nick, nombre, pass, email, pfp, txn);
        cout << "¡Usuario registrado!" << endl; 
        cout << "¿Desea iniciar sesión con este usuario?" << endl; 
        cout << "   1: Sí" << endl;
        cout << "   2: No" << endl; 
        cin >> opt; 
        if(opt == 1){
            pqxx::work txn1(c);
            iConU->iniciarSesion(nick, pass, txn1);
            sesionI = true;
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}


void agregarJuegoAlSistema(){
    string nombre, imgLink, desc; 
    int plataforma, opt = 0;
    list<string> archivosData;
    list<string> directoriosData; 
    list<string> archivosConfig;

    pqxx::work txn(c);

    string info;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el nombre del juego a agregar: ";
    getline(cin, nombre);

    cout << "   1- Windows" << endl;
    cout << "   2- Linux" << endl;
    cout << "   3- Android" << endl;
    cout << "   4- PS1" << endl;
    cout << "   5- PS2" << endl;
    cout << "   6- Gamecube" << endl;
    cout << "   7- Xbox" << endl;
    cout << "Ingrese el número de la plataforma a la que pertenece el juego: ";
    cin >> plataforma; 
    
    plataforma--;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    EnumPlataforma platf = (EnumPlataforma)plataforma; 

    cout << "Ingrese el link de la imagen de carátula del juego: ";
    getline(cin, imgLink);

    cout << "Ingrese una descripción del juego: ";
    getline(cin, desc);

    do{
        cout << "Ingrese la ruta de la carpeta donde el juego guarda sus archivos: ";
        getline(cin, info);

        for (char& c : info) {
            if (c == '\\') {
                c = '/';
            }
        }

        directoriosData.push_back(info);

        cout << "   1- Ingresar otra dirección" << endl; 
        cout << "   2- Continuar" << endl; 
        cout << "Ingrese una opción:"; 
        cin >> opt; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(opt!=2);

    opt = 0;
    do{
        cout << "Ingrese el nombre del archivo de guardado del juego (incluyendo extensión): ";
        getline(cin, info);

        archivosData.push_back(info);

        cout << "   1- Ingresar otro archivo" << endl; 
        cout << "   2- Continuar" << endl; 
        cout << "Ingrese una opción:"; 
        cin >> opt; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(opt!=2);

    opt = 0; 
    do{
        cout << "Ingrese el nombre del archivo de configuración del juego (incluyendo extensión): ";
        getline(cin, info);


        archivosConfig.push_back(info);

        cout << "   1- Ingresar otro archivo" << endl; 
        cout << "   2- Continuar" << endl; 
        cout << "Ingrese una opción:"; 
        cin >> opt; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(opt!=2);

    iConJ->recopilarDatos(nombre, platf, imgLink, desc, archivosData, archivosConfig, directoriosData);
    iConJ->agregarJuego(txn);
}

bool archivoExiste(const char* directorio, string archivo){ 
    struct stat sb; 

    string dir;

    bool existe = false;

    if(stat(directorio, &sb) == 0){
        cout << "La carpeta existe" << endl;

        dir = directorio;
        archivo = dir + "/" + archivo;

        ifstream archivoA(archivo);

        if(archivoA.good()){
            cout << "El archivo existe";
            archivoA.close();
            existe = true;
        }
        else{
            cout << "El archivo no existe";
        }
    }
    else{
        cout << "La carpeta no existe";
    }

    return existe; 
}

void respaldarDatos(){
    pqxx::work txn(c);
    int idJuego;
    int cont; 
    int opt = 0; 
    list<string> archivosEncontrados; 
    string archivoElegido = "";
    string directorioBackup = "";
    string nombreData = "";
    string comentariosJugador = "";
    string trash; 
    EnumTipoDato tipoDato;
    bool success = false; 
    bool conReemplazo;
    
    listarJuegos();

    cout << "Inserte el ID del juego al que pertenece el archivo: ";
    cin >> idJuego;

    while(success == false){
        cout << "Quiere respaldar: " << endl;
        cout << "   1- Partida" << endl;
        cout << "   2- Configuración" << endl;
        cin >> opt;
        if(opt == 1){
            tipoDato = static_cast<EnumTipoDato>(0);
            success = true; 
        }
        else if(opt == 2){
            tipoDato = static_cast<EnumTipoDato>(1);
            success = true; 
        }
        else{
            cout << "Opción no reconocida. Reintente" << endl; 
        }
    }
    success = false;



    archivosEncontrados = iConD->encontrarArchivosPorJuego(idJuego, tipoDato);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    opt = 0; 
    while(opt!=-1){
        cont = 0; 
        success = false; 
        for(const string archivo : archivosEncontrados){
            cout << cont << "   =>" << archivo << endl; 
            cont++; 
        }
        cout << "Inserte el número de un archivo que quiere agregar al backup, o digite -1 para continuar: ";
        cin >> opt; 

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while(success==false){
            if (opt >= 0 && opt <= archivosEncontrados.size()) {
                auto it = archivosEncontrados.begin();
                advance(it, opt);  // Avanza al elemento seleccionado

                archivoElegido = *it;
                cout << "Archivo elegido: " << archivoElegido << endl;
                success = true; 
            } 
            else if(opt == -1){
                success = true;
            }
            else {
                cout << "Opción no válida." << endl;
            }

        }

        if(opt != -1){
            iConD->seleccionarDirectorioLocal(archivoElegido);
        }
    }
    success = false;
    
    while(success == false){
        cout << "Ingrese un nombre para el backup: ";

        getline(cin, nombreData);

        if(!iConD->disponibilidadNombreData(nombreData)){
            cout << "Ya existe un backup con el nombre dado. Reintente" << endl;
        }
        else{
            success = true; 
        }
    }

    cout << "Ingrese un comentario para el backup (opcional): ";

    getline(cin, comentariosJugador);



    cout << "Ingrese la dirección de la carpeta que quiere usar como backup: ";

    getline(cin, directorioBackup);
    bool exito = false; 

    while(!exito){
        opt = 0; 
        cout << "   1-Backup con historial" << endl; 
        cout << "   2-Backup sin historial" << endl;
        cout << "Ingrese una opción: ";
        cin >> opt; 

        if(opt == 1){
            conReemplazo = false; 
            exito = true; 
        }
        else if(opt == 2){
            conReemplazo = true; 
            exito = true;
        }
        else{
            cout << "Opción no reconocida. Reintente" << endl; 
        }
    }

    iConD->crearCarpetaBackup(directorioBackup, idJuego, nombreData, conReemplazo);

    iConD->backupearDatos(conReemplazo);

    EnumFuente plataformaFuente = static_cast<EnumFuente>(0);

    DtFechaHora* fechaHora = new DtFechaHora();

    fechaHora->setFechaHoraActual();

    iConD->crearVirtualData(idJuego, nombreData, comentariosJugador, fechaHora, plataformaFuente, tipoDato, conReemplazo, txn);
}



void verRespaldos(int opcion){
    EnumTipoDato tipoDato = static_cast<EnumTipoDato>(opcion); 

    list<DtData*> partidas = iConD->verVirtualData(tipoDato);

    if(!partidas.empty()){
        list<DtData*>::iterator it; 
        for(it=partidas.begin();it!=partidas.end(); it++){
            cout << "================================================" << endl;
            cout << (*(*it));
            cout << "================================================" << endl;
        }
    }
    else{
        cout << "El usuario no tiene datos de este tipo registrados" << endl; 
    }
}


/*


=================================================================================

La siguiente función requiere solución de bugs

=================================================================================



*/



void actualizarRespaldos(){
    list<DtData*> userData = iConD->verVirtualDataCompleta();
    list<DtData*>::iterator dt;

    int idData; 
    string nombreData;

    list<string> directoriosLocales;
    list<string>::iterator st;

    bool desactualizado = false; 

    for(dt = userData.begin(); dt!=userData.end(); dt++){
        desactualizado = iConD->archivosDesactualizados((*dt)->getIdData());

        string pathCloud = (*dt)->getDirectorioCloud();
        string nombreJuego = iConJ->nombreDeJuego((*dt)->getJuego()) + "/";




        size_t pos = pathCloud.find(nombreJuego);
        if(pos != string::npos){
            pathCloud.erase(pos - 1);
        }


        if(desactualizado){
            //Se obtienen todos los directorios de archivos en la pc y el respaldo
            directoriosLocales = (*dt)->getDirectorioLocal();

            //Se le dan al controlador todos los directorios de los archivos en la pc 
            for(st=directoriosLocales.begin();st!=directoriosLocales.end();st++){
                iConD->seleccionarDirectorioLocal((*st));
            }
                
            //Se crea la carpeta del backup/elimina los archivos anteriores si no es con historial
            iConD->crearCarpetaBackup(pathCloud, (*dt)->getJuego(), (*dt)->getNombreData(), !(*dt)->getConHistorial());

            iConD->backupearDatos(!(*dt)->getConHistorial());

            idData = (*dt)->getIdData();
            nombreData = (*dt)->getNombreData();

            iConD->actualizarFechaVirutalData(idData);

            cout << "Se actualizaron los archivos del backup " << nombreData << endl; 
        }
        directoriosLocales.clear();
    }
}

void listarJuegos(){
    list<DtJuego*> juegos = iConJ->listarJuegos();

    list<DtJuego*>::iterator it;
    for(it = juegos.begin(); it!= juegos.end(); it++){
        cout << "================================================" << endl;
        cout << (*(*it));
        cout << "================================================" << endl;
    }
}

void verJuegosPorUsuario(){
    DtUsuario* user = iConU->getDtUsuarioActual();
    list<DtJuego*> juegos; 
    if(user->getAdmin()){
        string nick;
        cout << "Inserte el nick del usuario del que quiere ver los datos: ";
        getline(cin, nick);

        juegos = iConJ->verJuegosBackupeadosPorJugador(nick, move(c));
    }
    else{
        juegos = iConJ->verJuegosBackupeadosPorJugador(user->getNick(), move(c));
    }

    if(!juegos.empty()){
        list<DtJuego*>::iterator it;
        for(it = juegos.begin(); it!= juegos.end(); it++){
            cout << "================================================" << endl;
            cout << (*(*it));
            cout << "================================================" << endl;
        }
    }
    else{
        cout << "El usuario no tiene ningún backup creado." << endl; 
    }
}

void modificarDatosJuego(){
    Sesion* sesion = Sesion::getSesion();
    Usuario* user = sesion->getUsuario();
    pqxx::work txn(c);

    int idJuego = 0; 
    string nombre = "";
    string imgLink = "";
    string desc = "";

    int opt = 0; 


    if(user->getAdmin()){
        listarJuegos();

        cout << "Ingrese el ID del juego que quiere modificar: ";
        cin >> idJuego;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "¿Qué dato desea modificar?" << endl; 
        cout << "   1- Nombre" << endl;
        cout << "   2- Imagen" << endl;
        cout << "   3- Descripción" << endl;
        cin >> opt; 

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(opt<=3 && opt>=1){
            while(opt!=4){

                cout << "Ingrese el nuevo dato: ";

                switch(opt){
                    case 1:
                        getline(cin, nombre);
                    break;
                    case 2: 
                        getline(cin, imgLink);
                    break;
                    case 3:
                        getline(cin, desc);
                    break;
                    case 4:
                    break;
                    default:
                        cout << "Opción incorrecta. Reintente" << endl; 
                    break;
                }

                nombre = ""; //Por ahora, debido a que es necesario ver qué pasa con los datos guardados si se modifica el nombre del juego (porque la carpeta en el backup depende de este parámetro)
                iConJ->modificarDatosJuego(idJuego, nombre, imgLink, desc, txn);

                cout << "¿Desea modificar otro dato?" << endl; 
                cout << "   1- Nombre" << endl;
                cout << "   2- Imagen" << endl;
                cout << "   3- Descripción" << endl;
                cout << "   4- Salir" << endl;
                cin >> opt; 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else{
            cout << "Opción incorrecta" << endl; 
        }


    }
}

void precargarDatos(){
    /*iConU->registro("ElDeLaBarba", "Enzo", "1234", "enzogagu@gmail.com", "google.com", std::move(c));


    iConU->registro("EnzoGularte1", "Enzo", "1234", "enzogagu@gmail.com", "google.com", txn);


    pqxx::work txn1(c);
    iConU->registro("ElBar", "Bas", "1234", "thatonewithabeard@gmail.com", "instagram.com", txn1);

    int plat = 0; 

    EnumPlataforma plataforma = static_cast<EnumPlataforma>(plat);

    list<string> directorios;
    list<string> archivos;
    string carpetaUsuario; 

    PWSTR path;
    if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path))) {
        wcout << L"User folder: " << path << endl;

        //wstring userFolder(path);

        int wstrLength = static_cast<int>(wcslen(path));

        int requiredSize = WideCharToMultiByte(CP_UTF8, 0, path, wstrLength, nullptr, 0, nullptr, nullptr);


        string userPath(requiredSize, 0);

        WideCharToMultiByte(CP_UTF8, 0, path, wstrLength, &userPath[0], requiredSize, nullptr, nullptr);

    
        replace(userPath.begin(), userPath.end(), '\\', '/');

        carpetaUsuario = userPath;
        //cout << userPath << "/Documents/GTA San Andreas User Files"; 
        CoTaskMemFree(static_cast<void*>(path));
    } else {
        cerr << "Error getting user folder." << endl;
    }

    directorios.push_back(carpetaUsuario + "/Documents");
    directorios.push_back(carpetaUsuario + "/Documents/GTA San Andreas User Files");

    archivos.push_back("GTASAsf1.b");
    archivos.push_back("GTASAsf2.b");
    archivos.push_back("GTASAsf3.b");
    archivos.push_back("GTASAsf4.b");
    archivos.push_back("GTASAsf5.b");
    archivos.push_back("GTASAsf6.b");
    archivos.push_back("GTASAsf7.b");
    archivos.push_back("GTASAsf8.b");

    pqxx::work txn(c);
    iConJ->recopilarDatos("GTA San Andreas", plataforma, "google.com", "GTA game", archivos, directorios);
    iConJ->agregarJuego(txn);

    directorios.clear();
    archivos.clear();

    directorios.push_back(carpetaUsuario + "/Documents/My Games/HotlineMiami");

    archivos.push_back("SaveData.sav");
    archivos.push_back("hotline.cfg");

    pqxx::work txn1(c);
    iConJ->recopilarDatos("Hotline Miami", plataforma, "google.com", "GOTY", archivos, directorios);
    iConJ->agregarJuego(txn1);
    */
}
