#ifndef DTFECHAHORA
#define DTFECHAHORA
#include <iostream>
#include <ctime>

using namespace std;//para usar string

class DtFechaHora{
private:
	int dia;
	int mes;
	int anio;
	int hora;
	int minuto;
public:
	DtFechaHora();//constructor vacio
	DtFechaHora(int,int,int,int,int);//constructor completo

	int getDia();
	int getMes();
	int getAnio();
	int getHora();
	int getMinuto();

	void setFechaHoraActual();

	~DtFechaHora();//destructor

	friend ostream& operator <<(ostream&,const DtFechaHora&);//sobrecarga de << , para mostrar la clase DtFechaHora
	friend bool operator <(const DtFechaHora&,const DtFechaHora&);//sobrecarga de < , para comparar DtFechaHoras
	friend bool operator <=(const DtFechaHora&,const DtFechaHora&);//sobrecarga de <= , para comparar fechas


};
#endif
