#include "DtFechaHora.h"

using namespace std;//para usar string

DtFechaHora::DtFechaHora(){}//constructor vacio

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int minuto, int segundo){
	if (dia<1 or dia>31 or mes<1 or mes>12 or anio<1900)
	{
		throw invalid_argument("Fecha no válida");	
	}else{	
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
		this->hora = hora;
		this->minuto = minuto;
		this->segundo = segundo; 
	}


}//constructor completo

int DtFechaHora::getDia(){
	return this->dia;
}

int DtFechaHora::getMes(){
	return this->mes;
}

int DtFechaHora::getAnio(){
	return this->anio;
}

int DtFechaHora::getHora(){
	return this->hora;
}

int DtFechaHora::getMinuto(){
	return this->minuto;
}

int DtFechaHora::getSegundo(){
	return this->segundo; 
}

void DtFechaHora::setFechaHoraActual(){
	time_t now = time(0);
    tm *ltm = localtime(&now);
	this->dia = ltm->tm_mday;
	this->mes = 1+ltm->tm_mon;
	this->anio = 1900+ltm->tm_year;
	this->hora = ltm->tm_hour;
	this->minuto = ltm->tm_min;
	this->segundo = ltm->tm_sec;
}


void DtFechaHora::fechaModificacionArchivo(string ruta){
    DtFechaHora* fechaModificacion = new DtFechaHora(); 
    
    try {
		namespace fs = std::filesystem;

		fs::file_time_type ftime = fs::last_write_time(ruta);

		auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now());
        auto cftime = std::chrono::system_clock::to_time_t(sctp);

		std::tm* tm_time = std::localtime(&cftime);

		// Obtener los componentes de la fecha
		this->anio = tm_time->tm_year + 1900; // El año actual es el año desde 1900
		this->mes = tm_time->tm_mon + 1;     // tm_mon comienza en 0 para enero
		this->dia = tm_time->tm_mday;          // Día del mes
		this->hora = tm_time->tm_hour;         // Hora del día
		this->minuto = tm_time->tm_min;        // Minuto de la hora
		this->segundo = tm_time->tm_sec;        // Segundo del minuto
    } catch (const std::filesystem::filesystem_error& ex) {
        std::cerr << "Error al obtener la fecha de modificación: " << ex.what() << std::endl;
    }
}

void DtFechaHora::PostgreToDt(string fecha){
    string fechaMod;

    fechaMod = fecha.substr(1, fecha.size()-2);

    stringstream ss(fechaMod);


    int dia, mes, anio, hora, minuto, segundo; 
    char comma; 

    ss >> dia >> comma >> mes >> comma >> anio >> comma >> hora >> comma >> minuto >> comma >> segundo; 

	

	this->dia = dia;
	this->mes = mes; 
	this->anio = anio; 
	this->hora = hora; 
	this->minuto = minuto; 
	this->segundo = segundo;
}

DtFechaHora::~DtFechaHora(){}//destructor

ostream& operator <<(ostream& salida,const DtFechaHora& a) {
	cout << "Fecha: " << a.dia << "/" << a.mes << "/" << a.anio;
	cout << " hora " << a.hora <<":"<< a.minuto << ":" << a.segundo << endl;
	return salida;
}//sobrecarga de << , para mostrar la clase DtFechaHora

/*

bool operator <(const DtFechaHora& dtf1,const DtFechaHora& dtf2){
	bool retorno = false;

	if (dtf1.anio < dtf2.anio){
		retorno=true;
	}else if(dtf1.anio == dtf2.anio){
		if (dtf1.mes < dtf2.mes){
			retorno=true;
		}else if(dtf1.mes == dtf2.mes){
			if (dtf1.dia < dtf2.dia){
				retorno=true;
			}else if(dtf1.dia == dtf2.dia){ 
				if(dtf1.hora < dtf2.hora){
					retorno=true; 
				}
				else if(dtf1.hora == dtf2.hora){
					if(dtf1.minuto < dtf2.minuto){
						retorno=true;
					}
					else if(dtf1.minuto == dtf2.minuto){
						if(dtf1.segundo < dtf2.segundo){
							retorno=true; 
						}
					}
				}
			}
		}
	}
	return retorno;
}//sobrecarga de < , para comparar fechas
*/

bool operator <(const DtFechaHora& lhs, const DtFechaHora& rhs) {
    if (lhs.anio < rhs.anio)
        return true;
    if (lhs.anio > rhs.anio)
        return false;
    if (lhs.mes < rhs.mes)
        return true;
    if (lhs.mes > rhs.mes)
        return false;
    if (lhs.dia < rhs.dia)
        return true;
    if (lhs.dia > rhs.dia)
        return false;
    if (lhs.hora < rhs.hora)
        return true;
    if (lhs.hora > rhs.hora)
        return false;
    if (lhs.minuto < rhs.minuto)
        return true;
    if (lhs.minuto > rhs.minuto)
        return false;
    return lhs.segundo < rhs.segundo;
}


bool operator<=(const DtFechaHora& dtf1, const DtFechaHora& dtf2) {
    if (dtf1.anio < dtf2.anio) {
        return true;
    } else if (dtf1.anio > dtf2.anio) {
        return false;
    } else {
        // Los años son iguales, continuamos con los meses
        if (dtf1.mes < dtf2.mes) {
            return true;
        } else if (dtf1.mes > dtf2.mes) {
            return false;
        } else {
            // Los meses son iguales, continuamos con los días
            if (dtf1.dia < dtf2.dia) {
                return true;
            } else if (dtf1.dia > dtf2.dia) {
                return false;
            } else {
                // Los días son iguales, continuamos con las horas
                if (dtf1.hora < dtf2.hora) {
                    return true;
                } else if (dtf1.hora > dtf2.hora) {
                    return false;
                } else {
                    // Las horas son iguales, continuamos con los minutos
                    if (dtf1.minuto < dtf2.minuto) {
                        return true;
                    } else if (dtf1.minuto > dtf2.minuto) {
                        return false;
                    } else {
                        // Los minutos son iguales, continuamos con los segundos
                        return dtf1.segundo <= dtf2.segundo;
                    }
                }
            }
        }
    }
}
