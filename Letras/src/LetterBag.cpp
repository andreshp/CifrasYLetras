////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase LetterBag, archivo .cpp
////////////////////////////////////////////////////////////

/**
 * @file LetterBag.cpp
 * @brief Implementación del TDA LetterBag.
 *
 * Para una mayor descripción ver "LetterBag.h".
 */

# include "LetterBag.h"

////////////////////////////* MÉTODOS PÚBLICOS *///////////////////////////////

/* __________________________ Constructor de la Clase ___________________________ */

LetterBag::LetterBag(const vector <char> &letters){
    if (letters.size() > 0){
        this->letters = letters;
    }
    else{
        throw runtime_error("LetterBag: No se puede construir el objeto sin letras");
    }
}

/* ______________________________ randomLetter _______________________________ */

char LetterBag::randomLetter(){
    int index = rand() % letters.size();
    return letters[index];
}

/* ________________________________________________________________________ */
