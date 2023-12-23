#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>
#include "DtUsuario.h"

using namespace std;

class IControladorUsuario{
    public:
        virtual void iniciarSesion(string nick, string pass) = 0; 
        virtual void registro(string nick, string nombre, string pass, string email, string pfp) = 0;
        virtual void modificarUsuario(string nick, string nombre, string pass, string email, string pfp) = 0;
        virtual DtUsuario* getDtUsuarioActual() = 0;
};

#endif