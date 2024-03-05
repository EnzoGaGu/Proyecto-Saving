#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include "IControladorUsuario.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"

using namespace std;

class ControladorUsuario: public IControladorUsuario{
    private:
        string nick;
    public:
        ControladorUsuario();
        void iniciarSesion(string nick, string pass, pqxx::work& txn);
        void registro(string nick, string nombre, string pass, string email, string pfp, pqxx::work& txn);
        void modificarUsuario(string nick, string nombre, string pass, string email, string pfp);
        DtUsuario* getDtUsuarioActual();
        ~ControladorUsuario();
};

#endif