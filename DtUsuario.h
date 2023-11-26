#ifndef DTUSUARIO
#define DTUSUARIO
#include <string>
#include <list>
#include "DtFechaHora.h"
#include "Data.h"
#include "DtData.h"

class DtUsuario{
    private:
        string nick;                                        //Nick de usuario (clave)
        string nombre;                                      //Nombre    
        string pass;                                        //Contraseña
        string email;                                       //Correo electrónico
        string pfp;                                         //Foto de perfil (link)
        DtFechaHora* fechaInsc;                             //Fecha de inscripción (autogenerada)
        bool admin;                                         //Si es admin o no (false por defecto)
        list<Data*> dataAgregada;
    public:
        DtUsuario();
        DtUsuario(string nick, string nombre, string pass, string email, string pfp, DtFechaHora* fechaInsc, bool admin);
        string getNick();
        string getNombre();
        string getPass();
        string getEmail();
        string getPfp();
        DtFechaHora* getFechaInsc();
        bool getAdmin();
        Data* findData(string idData);
        bool memberData(string idData);
        DtData* getDtData(string idData);
        list<DtData*> listData();
        ~DtUsuario();

};


#endif