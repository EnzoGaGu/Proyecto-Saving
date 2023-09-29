#include "DtFechaHora.h"

using namespace std;//para usar string

DtFechaHora::DtFechaHora(){}//constructor vacio

DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int minuto){
	if (dia<1 or dia>31 or mes<1 or mes>12 or anio<1900)
	{
		throw invalid_argument("Fecha no válida");	
	}else{	
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
		this->hora = hora;
		this->minuto = minuto;
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

void DtFechaHora::setFechaHoraActual(){
	time_t now = time(0);
    tm *ltm = localtime(&now);
	this->dia = ltm->tm_mday;
	this->mes = 1+ltm->tm_mon;
	this->anio = 1900+ltm->tm_year;
	this->hora = ltm->tm_hour;
	this->minuto = ltm->tm_min;
}

DtFechaHora::~DtFechaHora(){}//destructor

ostream& operator <<(ostream& salida,const DtFechaHora& a) {
	cout << "Fecha: " << a.dia << "/" << a.mes << "/" << a.anio;
	cout << " hora " << a.hora <<":"<< a.minuto << endl;
	return salida;
}//sobrecarga de << , para mostrar la clase DtFechaHora


bool operator <(const DtFechaHora& dtf1,const DtFechaHora& dtf2){
	bool retorno;

	if (dtf1.anio < dtf2.anio){
		retorno=true;
	}else if(dtf1.anio == dtf2.anio){
		if (dtf1.mes < dtf2.mes){
			retorno=true;
		}else if(dtf1.mes == dtf2.mes){
			if (dtf1.dia < dtf2.dia){
				retorno=true;
			}else{ 
				retorno=false;
			}
		}
	}
	return retorno;
}//sobrecarga de < , para comparar fechas

bool operator <=(const DtFechaHora& dtf1,const DtFechaHora& dtf2){
	bool retorno;

	if (dtf1.anio <= dtf2.anio){
		if(dtf1.mes <= dtf2.mes){
			if(dtf1.dia <= dtf2.dia){
				return true;
			}else if(dtf1.dia > dtf2.dia){
				return false;
			}

		}else if(dtf1.mes > dtf2.mes){
			return false;		
		}
	}else if(dtf1.anio>dtf2.anio){
		return false;
	}


	return retorno;
}//sobrecarga de <= , para comparar fechas
