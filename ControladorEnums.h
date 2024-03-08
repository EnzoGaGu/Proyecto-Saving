#ifndef CONTROLADORENUMS
#define CONTROLADORENUMS
#include "IControladorEnums.h"
#include "enumPlataforma.h"
#include "enumTipoDato.h"
#include "enumFuente.h"

using namespace std; 

class ControladorEnums : public IControladorEnums{
    private:
    public: 
        ControladorEnums();
        string plataformaToString(EnumPlataforma plataforma);
        EnumPlataforma stringToPlataforma(string plataforma);
        string fuenteToString(EnumFuente fuente);
        EnumFuente stringToFuente(string fuente);
        string tipoDatoToString(EnumTipoDato tipoDato);
        EnumTipoDato stringToTipoDato(string tipoDato);
        
};


#endif