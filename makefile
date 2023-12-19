principal: DtFechaHora.o DtJuego.o DtData.o Usuario.o Sesion.o Juego.o Data.o Configuracion.o ManejadorUsuario.o ManejadorJuego.o ControladorUsuario.o ControladorJuego.o ControladorData.o Fabrica.o main.o
	g++ DtFechaHora.o DtJuego.o DtData.o Usuario.o Sesion.o Juego.o Data.o Configuracion.o ManejadorUsuario.o ManejadorJuego.o ControladorUsuario.o ControladorJuego.o ControladorData.o Fabrica.o main.o -g -luuid -o proyecto -lshell32 -lole32

DtFechaHora.o: DtFechaHora.cpp
	g++ -g -c DtFechaHora.cpp

DtJuego.o: DtJuego.cpp
	g++ -g -c DtJuego.cpp

DtData.o: DtData.cpp
	g++ -g -c DtData.cpp

Usuario.o: Usuario.cpp
	g++ -g -c Usuario.cpp

Sesion.o: Sesion.cpp
	g++ -g -c Sesion.cpp

Juego.o: Juego.cpp
	g++ -g -c Juego.cpp

Data.o: Data.cpp
	g++ -g -c Data.cpp
	
#MemCard.o: MemCard.cpp
#	g++ -g -c MemCard.cpp

Configuracion.o: Configuracion.cpp
	g++ -g -c Configuracion.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp
	g++ -g -c ManejadorUsuario.cpp

ManejadorJuego.o: ManejadorJuego.cpp
	g++ -g -c ManejadorJuego.cpp

ControladorUsuario.o: ControladorUsuario.cpp
	g++ -g -c ControladorUsuario.cpp

ControladorJuego.o: ControladorJuego.cpp
	g++ -g -c ControladorJuego.cpp

ControladorData.o: ControladorData.cpp
	g++ -g -c ControladorData.cpp

Fabrica.o: Fabrica.cpp
	g++ -g -c Fabrica.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clear: 
	del -f *.o proyecto