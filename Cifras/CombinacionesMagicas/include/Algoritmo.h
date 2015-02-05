//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Combinaciones Mágicas del Problema de la Cifras.
/// 
//////////////////////////////////////////////////////////////


# ifndef ALGORITMO_H
# define ALGORITMO_H

    # include <string>
    # include <vector>
    # include "Solucion.h"
    # include <set>
    # include <cmath>
    # include <algorithm>
    # include <iostream>

    using namespace std ;
    
    /**
     * Clase Algoritmo. Contiene el algoritmo utilizado para resolver el problema de las cifras
     * así como las variables requeridas para el mismo. VERSIÓN COMBINACIONES MÁGINAS.
     * Encuentra todas las combinaciones mágicas posibles.
     */
    
    class Algoritmo {
    private:

        /**
         * @brief Número de elementos iniciales a combinar para obtener el valor objetivo.
         */
        int num_elementos_iniciales;

        /**
         * @brief Número de clase de soluciones.
         * @brief Las clase están generadas por la relación de equivalencia: nº elementos inciales que componen la solución.
         * Hay 2^num_elementos_iniciales clase (contando la clase vacía).
         */
        int num_clases;

        /**
         * @brief Array con las clave que representan a las clases.
         * @brief Contiene los números desde el 0 al 2^n -1  ordenados por número de unos en su representación binaria.
         */
        int *clave;

        /**
         * @brief Array de punteros a las clases. 
         * @brief Cada clase contendrá todas las soluciones al problema pertenecientes a la misma (sin valores repetidos).
         */
        set <Solucion> *clase;

        /**
         * @brief Límite inferior del intervalo de enteros positivos que se pretenden conseguir como combinación de los elementos iniciales.
         */
        int limite_inferior;

        /**
         * @brief Límite superior del intervalo de enteros positivos que se pretenden conseguir como combinación de los elementos iniciales.
         */
        int limite_superior;

        /**
         * @brief Número de valores a conseguir (longitud del interalo).
         * @brief num_a_conseguir = limite_superior - limite_inferior + 1 
         */
        int num_a_conseguir;

        /**
         * @brief Puntero a un array de bools que indica si el valor correspondiente a la posición i-ésima ha sido conseguido o no.
         */
        bool *conseguidos;

        /**
         * @brief Número de valores conseguidos dentro del rango dado por limite_inferior y limite_superior.
         */
        int num_conseguidos;


        //////////* MÉTODOS PRIVADOS *///////////////////
        
        /**
         * @brief Método que ordena el array clave según la relación de orden dada por el número de unos en binario del número.
         * @brief Utilizo sort() de la stl (n log n) y una función compare.
         * De esta forma la componente i de números contiene el valor correspondiente a la clase i-ésima.
         */
        void ordenarClaves();
        
        /**
         * @brief Método que añade a la clase[i] los resultados generados por combinar la clase[j] con clase[i-j].
         * @brief PRECONDICIONES: la clase[j] es una subclase de la  clase[i].
         * @param i Clase a la que pertenecen los resultados generados.
         * @param j Clase a partir de la cual se puede generar la clase i-ésima. Nótese que clase[i-j] contiene 
         * las soluciones generadas por los elementos iniciales que generan clase[i] y no generan clase[j].
         */
        void generarSoluciones(int i, int j);
        
        /**
         * @brief Método que crea el espacio para el array clase y sus clave, ordenando este último.
         * @brief Se llama en el constructor y utiliza el método ordenarClaves().
         */
        void crearClases();

    public:

        /**
         * @brief Constructor de la clase.
         * @brief Se pretende resolver el problema de las cifras asociado a elementos_iniciales y objetivo.
         * @param elementos_iniciales Vector con los elementos iniciales del problema.
         */
        Algoritmo(const vector <int> & elementos_iniciales, int limite_inferior, int limite_superior);
        
        /**
         * Destructor de la clase.
         */
        ~Algoritmo();

        /**
         * Método que resuelve el problema dado mediante el algoritmo explicado en el pdf.
         */
        void resolver();
    };

    /**
     * @brief Función auxiliar que devuelve el número de unos en binario del número dado.
     */
    int numeroUnos(int indice);

    /**
     * @brief Función auxiliar que devuelve si un número positivo si i tiene más unos en binario
     * que j, 0 si tienen igual número de unos y un número negativo si tiene menos.
     * @brief Se utiliza en el método ordenarClaves (sort de la stl).
     */
    bool comparar(int i,int j);

# endif