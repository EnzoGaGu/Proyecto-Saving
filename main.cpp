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

//Precarga usuarios y juegos, para probar el sistema sin necesidad de persistencia.
void precargarDatos();


//Iniciar sesión en el sistema a través de un usuario ya creado.
void IniciarSesion();


//Registrar un nuevo usuario en el sistema. Si no existe ninguno (no se precargaron datos), el primero siempre será admin.
void Registro();


//Agregar un juego al sistema (solo admins).
void agregarJuegoAlSistema();


//Respaldar una partida. Si ya existe un archivo con el mismo nombre en la carpeta backup, el sistema lo elimina y reemplaza por el nuevo.
void respaldarPartidaConReemplazo();


//Respaldar una partida. Crea una carpeta nueva por backup
void respaldarPartidaConHistorial();


//Comprobar si existe un archivo con el nombre "archivo" en la ruta "directorio".
bool archivoExiste(const char* directorio, string archivo);


//Listar todos los juegos registrados en el sistema. 
void listarJuegos();


//Devuelve un DtFechaHora con los datos del momento en el que se llamó la función
DtFechaHora* fechaHoraActual();

//void copiarArchivoReemplazando(const char* ubIn, const char* ubBackup, string nombreArchivo, const char* nombreJuego, const char* nombreSaved);

int main(){
    factory = Fabrica::getInstancia();
    iConU = factory->getControladorUsuario();
    iConJ = factory->getControladorJuego();
    iConD = factory->getControladorData();
    sesion = Sesion::getSesion();

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
                //cout << "   1: Agregar juego" << endl;
                cout << "   1: Respaldar partidas guardadas reemplazando" << endl;
                cout << "   2: Respaldar partidas guardadas con historial" << endl;
                cout << "   3: Respaldar configuraciones" << endl;
                cout << "   4: Comprobar si respalo está up-to-date" << endl;
                cout << "   5: Ver juegos agregados" << endl;
                cout << "   6: Ver respaldos de partidas" << endl;
                cout << "   7: Ver respaldos de configuraciones" << endl;
                cout << "   8: Ver respaldos" << endl;
                cout << "   9: Subir a la nube" << endl;
                cout << "   10: Descargar de la nube" << endl;
                cout << "   11: Actualizar rutas juego" << endl;
                cout << "   12: Cambiar usuario" << endl;
                cout << "   0: Salir"   << endl;
                cout << "Ingrese una opción: " << endl;
                cin >> opt; 

                switch(opt){
                    case 1: 
                        respaldarPartidaConReemplazo();
                    break;
                    case 2: 
                        respaldarPartidaConHistorial();
                    break;
                    case 3: 
                    break;
                    case 4: 
                    break;
                    case 5: 
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
                    case 11: 
                    break;
                    case 12: 
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
                cout << "   3: Modificar datos juego" << endl;
                cout << "   4: Ver usuarios" << endl;
                cout << "   5: Cambiar usuario" << endl;
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
                    break;
                    case 4: 
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

    cout << "Ingrese el nickname: ";
    cin >> nick;     

    cout << "Ingrese la contraseña: ";
    cin >> pass;     

    try{
        iConU->iniciarSesion(nick, pass);
        sesionI = true;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

void Registro(){
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
        iConU->registro(nick, nombre, pass, email, pfp);
        cout << "¡Usuario registrado!" << endl; 
        cout << "¿Desea iniciar sesión con este usuario?" << endl; 
        cout << "   1: Sí" << endl;
        cout << "   2: No" << endl; 
        cin >> opt; 
        if(opt == 1){
            iConU->iniciarSesion(nick, pass);
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

    string info;

    cout << "Ingrese el nombre del juego a agregar: ";
    cin >> nombre;

    cout << "   1- Windows" << endl;
    cout << "   2- Linux" << endl;
    cout << "   3- Android" << endl;
    cout << "   4- PS1" << endl;
    cout << "   5- PS2" << endl;
    cout << "   6- Gamecube" << endl;
    cout << "   7- Xbox" << endl;
    cout << "Ingrese el número de la plataforma a la que pertenece el juego: ";
    cin >> plataforma; 
    
    EnumPlataforma platf = (EnumPlataforma)plataforma; 

    cout << "Ingrese el link de la imagen de carátula del juego: ";
    cin >> imgLink;

    cout << "Ingrese una descripción del juego: ";
    cin >> desc; 

    do{
        cout << "Ingrese la ruta de la carpeta donde el juego guarda sus archivos: ";
        cin >> info; 

        directoriosData.push_back(info);

        cout << "   1- Ingresar otra dirección" << endl; 
        cout << "   2- Continuar" << endl; 
        cout << "Ingrese una opción:"; 
        cin >> opt; 
    }while(opt!=2);

    opt = 0;
    do{
        cout << "Ingrese el nombre del archivo de guardado del juego (incluyendo extensión): ";
        cin >> info; 

        archivosData.push_back(info);

        cout << "   1- Ingresar otro archivo" << endl; 
        cout << "   2- Continuar" << endl; 
        cout << "Ingrese una opción:"; 
        cin >> opt; 
    }while(opt!=2);

    iConJ->recopilarDatos(nombre, platf, imgLink, desc, archivosData, directoriosData);
    iConJ->agregarJuego();
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

void respaldarPartidaConReemplazo(){
    int idJuego;
    int cont = 0; 
    int opt; 
    list<string> archivosEncontrados; 
    string archivoElegido = "";
    string directorioBackup = "";
    string trash; 
    
    listarJuegos();

    cout << "Inserte el ID del juego al que pertenece la partida: ";
    cin >> idJuego;

    archivosEncontrados = iConD->encontrarArchivosPorJuego(idJuego);

    for(const string archivo : archivosEncontrados){
        cout << cont << "   =>" << archivo << endl; 
        cont++; 
    }
    cout << "Inserte el número del archivo que quiere agregar al backup: ";
    cin >> opt; 

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool success = false; 

    while(success==false){
        if (opt >= 0 && opt <= archivosEncontrados.size()) {
            auto it = archivosEncontrados.begin();
            advance(it, opt);  // Avanza al elemento seleccionado

            archivoElegido = *it;
            cout << "Archivo elegido: " << archivoElegido << endl;
            success = true; 
        } else {
            cout << "Opción no válida." << endl;
        }

    }
    

    cout << "Archivo elegido: " << archivoElegido << endl;
    iConD->seleccionarDirectorioLocal(archivoElegido);

    cout << "Ingrese la dirección de la carpeta que quiere usar como backup: ";

    getline(cin, directorioBackup);

    EnumTipoDato tipoDato = static_cast<EnumTipoDato>(0);

    iConD->crearCarpetaBackup(directorioBackup, idJuego, fechaHoraActual(), tipoDato, true);

    iConD->backupearDatos(true);
}


void respaldarPartidaConHistorial(){
    int idJuego;
    int cont = 0; 
    int opt; 
    list<string> archivosEncontrados; 
    string archivoElegido = "";
    string directorioBackup = "";
    string trash; 
    
    listarJuegos();

    cout << "Inserte el ID del juego al que pertenece la partida: ";
    cin >> idJuego;

    archivosEncontrados = iConD->encontrarArchivosPorJuego(idJuego);

    for(const string archivo : archivosEncontrados){
        cout << cont << "   =>" << archivo << endl; 
        cont++; 
    }
    cout << "Inserte el número del archivo que quiere agregar al backup: ";
    cin >> opt; 

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool success = false; 

    while(success==false){
        if (opt >= 0 && opt <= archivosEncontrados.size()) {
            auto it = archivosEncontrados.begin();
            advance(it, opt);  // Avanza al elemento seleccionado

            archivoElegido = *it;
            cout << "Archivo elegido: " << archivoElegido << endl;
            success = true; 
        } else {
            cout << "Opción no válida." << endl;
        }

    }
    

    cout << "Archivo elegido: " << archivoElegido << endl;
    iConD->seleccionarDirectorioLocal(archivoElegido);

    cout << "Ingrese la dirección de la carpeta que quiere usar como backup: ";

    getline(cin, directorioBackup);

    EnumTipoDato tipoDato = static_cast<EnumTipoDato>(0);

    iConD->crearCarpetaBackup(directorioBackup, idJuego, fechaHoraActual(), tipoDato, false);

    iConD->backupearDatos(true);
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


//Fecha y hora actual
DtFechaHora* fechaHoraActual(){
    time_t now = time(0);

    tm *ltm = localtime(&now);

    DtFechaHora* dtFechaHora = new DtFechaHora(ltm->tm_mday,(1+ltm->tm_mon),(1900+ltm->tm_year),(ltm->tm_hour),(ltm->tm_min));
    return dtFechaHora;
}


void precargarDatos(){
    iConU->registro("ElDeLaBarba", "Enzo", "1234", "enzogagu@gmail.com", "google.com");
    iConU->registro("EnzoGularte", "Enzo", "1234", "enzogagu@gmail.com", "google.com");
    iConU->registro("ElBar", "Bas", "1234", "thatonewithabeard@gmail.com", "instagram.com");

    int plat = 1; 

    EnumPlataforma plataforma = static_cast<EnumPlataforma>(plat);

    list<string> directorios;
    list<string> archivos;

    string direc1 = "/Documents";

    PWSTR path;
    if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path))) {
        std::wcout << L"User folder: " << path << std::endl;

        //wstring userFolder(path);

        int wstrLength = static_cast<int>(wcslen(path));

        int requiredSize = WideCharToMultiByte(CP_UTF8, 0, path, wstrLength, nullptr, 0, nullptr, nullptr);


        string userPath(requiredSize, 0);

        WideCharToMultiByte(CP_UTF8, 0, path, wstrLength, &userPath[0], requiredSize, nullptr, nullptr);

    
        replace(userPath.begin(), userPath.end(), '\\', '/');

        directorios.push_back(userPath + direc1);
        directorios.push_back(userPath + "/Documents/GTA San Andreas User Files");

        //cout << userPath << "/Documents/GTA San Andreas User Files"; 
        CoTaskMemFree(static_cast<void*>(path));
    } else {
        std::cerr << "Error getting user folder." << std::endl;
    }

    archivos.push_back("GTASAsf1.b");
    archivos.push_back("GTASAsf2.b");
    archivos.push_back("GTASAsf3.b");
    archivos.push_back("GTASAsf4.b");
    archivos.push_back("GTASAsf5.b");
    archivos.push_back("GTASAsf6.b");
    archivos.push_back("GTASAsf7.b");
    archivos.push_back("GTASAsf8.b");

    iConJ->recopilarDatos("GTA San Andreas", plataforma, "google.com", "GTA game", archivos, directorios);
    iConJ->agregarJuego();
}

