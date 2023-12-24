#include "ControladorTiempo.h"

ControladorTiempo::ControladorTiempo(){}


//Devuelve un DtFechaHora con los datos del momento en el que se llamó la función
DtFechaHora* ControladorTiempo::fechaHoraActual(){

    DtFechaHora* dtFechaHora = new DtFechaHora();
    dtFechaHora->setFechaHoraActual();
    return dtFechaHora;
}

DtFechaHora* ControladorTiempo::fechaModificacionArchivo(string ruta){
    DtFechaHora* fechaModificacion; 
    
    try {
        // Obtén la fecha de modificación del archivo
        const auto fileTime = fs::last_write_time(ruta);

        // Convierte el tiempo del archivo a un formato de tiempo legible
        const auto durationSinceEpoch = fileTime.time_since_epoch();
        const auto systemTimePoint = chrono::time_point<chrono::system_clock>(durationSinceEpoch);
        time_t time = chrono::system_clock::to_time_t(systemTimePoint);

        tm timeInfo = *localtime(&time);

        fechaModificacion = new DtFechaHora();
                    
        // Imprime la fecha de modificación del archivo
        std::cout << "Fecha de modificación: " << std::ctime(&time) << std::endl;
        } catch (const std::filesystem::filesystem_error& ex) {
            std::cerr << "Error al obtener la fecha de modificación: " << ex.what() << std::endl;
    }

    return fechaModificacion;
}

ControladorTiempo::~ControladorTiempo(){}