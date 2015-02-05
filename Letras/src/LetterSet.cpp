////////////////////////////////////////////////////////////
// Autor: Andrés Herrera Poyatos
// Universidad de Granada, 2º DGMII, Estructura de Datos
// Practica Final, Clase LetterSet, archivo .cpp
////////////////////////////////////////////////////////////

/**
 * @file LetterSet.cpp
 * @brief Implementación del TDA LetterSet.
 *
 * Para una mayor descripción ver "LetterSet.h".
 */

# include "LetterSet.h"

//------------------------------------ MÉTODOS PÚBLICOS ------------------------------------//

/* ________________________________ Constructor de la Clase 1 _________________________________ */

LetterSet::LetterSet(const char file[]){
    
    // Abro el archivo dado y leo los datos del mismo:
    string sfile = (string)file;    
    ifstream f(file);
    if (!f){
        throw runtime_error("No se puede abrir el archivo con las letras: " + sfile);
    }

    f >> *this;
}

/* ________________________________ Constructor de la Clase 2 _________________________________ */

LetterSet::LetterSet(string dictionary_file){
    updateLetters(dictionary_file.c_str());
}

/* ____________________________________ updateLetters ______________________________________ */

void LetterSet::updateLetters(const char dictionary_file[]){
    
    letters.clear();

    int num_letters = 0;
    double min_freq = 101, score;
    map <char, int> new_letters;
    map <char, int>::iterator it_map;
    
    // Abro el archivo dado y leo los datos del mismo:
    string sfile = (string)dictionary_file, word;    
    ifstream f(dictionary_file);
    if (!f){
        throw runtime_error("No se puede abrir el archivo con las letras: " + sfile);
    }

    // Se lee la primera palabra. Mientras queden líneas en el fichero,
    // se lee la siguiente palabra y se cuentan sus letras.
    getline(f, word, '\n');
    while(! f.eof() ){
        for (int i = 0; i < word.length(); i++){
            if ( (it_map = new_letters.find(word[i])) != new_letters.end()){
                it_map->second++;
            }
            else{
                new_letters.insert(pair<char,int>(word[i], 1));                
            }
        }
        num_letters += word.length();
        getline(f, word, '\n');
    }

    // Calculo la frecuencia mínima (en tanto por ciento):
    for (it_map = new_letters.begin(); it_map != new_letters.end(); it_map++){
        min_freq = min(100.0 * it_map->second / num_letters, min_freq);
    }

    // Inserto las letras con su correspondiente frecuencias y puntuación.
    // La puntuación se calcula acotada entre 1 y 10. La letra más frecuente obtiene un uno
    // y la letra menos frecuente obtiene un 10. La demás siguen una tendencia 1/x:
    for (it_map = new_letters.begin(); it_map != new_letters.end(); it_map++){
        score = nearbyint(10.0 / ( (100.0 * it_map->second) / num_letters - min_freq + 1)); // Puntuación entre 1 y 10
        score = (score == 0) ? 1 : score;
        
        it_map->second = nearbyint(100.0 * it_map->second / num_letters);                   // Frecuencia
        it_map->second = it_map->second == 0 ? 1 : it_map->second;
        letters.insert(Letter(it_map->first, it_map->second, score) );
    }

}

/* ___________________________________ getLetterBag _____________________________________ */

LetterBag LetterSet::getLetterBag() const{
    vector<char> vector_letters;

    for (set<Letter>::iterator i = letters.begin(); i != letters.end(); i++){
        for (int j = 0; j < i->getFrequency(); j++){
            vector_letters.push_back(i->getCharacter());
        }
    }

    return LetterBag(vector_letters);    
}

/* ___________________________________ getLetterScore _____________________________________ */

int LetterSet::getLetterScore(char letter){
    set<Letter>::iterator it = letters.find(Letter(letter,0,0));
    if (it != letters.end()){
        return it->getScore();
    }
    else{
        return -1;
    }
}

/* ___________________________________ getWordScore _____________________________________ */

int LetterSet::getWordScore(string word){
    int total_score = 0, letter_score;
    for (int i = 0; i < word.size(); i++){
        letter_score = getLetterScore(word[i]);
        if (letter_score > 0){
            total_score += letter_score;
        }
        else{
            total_score = -1;
            break;
        }
    }

    return total_score;
}

/* ___________________________________ printScore _____________________________________ */

void LetterSet::printScore(ostream & out){
    
    // Cabecera:
    out << "Letra Puntos\n";

    // Información: carácter frecuencia puntuación 
    for (set<Letter>::iterator i = letters.begin(); i != letters.end(); i++){
        out << "  " << i->getCharacter() << "     "  << i->getScore() << "\n"; 
    }
}

/* _______________________________ Sobrecarga del Operador >> _______________________________ */

istream & operator>>(istream & in, LetterSet & S){
    
    // Declaración de variables:
    string line;
    stringstream  ss;
    char character;
    int quantity, score;

    // Se lee la cabecera:
    getline(in, line, '\n');

    // Se lee la primera línea. Mientras queden líneas en el fichero,
    // se obtienen los datos de la última línea leída (que se insertan 
    // en el conjunto de letras) y se lee la siguiente línea.
    getline(in, line, '\n');

    while(! in.eof() ){
        ss << line;
        ss >> character >> quantity >> score;
        ss.clear();
        Letter letter(character, quantity, score);

        S.letters.insert(letter);

        getline(in, line, '\n');
    }

    return in;
}

/* ________________________________ Sobrecarga del Operador << _____________________________________ */

ostream & operator<<(ostream & out, const LetterSet & S){
    
    // Cabecera:
    out << "#Letra Cantidad Puntos\n";
    
    // Información: carácter frecuencia puntuación 
    for (set<Letter>::iterator i = S.letters.begin(); i != S.letters.end(); i++){
        out << i->getCharacter() << " " << i->getFrequency() << " " << i->getScore() << endl; 
    }

    return out;
}

/* _________________________________________________________________________________________________ */