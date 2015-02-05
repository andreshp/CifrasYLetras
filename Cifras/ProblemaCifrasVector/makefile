# Fichero: make
# Permite compilar el programa mapa pedido en la práctica:

	#VARIABLES#
# Compilador y Flags:
CXX=g++
CC=$(CXX)
CPPFLAGS=-c -Wall -fpermissive
CXXFLAGS=-I$(INCLUDE) -g
LDFLAGS=
LOADLIBS=
ARFLAGS=rvs
# Directorios:
BIN=./bin
INCLUDE =./include
LIB=./lib
OBJ=./obj
SRC=./src
DOC=./doc
# Módulos, Códigos Fuentes y Ejecutable:
EXECUTABLE=problemaCifras
EXECUTABLE_OBJECTS=$(OBJ)/Solucion.o $(OBJ)/Algoritmo.o $(OBJ)/main.o
LIBRARY_OBJECTS=

	#REGLAS#
# Regla que compila todo el proyecto:
all: $(BIN)/$(EXECUTABLE)

# Regla que crea el ejecutable problemaCifras:
$(BIN)/$(EXECUTABLE): $(EXECUTABLE_OBJECTS)
	@echo Creando el ejecutable $@...
	$(CC) $(CXXFLAGS) -o $(BIN)/$(EXECUTABLE) $^ $(INCLUDE)/Solucion.h $(INCLUDE)/Algoritmo.h

# Regla que crea el objeto main.o:
$(OBJ)/main.o: $(SRC)/main.cpp $(INCLUDE)/Solucion.h $(INCLUDE)/Algoritmo.h
	@echo Creando el módulo objeto $@...
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/main.cpp

# Regla que crea el objeto Solucion.o:
$(OBJ)/Solucion.o: $(SRC)/Solucion.cpp $(INCLUDE)/Solucion.h
	@echo Creando el módulo objeto $@...
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/Solucion.cpp

# Regla que crea el objeto Algoritmo.o:
$(OBJ)/Algoritmo.o: $(SRC)/Algoritmo.cpp $(INCLUDE)/Algoritmo.h $(INCLUDE)/Solucion.h
	@echo Creando el módulo objeto $@...
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/Algoritmo.cpp

# Regla que permite borrar todos los archivos .o:
clean:
	@echo Borrando los ficheros .o del directorio $(OBJ)...
	rm $(OBJ)/*.o

# Regla que genera la documentación con doxygen:
documentacion:
	doxygen $(DOC)/doxys/Doxyfile

