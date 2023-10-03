principal: DtFechaHora.o DtJuego.o DtPartidaGuardada.o Usuario.o Sesion.o Juego.o PartidaGuardada.o MemCard.o Configuracion.o ManejadorUsuario.o ManejadorJuego.o ControladorUsuario.o Fabrica.o main.o
	g++ DtFechaHora.o DtJuego.o DtPartidaGuardada.o Usuario.o Sesion.o Juego.o PartidaGuardada.o MemCard.o Configuracion.o ManejadorUsuario.o ManejadorJuego.o ControladorUsuario.o Fabrica.o main.o -g -o proyecto

DtFechaHora.o: DtFechaHora.cpp
	g++ -g -c DtFechaHora.cpp

DtJuego.o: DtJuego.cpp
	g++ -g -c DtJuego.cpp

DtPartidaGuardada.o: DtPartidaGuardada.cpp
	g++ -g -c DtPartidaGuardada.cpp

Usuario.o: Usuario.cpp
	g++ -g -c Usuario.cpp

Sesion.o: Sesion.cpp
	g++ -g -c Sesion.cpp

Juego.o: Juego.cpp
	g++ -g -c Juego.cpp

PartidaGuardada.o: PartidaGuardada.cpp
	g++ -g -c PartidaGuardada.cpp
	
MemCard.o: MemCard.cpp
	g++ -g -c MemCard.cpp

Configuracion.o: Configuracion.cpp
	g++ -g -c Configuracion.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp
	g++ -g -c ManejadorUsuario.cpp

ManejadorJuego.o: ManejadorJuego.cpp
	g++ -g -c ManejadorJuego.cpp

ControladorUsuario.o: ControladorUsuario.cpp
	g++ -g -c ControladorUsuario.cpp

Fabrica.o: Fabrica.cpp
	g++ -g -c Fabrica.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clear: 
	del -f *.o proyecto