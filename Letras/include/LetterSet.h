////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase LetterSet, archivo .h
////////////////////////////////////////////////////////////

/**
 * @file LetterSet.h
 * @brief Fichero cabecera del TDA LetterSet.
 *
 * Gestiona un conjunto de letras de la clase Letter.
 * Proporciona las operaciones de entrada y salida
 * necesarias para el buen funcionamiento del programa.  
 */

# ifndef LETTERSET_H
# define LETTERSET_H

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <set>
# include <map>
# include <cmath>
# include <algorithm>
# include "Letter.h"
# include "LetterBag.h"

using namespace std;

/**
 * @brief T.D.A. LetterSet.
 * 
 * ### Descripción del tipo de dato abstracto ###
 *
 * Una instancia *C* del tipo de dato abstracto LetterSet 
 * consiste en un conjunto de letras (objetos de la clase Letter).
 * Cada letra contiene su carácter correspondiente, su frecuencia
 * en el diccionario (en tanto por ciento) y su puntuación
 * para el juego de las letras. Para más información ver la clase Letter.
 *
 * Este T.D.A. permite crear tanto una LetterBag (bolsa de letras)
 * para obtener letras de forma aleatoria según la frecuencia de las mismas en el
 * diccionario, así como actualizar las letras, sus frecuencias y puntuaciones
 * según el diccionario en cuestión. Además contiene operaciones de entrada y salida
 * para mantener un archivo externo con la información utilizada por la clase.
 *
 * Para poder usar el tipo de dato LetterSet se debe incluir el fichero:
 * 
 * <tt>\#include LetterSet.h</tt>
 *
 * ### Información sobre la Implementación ###
 *
 * La implementación se realiza utilizando la clase **set** de la **STL** ya que
 * los caracteres pueden ser ordenados según el código ASCII. De esta forma se puede
 * imprimir el fichero con las letras ordenado alfabéticamente, asegurarse de que
 * ninguna letra se repite y demás comodidades sin perder prácticamente velocidad
 * pues el conjunto de letras suele tener un tamaño reducido.
 *  
 * @author Andrés Herrera Poyatos
 * @date 27 de diciembre de 2014
 */
class LetterSet{

    private:

        /**
         * @brief Conjunto con las letras que conforman el objeto de la clase LetterSet.
         */
        set <Letter> letters;
    
    public:

        /**
         * @brief Constructor de la clase. Lee el conjunto de letras a partir de un archivo con
         * la información correspondiente.
         * @param letters_file Nombre del archivo con las letras y la información necesaria.
         *
         * Se implementa llamando al operador >>.
         */
        LetterSet(const char letters_file[]);

        /**
         * @brief Constructor alternativo para la clase. Crea un objeto de la clase letras a partir de 
         * un diccionario.
         * @param dictionary_file Nombre del archivo con el diccionario.
         *
         * El objeto resultante contiene las letras que aparecen en el diccionario, su correspondiente
         * frecuencia y una puntuación asignada en relación a esta última. La operación se realiza 
         * llamando al método updateLetters.
         */
        LetterSet(string dictionary_file);

        /**
         * @brief Devuelve un objeto de la clase LetterBag construido a partir de las letras y 
         * frecuencias almacenadas.
         * @return Objeto de la clase LetterBag que permite obtener una letra aleatoria 
         * con probabilidad de que sea determinado carácter igual a la frecuencia de este
         * guardada en el conjunto de letras.
         */
        LetterBag getLetterBag() const;

        /**
         * @brief Obtiene la puntuación de una letra del conjunto.
         * @param  letter Caracter que representa la letra.
         * @return Puntuación de la letra si esta pertenece al conjunto.
         *  -1 en caso contrario.
         */
        int getLetterScore(char letter);

        /**
         * @brief Obtiene la puntuación de una palabra de letras del conjunto.
         * @param  word Palabra a puntuar.
         * @return Puntuación de la palabra. Si alguna letra de la misma no 
         * pertenece al conjunto se devuelve -1.
         */
        int getWordScore(string word);

        /**
         * @brief Imprime las letras con la puntuación correspondiente.
         * @param  out Flujo de salida.
         */
        void printScore(ostream & out);

        /**
         * @brief Actualiza el conjunto de letras con los datos obtenidos de un diccionario.
         * @param dictionary_file Nombre del archivo con el diccionario.
         * @pre El diccionario contiene una palabra por línea.
         * 
         * Las letras que se almacenarán en el conjunto son aquellas que aparecen en el diccionario.
         * La frecuencia de las mismas es la frecuencia con la que aparecen en el diccionario.
         * La puntuación se asigna de forma inversamente proporcional a dicha frecuencia como un 
         * número natural del 1 al 10.
         */
        void updateLetters(const char dictionary_file[]);

        /**
         * @brief Sobrecarga del operador >>. Lee de un flujo de entrada el conjunto de letras.
         * @param in Flujo de entrada.
         * @param S Conjunto de letras en el que se almacenan las letras e información leída.
         * @return El flujo de entrada para posibilitar el posterior uso del mismo.
         *
         * El fichero de entrada debe tener la siguiente forma:
         * #Letra Cantidad Puntos
         *    a     12       1
         *   ...    ...     ...
         */
        friend istream & operator>>(istream & in, LetterSet &S);

        /**
         * @brief Sobrecarga del operador <<. Escribe en un flujo de salida la información que 
         * contiene el conjunto de letras.
         * @param out Flujo de salida.
         * @param S El objeto de la clase LetterSet que se escribe.
         * @return El flujo de salida para posibilitar el posterior uso del mismo.
         *
         * La información escrita tiene la siguiente forma:
         * #Letra Cantidad Puntos
         *    a     12       1
         *   ...    ...     ...
         */
        friend ostream & operator<<(ostream & out, const LetterSet &S);

};

#endif