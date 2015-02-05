////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase LetterBag, archivo .h
////////////////////////////////////////////////////////////

/**
 * @file LetterBag.h
 * @brief Fichero cabecera del TDA LetterBag.
 *
 * Gestiona una Letra, que contiene la siguiente información:
 * 
 * - Carácter que la representa.
 * - Frecuencia utilizada en determinado idioma.
 * - Puntuación asignada en el juego de las Letras.
 */

# ifndef LETTERBAG_H
# define LETTERBAG_H

# include <vector>
# include <stdlib.h>     // srand, rand
# include <time.h>
# include <stdexcept>
# include <iostream>

using namespace std;

/**
 * @brief T.D.A. LetterBag.
 * 
 * ### Descripción del tipo de dato abstracto ###
 *
 * Una instancia *C* del tipo de dato abstracto LetterBag
 * permite obtener letras aleatorias con una probabilidad prefijada
 * de antemano.
 *
 * Se utiliza en combinación con la clase LetterSet para obtener letras
 * con probabilidad la frecuencia de las letras contenidas en el conjunto.
 *  
 * Para poder usar el tipo de dato LetterBag se debe incluir el fichero:
 * 
 * <tt>\#include LetterBag.h</tt>
 *
 * ### Información sobre la Implementación ###
 *
 * La implementación se realiza utilizando un vector de caracteres en el que
 * cada letra se encuentra repretida una serie de veces. Para obtener una letra
 * de forma aleatoria se obtiene un entero entre 0 y el tamaño del vector -1
 * y se devuelve la letra almacenada en esa componente. De esta forma la 
 * probabilidad de obtener determinada letra responde al número de veces
 * que se encuentra repetida en el vector partido el tamaño del mismo.
 *  
 * @author Andrés Herrera Poyatos
 * @date 27 de diciembre de 2014
 */
class LetterBag{

    private:

        /**
         * @brief Vector con los caracteres asociados a las letras. 
         * 
         * Cada letra está repetida una serie de veces de forma que la probabilidad 
         * de obtener determinada letra responde a el número de veces que se encuentra
         * en el vector partido del tamaño del mismo.
         */
        vector<char> letters;

    public:

        /**
         * @brief Constructor de la clase.
         * @param Vector con los caracteres asociados a las letras que se asigna 
         * al dato miembro.
         */
        LetterBag(const vector<char> &letters);

        /**
         * @brief Devuelve un carácter de forma aleatoria entre los que conforman el vector *letters*
         *
         * La probabilidad de obtener determinada letra responde a el número de 
         * veces que se encuentra en el vector partido del tamaño del mismo. 
         */
        char randomLetter();
};

# endif
