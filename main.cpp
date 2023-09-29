#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
#include <winbase.h>
#include <map>
//#include <mysql_driver.h>
//#include <mysql_connection.h>
//#include <boost/filesystem.hpp>
#include "DtFechaHora.h"
#include "IControladorUsuario.h"
#include "Fabrica.h"

using namespace std; 



//char* diagonal = "/";
Fabrica* factory;
IControladorUsuario* iConU;

void IniciarSesion();

void Registro();

bool archivoExiste(const char* directorio, string archivo);

void copiarArchivoReemplazando(const char* ubIn, const char* ubBackup, string nombreArchivo, const char* nombreJuego, const char* nombreSaved);

int main(){
    factory = Fabrica::getInstancia();
    iConU = factory->getControladorUsuario();

    int opt;
    bool sesionI = false; 
    bool salir = false; 

    while(sesionI == false && salir == false){
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
            break; 
            default: 
                cout << "La opción no es válida. Reintente" << endl; 
            break; 
        }    
    }
    

    /*
    const char* directorio;
    string dir;
    string archivo;

    cout << "Ingrese el directorio donde almacena los archivos: ";
    getline(cin, dir);

    cout << "Ingrese el nombre del archivo que desea: ";
    cin >> archivo;

    directorio = dir.c_str();

    copiarArchivoReemplazando(directorio, "C:/Users/ElDeLaBarba/Desktop/Proyecto Gonza/Backup", "GTABACK", "GTA VC", "GTA VC SAVE");

    if(archivoExiste(directorio, archivo)){
        copiarArchivoReemplazando(directorio, "C:/Users/ElDeLaBarba/Desktop/Proyecto Gonza/Backup", "GTABACK", "GTA VC", "GTA VC SAVE");
    }
    */
}

void IniciarSesion(){
    string nick, pass; 

    cout << "Ingrese el nickname: ";
    cin >> nick;     

    cout << "Ingrese la contraseña: ";
    cin >> pass;     

    try{
        iConU->iniciarSesion(nick, pass);
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
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
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

void copiarArchivoReemplazando(const char* ubIn, const char* ubBackup, string nombreArchivo, const char* nombreJuego, const char* nombreSaved){
    struct stat sb; 

    string dir; 

    char* ubJuego;                                                            //Carpeta del juego dentro del backup
    char* ubSaved;                                                            //Carpeta de las partidas guardadas del juego dentro del backup

    if(stat(ubBackup, &sb) == 0){
        cout << "La carpeta de respaldo existe" << endl;


        strcpy(ubJuego, ubBackup);
        //strcat(ubJuego, diagonal);
        strcat(ubJuego, nombreJuego);


        ubSaved = ubJuego;
        //strcat(ubSaved, diagonal);
        strcat(ubSaved, nombreSaved);


        if(stat(ubJuego, &sb) == 0){
            cout << "La carpeta del juego ya existe" << endl;
        }
        else{

            mkdir(ubJuego);

            mkdir(ubSaved);

            cout << "Se crearon las carpetas necesarias para el backup" << endl;
        }

        

    } 
    else{
        cout << "La carpeta de respaldo proporcionada no existe" << endl;
    }
}


/*
//Fecha y hora actual
DtFechaHora* fechaHoraActual(){
    time_t now = time(0);

    tm *ltm = localtime(&now);

    DtFechaHora* dtFechaHora = new DtFechaHora(ltm->tm_mday,(1+ltm->tm_mon),(1900+ltm->tm_year),(ltm->tm_hour),(ltm->tm_min));
    return dtFechaHora;
}

*/

