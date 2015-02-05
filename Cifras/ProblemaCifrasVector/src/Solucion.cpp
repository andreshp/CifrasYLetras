//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Problema de la Cifras con vectores.
/// 
//////////////////////////////////////////////////////////////

# include "Solucion.h"

/////////////////////* Métodos Públicos: */////////////////////

// Constructor:
Solucion::Solucion(int resultado, int clase, Solucion *padre1, Solucion *padre2, int operacion){
  this->resultado = resultado;
  this->clase = clase; 
  this->padre1 =padre1; 
  this->padre2 = padre2; 
  this->operacion = operacion;
}

// Método que imprime de forma recursiva las opreaciones realizadas en el cálculo de la solución.
void Solucion::imprimirCamino() const {
	if (padre1 != NULL && padre2 != NULL){ // Si quedan padres hay que imprimir paréntesis y operaciones.
		if (padre1->padre1 != NULL && (operacion == 2 || operacion == 4)){
			cout << "(";
			padre1->imprimirCamino();
			cout << ") ";
		}
		else{
			padre1->imprimirCamino();
		}
		if (operacion == 1){
			cout << " + ";
		}
		else if (operacion == 2){
			cout << " * ";
		}
		else if (operacion == 3){
			cout << " - ";
		}
		else if (operacion == 4){
			cout << " / ";
		}
		if (padre2->padre2 != NULL){
			cout << "(";
			padre2->imprimirCamino();
			cout << ")";
		}
		else{ // Si no quedan padres imprimo el número.
			padre2->imprimirCamino();
		}
	}
	else{
		cout << resultado;
	}
}