//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Combinaciones Mágicas del Problema de la Cifras.
/// 
//////////////////////////////////////////////////////////////

# include "Solucion.h"

/////////////////////* Métodos Públicos: */////////////////////

// Constructor:
Solucion::Solucion(int resultado, Solucion *padre1, Solucion *padre2, int operacion){
  this->resultado = resultado;
  this->padre1 =padre1; 
  this->padre2 = padre2; 
  this->operacion = operacion;
}