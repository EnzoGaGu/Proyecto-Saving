#include "ControladorData.h"


ControladorData::ControladorData(){}

void ControladorData::encontrarArchivo(string directorio, string archivo){
    struct stat sb; 

    if(stat(directorio.c_str(), &sb) == 0){
        string DirArchivo = directorio + "/" + archivo; 

        ifstream archivoA(DirArchivo);

        if(archivoA.good()){
            archivoA.close();
            this->nombreArchivo = archivo; 
            this->directorioLocal = directorio;
        }
    }
}

void ControladorData::crearCarpetaBackup(string directorioBackup, string nombreJuego, DtFechaHora* fecha, EnumTipoDato tipoDato, bool conReemplazo){
    struct stat sb;
    string directorioJuego = directorioBackup + "/" + nombreJuego;
    string reem = directorioJuego + "/reemplazo";
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

            }
        }
        else{
            fs::create_directory(directorioBackup.c_str());
        }
    }
    
}

void ControladorData::backupearDatos(bool conReemplazo){

    if(conReemplazo){
        fs::remove_all(this->directorioBackup);
    }


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

ControladorData::~ControladorData(){}