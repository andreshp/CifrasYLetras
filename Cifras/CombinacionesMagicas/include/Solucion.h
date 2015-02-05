//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Combinaciones Mágicas del Problema de la Cifras.
/// 
//////////////////////////////////////////////////////////////

# ifndef SOLUCION_H
# define SOLUCION_H

	# include <string>
	# include <vector>
	# include <iostream>
	
	using namespace std ;
	
	/**
	 * Clase Solucion. Representa una posible solución al problema de las cifras.
	 */
	
	class Solucion {
	private:
		
		/**
		 * @brief resultado de la solución, resultado de realizar una serie de operaciones con 
		 * algunos de los elementos iniciales.
		 */
		int resultado;

		/**
		 * @brief Punteros a las dos soluciones padres de la actual.
		 */
		const Solucion * padre1, *padre2;
		
		/**
		 * @brief Tipo de operación realizada entre los dos padres.
		 * @brief Hay 4 tipos: +, *, padre1-padre2, padre1 / padre2 
		 * (- y / no son conmutativos, esto se arregla poniéndo los padres en el orden correcto al construir la solución).
		 * La operación resta solo puede realizarse para el sentido que de un resultado positivo.
		 * La operación división solo puede realizarse en caso de ser exacta.
		 */
		int operacion;

	public:
		
		/**
		 * @brief Constructor de la clase.
		 */
		Solucion(int resultado, Solucion *padre1, Solucion *padre2, int operacion);
		
		/**
		 * @brief Método inline que devuelve el resultado de la solución.
		 */
		inline int getResultado() const {
			return resultado;
		}

		/**
		 * @brief Sobrecarga del operador <.
		 * @brief Una solución es mejor (<) que otra si es menor su distancia al resultado objetivo del problema.
		 */
		inline bool operator<(const  Solucion &otra) const {
			return (this->resultado < otra.resultado);
		}
		
		/**
		 * @brief Sobrecarga del operador >.
		 * @brief Una solución es peor (>) que otra si es mayor su distancia al resultado objetivo del problema.
		 */
		inline bool operator>(const  Solucion &otra) const {
			return (this->resultado > otra.resultado);
		}

		/**
		 * @brief Sobrecarga del operador <=.
		 * @brief Una solución es mejor o igual (<=) en términos de su resultado que otra 
		 * si es menor su distancia al resultado objetivo del problema.
		 */
		inline bool operator<=(const  Solucion &otra) const {
			return (this->resultado <= otra.resultado);
		}

		/**
		 * @brief Sobrecarga del operador >=.
		 * @brief Una solución es peor o igual (>=) en términos de su resultado que otra 
		 * si es mayor su distancia al resultado objetivo del problema.
		 */
		inline bool operator>=(const  Solucion &otra) const {
			return (this->resultado >= otra.resultado);
		}

		/**
		 * @brief Sobrecarga del operador ==.
		 * @brief Una solución es igual (==) en términos de su resultado que otra 
		 * si es igual su distancia al resultado objetivo del problema.
		 */
		inline bool operator==(const  Solucion &otra) const {
			return (this->resultado == otra.resultado);
		}
	};
# endif