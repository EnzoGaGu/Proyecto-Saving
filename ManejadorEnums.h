#ifndef MANEJADORENUMS
#define MANEJADORENUMS
#include <string>
#include <iostream>
#include "enumPlataforma.h"
#include "enumTipoDato.h"
#include "enumFuente.h"

using namespace std; 

class ManejadorEnums{
    private:
        ManejadorEnums();
        static ManejadorEnums* instancia; 
    public: 
        static ManejadorEnums* getInstancia();
        string plataformaToString(EnumPlataforma plataforma);
        EnumPlataforma stringToPlataforma(string plataforma);
        string fuenteToString(EnumFuente fuente);
        EnumFuente stringToFuente(string fuente);
        string tipoDatoToString(EnumTipoDato tipoDato);
        EnumTipoDato stringToTipoDato(string tipoDato);
        ~ManejadorEnums();
};


#endif