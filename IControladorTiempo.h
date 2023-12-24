#ifndef ICONTROLADORTIEMPO 
#define ICONTROLADORTIEMPO
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <winbase.h>
#include <list>
#include <algorithm>
#include <chrono>
#include <ctime> 
#include "DtFechaHora.h"
#include <filesystem>


namespace fs = std::filesystem;
using namespace std;

class IControladorTiempo{
    private:
    public: 
        virtual DtFechaHora* fechaHoraActual() = 0;
        virtual DtFechaHora* fechaModificacionArchivo(string ruta) = 0;
};

#endif