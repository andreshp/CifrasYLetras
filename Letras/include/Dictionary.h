////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase Dictionary, archivo .h
////////////////////////////////////////////////////////////

/**
 * @file Dictionary.h
 * @brief Fichero cabecera del TDA Dictionary.
 *
 * Gestiona un diccionario que posibilita la inserción y borrado de palabras
 * así como diferentes métodos de búsqueda de palabras que tengan determinadas
 * características. Proporciona además métodos de entrada y salida. 
 */

# ifndef DICTIONARY_H
# define DICTIONARY_H

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include "Trie.h"

using namespace std;


/**
 * @brief T.D.A. Dictionary.
 * 
 * ### Descripción del tipo de dato abstracto ###
 *
 * Un Dictionary (diccionario) consiste en un conjunto de palabras con métodos eficientes
 * de insercción, borrado y especialmente búsqueda. Posibilita la búsqueda de palabras
 * que tengan determinadas características como una longitud específica, estén formadas
 * por unos caracteres específicos o maximicen determinado criterio. Por ello
 * la clase Dictionary permite el desarrollo del juego de las cifras aportando métodos
 * que, dentro de las palabras formadas por determinados caracteres devuelvan la más 
 * larga o más puntuada.
 *
 * ### Información sobre la Implementación ###
 *
 * La implementación se realiza mediante la clase Trie instanciada a string y char. Se
 * proporciona por tanto una estructura *func* con los *operator()* necesarios para 
 * su funcionamiento.
 *
 * Las funcionalidades del diccionario prácticamente consisten en llamar a las operaciones
 * ofrecidas por la clase Trie.
 * 
 * @author Andrés Herrera Poyatos
 * @date 29 de diciembre de 2014
 */

class Dictionary{
    private:

        /**
         * @brief Estructura que posibilita instanciar un Trie a string y char.
         *
         * Contiene las sobrecargas del operador () que se especifican en la clase Trie.
         */
        struct func{
            /**
             * @brief Sobrecarga que asigna a *key* el carácter de *element* que ocupa 
             * la posición *pos*.
             * @param element  Palabra de la que se obtiene el carácter.
             * @param key      Referencia en la que se asigna el carácter.
             * @param pos      Posición que ocupa el carácter en memoria.
             * @return  *pos*+1 en caso de éxito. -1 en caso de error.
             */
            int operator()(string element, int pos, char &key){
                if (pos < element.size() && pos >= 0){
                    key = element[pos];
                    pos++;
                }
                else{
                    pos = -1;
                }
                return pos;
            }

            /**
             * @brief Sobrecarga que asigna a la componente de *element* que ocupa 
             * la posición *pos* el carácter *key*.
             * @param element  String que obtiene el carácter.
             * @param key      Carácter a asignar.
             * @param pos      Posición en la que se asigna el carácter.
             */
            void operator()(string &element, int pos, char key){
                if(pos >=  0){
                    if (element.size() > pos){
                        element[pos] = key;
                    }
                    else{
                        while (pos > element.size()){
                            element.push_back('\0');
                        }
                        element.push_back(key);
                    }
                }
            }

            /**
             * @brief Sobrecarga que asigna '\0' a la componente de *element* que ocupa 
             * la posición *pos*.
             * @param element  String que objetivo de la acción.
             * @param pos      Posición en la que se asigna el carácter '\0'.
             */
            void operator()(string &element, int pos){
                if (pos < element.size() && pos >= 0){
                    element[pos] = '\0';
                }
            }
        };

        /**
         * @brief Trie que conforma el interior del diccionario.
         *
         * Tbase = string, Tnode = char, f = func  
         */
        Trie<string, char, func> words_trie;

    public:

        /**
         * @brief Construye un diccionario vacío.
         */
        Dictionary();

        /**
         * @brief Construye un diccionario a partir de un archivo con las palabras.
         */
        Dictionary(char file[]);

        /**
         * @brief Elimina una palabra del diccionario.
         * @param word: la palabra que se quiere eliminar
         * @return True si la palabra estaba en el diccionario. False en el caso contrario.
         */
        inline bool erase(string word){
            words_trie.erase(word);            
        }

        /**
         * @brief Indica si una palabra está en el diccionario o no.
         * @param word: la palabra que se quiere buscar
         * @return True si la palabra esta en el diccionario. False en el caso contrario.
         */
        inline bool find(string word){
            words_trie.find(word);            
        }

        /**
         * @brief Busca la palabra con una mayor puntuación dentro de las que contienen solo las letras dadas por *letters*.
         * @param letters     map con las letras (su puntuación y el número de veces que se pueden repetir) 
         *                    que deben conformar las palabras candidatas. 
         *                        
         * Se llama a **highestScoredElement** de word_trie.
         * 
         * **Eficiencia:** O(tree.size() log(keys.size())). Habitualmente mucho menos. 
         */
        inline vector<string> highestScoredWord(map<char,pair<int,int> > &letters) const{
            return words_trie.highestScoredElement(letters);
        }

        /**
         * @brief Inserta una palabra en el diccionario.
         * @param word: La palabra que se pretende insertar.
         */
        inline void insert(string word){
            words_trie.insert(word);
        }

        /**
         * @brief Busca la palabra más larga dentro de las que contienen solo las letras dadas por *letters*.
         * @param letters     map con las letras (y el número de veces que se pueden repetir) 
         *                    que deben conformar las palabras candidatas. 
         *                        
         * Se llama a **largestElement** de word_trie.
         * 
         * **Eficiencia:** O(tree.size()). Habitualmente mucho menos. 
         */
        inline vector<string> largestWord(map<char,int> &letters) const{
            return words_trie.largestElement(letters);
        }

        /**
         *@brief Devuelve el numero de palabras en el diccionario.
         */
        inline int size() const{
            return words_trie.size();
        }

        /**
         * @brief Obtiene todas las palabras en el diccionario de una longitud dada.
         * @param length: Longitud de las palabras buscadas.
         * @return Un vector con las palabras de longitud especifica en el parametro de entrada.
         */
        inline vector<string> wordsWithLength(int length){
            return words_trie.elementsWithLength(length);
        }
        
        
        /**
         * @brief Sobrecarga del operador >>. Lee de un flujo de entrada un diccionario.
         * @param in Flujo de entrada.
         * @param D Diccionario en el que se almacenan las palabras leídas.
         * @return El flujo de entrada para posibilitar el posterior uso del mismo.
         */
        friend istream & operator>>(istream & in, Dictionary &D);

        /**
         *@brief Sobrecarga del operador <<. Escribe en un flujo de salida las palabras de un diccionario.
         *@param out Flujo de salida.
         *@param D  El objeto diccionario que se escribe.
         * @return El flujo de salida para posibilitar el posterior uso del mismo.
         */
        friend ostream & operator<<(ostream & out, const Dictionary &D);
};

#endif