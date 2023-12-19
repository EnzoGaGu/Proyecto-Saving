#ifndef USUARIO
#define USUARIO
#include <string>
#include <list>
#include "DtFechaHora.h"
#include "Juego.h"
#include "Data.h"
#include "DtData.h"

using namespace std;

class Usuario{
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
        Usuario();
        Usuario(string nick, string nombre, string pass, string email, string pfp, DtFechaHora* fechaInsc, bool admin);
        void setNick(string nick);
        string getNick();
        void setNombre(string nombre);
        string getNombre();
        void setPass(string pass);
        string getPass();
        void setEmail(string email);
        string getEmail();
        void setPfp(string pfp);
        string getPfp();
        void setFechaInsc(DtFechaHora* fechaInsc);
        DtFechaHora* getFechaInsc();
        void setAdmin(bool admin);
        bool getAdmin();
        void addData(Data* data);
        Data* findData(int idData);
        bool memberData(int idData);
        DtData* getDtData(int idData);
        list<DtData*> listData();
        void removeData(int idData);
        ~Usuario();
};

#endif