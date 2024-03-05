#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>
#include <pqxx/pqxx>
#include "DtUsuario.h"

using namespace std;

class IControladorUsuario{
    public:
        virtual void iniciarSesion(string nick, string pass, pqxx::work& txn) = 0; 
        virtual void registro(string nick, string nombre, string pass, string email, string pfp, pqxx::work& txn) = 0;
        virtual void modificarUsuario(string nick, string nombre, string pass, string email, string pfp) = 0;
        virtual DtUsuario* getDtUsuarioActual() = 0;
};

#endif