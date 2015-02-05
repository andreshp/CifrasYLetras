############################################################
# Autor: Andrés Herrera Poyatos
# Universidad de Granada, 2º DGMII, Estructura de Datos
# Practica Final, makefile
############################################################

# ************* VARIABLES ************* #

# Compilador y Flags:
CXX=g++
CC=$(CXX)
CPPFLAGS=-c -g
CXXFLAGS=-I$(INC)

# Directorios:
BIN=./bin
INC =./include
OBJ=./obj
SRC=./src

# Módulos, Códigos Fuentes y Ejecutable
EXECUTABLE=letras
EXECUTABLE_OBJECTS=$(OBJ)/main.o $(OBJ)/Dictionary.o $(OBJ)/LetterBag.o $(OBJ)/LetterSet.o 
INCLUDES_H=$(INC)/Trie.h $(INC)/Trie.cpp $(INC)/GeneralTree.h $(INC)/GeneralTree.cpp $(INC)/Dictionary.h $(INC)/Letter.h $(INC)/LetterBag.h $(INC)/LetterSet.h

all: $(BIN)/$(EXECUTABLE)

# ************ Compilación de módulos ************ #

# Se crea el archivo ejecutable:
$(BIN)/$(EXECUTABLE): $(EXECUTABLE_OBJECTS)
	@echo "Creando el ejecutable $@..."
	$(CC) -o $(BIN)/$(EXECUTABLE) $(EXECUTABLE_OBJECTS)

# Creación del módulo main.o
$(OBJ)/main.o: $(SRC)/main.cpp $(INCLUDES_H)
	@echo "Creando el modulo objeto $@..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/main.cpp

# Creación del módulo Dictionary.o
$(OBJ)/Dictionary.o: $(SRC)/Dictionary.cpp $(INCLUDES_H)
	@echo "Creando el modulo objeto $@..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/Dictionary.cpp

# Creación del módulo LetterBag.o
$(OBJ)/LetterBag.o: $(SRC)/LetterBag.cpp $(INCLUDES_H)
	@echo "Creando el modulo objeto $@..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/LetterBag.cpp

# Creación del módulo LetterSet.o
$(OBJ)/LetterSet.o: $(SRC)/LetterSet.cpp $(INCLUDES_H)
	@echo "Creando el modulo objeto $@..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $(SRC)/LetterSet.cpp

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
