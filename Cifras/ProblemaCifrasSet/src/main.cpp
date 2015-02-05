//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Problema de la Cifras con set de la STL.
/// 
//////////////////////////////////////////////////////////////

# include <iostream>
# include <vector>
# include <string>
# include <stdexcept>
# include <ctime>
# include <fstream>
# include "Algoritmo.h"

using namespace std;

int main(int argc, char *argv[]){

	if (argc != 2){
		cout << "Sintaxis: ./bin/problemaCifras <parameters.par>" << endl;
		exit(-1);
	}

	/* DECLARACIÓN DE VARIABLES Y OBJETOS */
	vector <int> elementos_iniciales;
	int objetivo, valor, num_elementos_iniciales;
	string lectura;
	string nombre_archivo = argv[1];

	// Inicia la lectura del archivo indicado por argv[1]. Si no existe se produce un error de ejecución:
    ifstream parametros(nombre_archivo.c_str());
    if (!parametros){
        throw runtime_error("No existe el archivo " + (string) argv[1]);
    }

    do{
    	parametros >> lectura;
    }while(lectura != "NumeroDatos=");

    parametros >> num_elementos_iniciales;

	do{
    	parametros >> lectura;
    }while(lectura != "Datos=");

	for (int i = 0; i < num_elementos_iniciales; i++){
		parametros >> valor;
		elementos_iniciales.push_back(valor);
	}

	do{
    	parametros >> lectura;
    }while(lectura != "ValorObjetivo=");

	parametros >> objetivo;

	Algoritmo solver(elementos_iniciales, objetivo);

	clock_t start;
    double duration;
	start = clock();
	
	solver.resolver();
	
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "Tiempo de Cómputo: " << duration << " segundos" << endl;

	solver.imprimirSolucion();
	cout << endl;
	
	return 0;
}