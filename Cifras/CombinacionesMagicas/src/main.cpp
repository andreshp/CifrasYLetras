//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Combinaciones Mágicas del Problema de la Cifras.
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

vector <int> elementos;
int num_elementos_iniciales, limite_inferior, limite_superior, longitud_combinacion;

/**
 * Función recursiva que genera todas las combinaciones con repetición de longitud dada
 * para los elementos del conjunto indicado en parametros.par
 * @param elementos_iniciales Combinación con la que se inicializará la clase Algoritmo.
 * @param ultimo_elemento índice del último elemento añadio a la combinación del vector elementos_iniciales.
 * @param etapa Número de elementos asignados a la combinación. En la etapa longitud_combinación se ha finalizado
 * la combinación y se procede a comprobar si es o no mágica.
 */
void calcularCombinacionesMagicas(vector <int> elementos_iniciales, int ultimo_elemento, int etapa){
    if (etapa == longitud_combinacion){
        Algoritmo solver(elementos_iniciales, limite_inferior, limite_superior);
        solver.resolver();   
    }
    else{
        for (int i = ultimo_elemento; i < num_elementos_iniciales; i++){
            elementos_iniciales[etapa] = elementos[i];
            calcularCombinacionesMagicas(elementos_iniciales, i, etapa+1);
        }
    }
}

int main(int argc, char *argv[]){

	if (argc != 2){
		cout << "Sintaxis: ./bin/problemaCifras <parameters.par>" << endl;
		exit(-1);
	}

	/* DECLARACIÓN DE VARIABLES Y OBJETOS */
	int valor;
	string lectura;
	string nombre_archivo = argv[1];
    
    /* LECTURA DE DATOS */
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
		elementos.push_back(valor);
	}
    do{
        parametros >> lectura;
    }while(lectura != "LongitudCombinacion=");

    parametros >> longitud_combinacion;

    do{
        parametros >> lectura;
    }while(lectura != "LimiteInferior=");

    parametros >> limite_inferior;

    do{
        parametros >> lectura;
    }while(lectura != "LimiteSuperior=");

    parametros >> limite_superior;
    
	
    vector <int> elementos_iniciales(6);

    cout << "Calculando Combinaciones Mágicas..." << endl;

    ////////////////////////* EJECUCIÓN DEL ALGORITMO *////////////////////////
    clock_t start;
    double duration;
    start = clock();
    
    calcularCombinacionesMagicas(elementos_iniciales, 0, 0);
	
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "Tiempo de cómputo: " << duration << " segundos" << endl;

	cout << endl;
	
	return 0;
}