principal: DtFechaHora.o DtJuego.o DtPartidaGuardada.o Usuario.o Sesion.o Juego.o PartidaGuardada.o MemCard.o Configuracion.o enumPlataforma.o enumTipo.o ManejadorUsuario.o ManejadorJuego.o ControladorUsuario.o Fabrica.o main.o
	g++ DtFechaHora.o DtJuego.o DtPartidaGuardada.o Usuario.o Sesion.o Juego.o PartidaGuardada.o MemCard.o Configuracion.o enumPlataforma.o enumTipo.o ManejadorUsuario.o ManejadorJuego.o ControladorUsuario.o Fabrica.o main.o -g -o proyecto

DtFechaHora.o: DtFechaHora.cpp
	g++ -g -c DtFechaHora.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clear: 
	rm -f *.o proyecto