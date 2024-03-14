#ifndef DTFECHAHORA
#define DTFECHAHORA
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <winbase.h>
#include <list>
#include <algorithm>
#include <chrono>
#include <ctime> 
#include <filesystem>


namespace fs = std::filesystem;
using namespace std;


class DtFechaHora{
private:
	int dia;
	int mes;
	int anio;
	int hora;
	int minuto;
	int segundo; 
public:
	DtFechaHora();//constructor vacio
	DtFechaHora(int,int,int,int,int,int);//constructor completo

	int getDia();
	int getMes();
	int getAnio();
	int getHora();
	int getMinuto();
	int getSegundo();

	void setFechaHoraActual();
    void fechaModificacionArchivo(string ruta);
    void PostgreToDt(string fecha);
	string dtToPostgre();

	~DtFechaHora();//destructor

	friend ostream& operator <<(ostream&,const DtFechaHora&);//sobrecarga de << , para mostrar la clase DtFechaHora
	friend bool operator <(const DtFechaHora&,const DtFechaHora&);//sobrecarga de < , para comparar DtFechaHoras
	friend bool operator <=(const DtFechaHora&,const DtFechaHora&);//sobrecarga de <= , para comparar fechas


};
#endif
