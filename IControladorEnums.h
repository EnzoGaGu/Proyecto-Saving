#ifndef ICONTROLADORENUMS
#define ICONTROLADORENUMS
#include <string>
#include <iostream>
#include "enumPlataforma.h"
#include "enumTipoDato.h"
#include "enumFuente.h"

using namespace std; 

class IControladorEnums { 
    private:
    public: 
        virtual string plataformaToString(EnumPlataforma plataforma) = 0;
        virtual EnumPlataforma stringToPlataforma(string plataforma) = 0;
        virtual string fuenteToString(EnumFuente fuente) = 0;
        virtual EnumFuente stringToFuente(string fuente) = 0;
        virtual string tipoDatoToString(EnumTipoDato tipoDato) = 0;
        virtual EnumTipoDato stringToTipoDato(string tipoDato) = 0;
};

#endif