////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase Letter, archivo .h
////////////////////////////////////////////////////////////

/**
 * @file Letter.h
 * @brief Fichero cabecera del TDA Letter.
 *
 * Gestiona una Letra, que contiene la siguiente información:
 * 
 * - Carácter que la representa.
 * - Frecuencia utilizada en determinado idioma.
 * - Puntuación asignada en el juego de las Letras.
 */

# ifndef LETTER_H
# define LETTER_H

using namespace std;

/**
 * @brief T.D.A. Letter.
 * 
 * ### Descripción del tipo de dato abstracto ###
 *
 * Una instancia del tipo de dato abstracto Letter contiene la información
 * necesaria para utilizar determinada letra en las demás clases. La 
 * información es la siguiente:
 * 
 * - Carácter que la representa.
 * - Frecuencia utilizada en determinado idioma.
 * - Puntuación asignada en el juego de las Letras.
 * 
 * Para poder usar el tipo de dato LetterSet se debe incluir el fichero:
 * 
 * <tt>\#include Letter.h</tt>
 *
 * ### Información sobre la Implementación ###
 *
 * Contiene un dato miembro por cada dato, un constructor y los correspondientes
 * métodos necesarios para tener acceso a los datos.
 *  
 * @author Andrés Herrera Poyatos
 * @date 27 de diciembre de 2014
 */

class Letter{
    private:

        /**
         * @brief Carácter que representa a la letra.
         */
        char character;
        
        /**
         * @brief Frecuencia de la letra en determinado lenguaje.
         */
        int frequency;

        /**
         * @brief Puntuación asociada a la letra.
         */
        int score;

    public:

        /**
         * @brief Constructor de la clase.
         */
        Letter(char character, int frequency, int score) : character(character), frequency(frequency), score(score)
        {}

        /**
         * @brief Devuelve una copia del carácter asociado a la letra.
         */
        inline char getCharacter() const{
            return character;
        }

        /**
         * @brief Devuelve una copia del carácter asociado a la letra.
         */

        inline int getFrequency() const{
            return frequency;
        }

        /**
         * @brief Devuelve una copia de la puntuación asociada a la letra.
         */
        inline int getScore() const{
            return score;
        }

        /**
         * @brief Sobrecarga del operador < para las letras. 
         * Compara solo el carácter asociado.
         */
        inline bool operator<(const Letter &other) const{
            return character < other.character;
        }
};

#endif