////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase Dictionary, archivo .cpp
////////////////////////////////////////////////////////////

/**
 * @file Dictionary.cpp
 * @brief Implementación del TDA Dictionary.
 *
 * Para una mayor descripción ver "Dictionary.h".
 */

# include "Dictionary.h"

////////////////////////////* MÉTODOS PRIVADOS *///////////////////////////////

/* ________________________________ Constructor de la Clase _________________________________ */

Dictionary::Dictionary(char file[]){
    
    // Abro el archivo dado y leo los datos del mismo:
    string sarchivo = (string)file;    
    ifstream f (file);
    if (!f){
        throw runtime_error("No se puede abrir el diccionario: " + sarchivo);
    }

    f >> *this;
}

/* ________________________________ Sobrecarga del Operador >> __________________________________ */

istream & operator>>(istream & in, Dictionary & D){
    
    // Declaración de variables:
    string word;

    // Se lee la primera palabra. Mientras queden líneas en el fichero,
    // se lee la siguiente palabra y se inserta en el diccionario.
    getline(in, word, '\n');

    while(! in.eof() ){
    
        D.insert(word);        
        getline(in, word, '\n');
    }

    return in;
}

/* ________________________________ Sobrecarga del Operador << _____________________________________ */

ostream & operator<<(ostream & out, const Dictionary & D){
    out << D.words_trie;
    return out;
}

/* _________________________________________________________________________________________________ */