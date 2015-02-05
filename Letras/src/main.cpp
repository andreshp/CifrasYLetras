////////////////////////////////////////////////////////////
/// Autor: Andrés Herrera Poyatos
/// Universidad de Granada, 2º DGMII, Estructura de Datos
/// Practica Final, main.cpp 
////////////////////////////////////////////////////////////

/**
 * @file main.cpp
 * @brief Programa principal que iteractúa con el usuario posibilitando
 * el manejo del pograma letras, su diccionario y los ajustes del mismo.
 *
 * Proporciona una serie de opciones para jugar a letras.
 * Para una mayor información sobre las mismas ejecutar la orden ./bin/letras -h
 */

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <set>
# include <map>
# include "Dictionary.h"
# include "LetterSet.h"
# include "LetterBag.h"

using namespace std;

// Sintaxis del programa:
void sintaxis(){
    cout << "Sintaxis: ./bin/letras <argumentos opcionales> <fichero con el diccionario> <argumentos pertinentes>" << endl;
    cout << "Para una mayor información ejecutar la orden ./bin/letras -h" << endl;
}

  
int main(int argc, char * argv[]){

    // Se comprueba que hay suficientes argumentos:
    if (argc < 2){
        sintaxis();
        return 0;
    }

    // Inicializa el generador de números aleatorios:
    srand(time(NULL));

    // Declaración de variables:
    char *dictionary_file, *letters_file, letter;
    int option, num_letters, count_letter = 1;
    string word;
    vector<string> words;


    ////////////////////////////////// COMPROBACIÓN DE LOS ARGUMENTOS //////////////////////////////////
    
    // Si se ha elegido una opción se comprueba cual es.
    // En caso contrario es la opción 0:
    if (argv[1][0] == '-'){       // Toda opción que no sea por defecto comienza con -
 
        if (argv[1][1] == '\0'){  // Compruebo que no se ha proporcionado el argumento '-'
            sintaxis();
            exit(-1);
        }
 
        // Para cada posible opción compruebo que la llamada es correcta y 
        // asigno las variables correspondientes:
        switch (argv[1][1]){
            case 'a': // Se añaden varias palabras al diccionario:
            {
                if (argc >= 4){  // Debe tener al menos 4 argumentos.
                    option = 1;  // Le corresponde la opción 1.
                    dictionary_file = argv[2];
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }
            case 'b': // Busca en el diccionario varias palabras e indica si existen:
            {
                if (argc >= 4){   // Debe tener al menos 4 argumentos.
                    option = 2;   // Le corresponde la opción 2.
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }
            case 'c': // Calcula un archivo con las letras del diccionario:
            {
                if (argc == 3 || argc == 4){   // Debe tener 3 o 4 argumentos.
                    option = 3;   // Le corresponde la opción 3.
                    if (argc == 4){
                        letters_file = argv[3];
                    }
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }
            case 'e': // Elimina del diccionario varias palabras:
            {
                if (argc >= 4){   // Debe tener al menos 4 argumentos.
                    option = 4;   // Le corresponde la opción 4.
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }
            case 'h':
            {
                cout << "\n                                *****************************************************" << endl;
                cout << "                                *                      Letras                       *" << endl;
                cout << "                                *         Autor: Andrés Herrera Poyatos             *" << endl;
                cout << "                                *****************************************************" << endl << endl;
                cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
                cout << "* Resumen: Programa para jugar a Letras." << endl << endl;
                cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
                cout << "* Opciones:" << endl << endl;
                cout << "Por defecto: Juega al juego de las letras para los ajustes dados. " << endl;
                cout << "                    Sintaxis: ./bin/letras <Diccionario> <Archivo con las Letras> <Nº de letras>" << endl << endl;
                cout << "-a         : Añade al diccionario seleccionado las palabras dadas." << endl;
                cout << "                    Sintaxis: ./bin/letras -a <Diccionario> <Varias Palabras>" << endl << endl;
                cout << "-b         : Busca en el diccionario las palabras dadas como argumento e indica si existen." << endl;
                cout << "                    Sintaxis: ./bin/letras -b <Diccionario> <Palabras a buscar>" << endl << endl;
                cout << "-c         : Calcula un archivo con las letras de un diccionario dado, sus frecuencias y una puntuación entre 1 y 10 asignada según estas frecuencias." << endl;
                cout << "                    Sintaxis: ./bin/letras -c <Diccionario> <Opcional: Nombre del archivo donde almacenar el resultado>" << endl << endl;
                cout << "-e         : Elimina del diccionario seleccionado varias palabras." << endl;
                cout << "                    Sintaxis: ./bin/letras -e <Diccionario> <Varias Palabras>" << endl << endl;
                cout << "-h         : Muestra por pantalla un manual de ayuda con las diferentes opciones del programa." << endl;
                cout << "                    Sintaxis: ./bin/letras -h" << endl << endl;
                cout << "-l         : Muestra por pantalla aquellas palabras del diccionario con longitud deseada." << endl;
                cout << "                    Sintaxis: ./bin/letras -l <Diccionario> <Longitud>" << endl << endl;
                cout << "-p         : Juega al juego de las letras en su versión por puntuación. " << endl;
                cout << "                    Sintaxis: ./bin/letras -p <Diccionario> <Archivo con las Letras> <Nº de letras>" << endl << endl;
                cout << "-u         : Une los dos diccionarios seleccionados almacenando el diccionario resultante con el nombre dado." << endl;
                cout << "                    Sintaxis: ./bin/letras -u <Diccionario 1> <Diccionario 2> <Opcional: Nombre del nuevo diccionario>" << endl << endl;
                cout << "---------------------------------------------------------------------------------------------------------------------" << endl << endl;
                exit(0);
                break;
            }
            case 'l': // Muestra por pantalla aquellas palabras del diccionario con longitud deseada:
            {
                if (argc == 4){   // Debe tener exactamente 4 argumentos.
                    option = 5;   // Le corresponde la opción 5.
                    num_letters = atoi(argv[3]);
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }
            case 'p': // Juega al juego de las letras en su versión por puntuación:
            {
                if (argc == 5){   // Debe tener exactamente 5 argumentos.
                    option = 6;   // Le corresponde la opción 6.
                    letters_file = argv[3];
                    num_letters = atoi(argv[4]);
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }
            case 'u': // Une dos diccionarios:
            {
                if (argc == 4 || argc == 5){   // Debe tener 4 o 5 argumentos.
                    option = 7;   // Le corresponde la opción 7.
                }
                else{
                    sintaxis();
                    exit(-1);
                }
                break;
            }            
            default: // No existe la opción elegida:
            {
                cout << "No existe la opción " << (string)argv[1] << ". Para una mayor información ejecutar la orden ./bin/letras -h" << endl;
                break;
            }
        }
        // Se asigna el archivo con el diccionario:
        dictionary_file = argv[2];
    }
    else if (argc == 4){ // Opción por defecto: Se juega al juego de las Letras.
        option = 0;      // Le corresponde la opción 0.
        dictionary_file = argv[1];
        letters_file = argv[2];
        num_letters = atoi(argv[3]);
    }
    else{
        sintaxis();
        exit(-1);
    }

    ////////////////////////////////// EJECUCIÓN DE LAS OPCIONES //////////////////////////////////

    try{
        
        // Se carga el diccionario en memoria:
        Dictionary D(dictionary_file);

        switch(option){
            case 0: // Opción por defecto: Se juega al juego de las Letras:
            {
                LetterSet S(letters_file);
                LetterBag B(S.getLetterBag());
            
                vector<string> words;
                cout << "LETRAS: ";
            
                // Calculo las letras:
                multiset <char> letters;
                for (int i = 0; i < num_letters; i++){
                    letter = B.randomLetter();
                    cout << letter << " ";
                    letters.insert(letter);
                }
                cout << endl;
            
                // Preparo un map con las mismas. La clave del map son las letras, que tienen asociado
                // un entero con el número de veces que se puede utilizar.
                map<char, int> map_letters;
                letter = *(letters.begin());
                for (multiset<char>::iterator i = ++(letters.begin()); i != letters.end(); i++){
                    if (*i != letter){
                        map_letters.insert(pair<char,int>(letter, count_letter));
                        letter = *i;
                        count_letter = 1;
                    }
                    else{
                        count_letter++;
                    }
                }
                map_letters.insert(pair<char,int>(letter, count_letter));

                // Calculo la palabra más larga formada por las letras anteriores:
                words = D.largestWord(map_letters);

                // Leo la solución del usuario:
                cout << "Introduzca la palabra más larga formada por las " << num_letters << " letras anteriores: ";   
                cin >> word;
            
                // Compruebo si es válida:
                if (D.find(word)){

                    bool es_valida = true;
                    map<char,int>::iterator it;
                    for (int i = 0; i < word.length() && es_valida; i++){
                        it = map_letters.find(word[i]);
                        if (it != map_letters.end() && it->second > 0){
                            it->second--;
                        }
                        else{
                            es_valida = false;
                        }
                    }

                    if (es_valida){
                        if (word.length() < words[0].length()){
                            cout << "Ha perdido. Su palabra tiene una longitud de " << word.size() << " letras." << endl;
                        }
                        else{
                            cout << "Ha ganado. Su palabra es la mejor solución." << endl;    
                        }
                    }
                    else{
                        cout << "La palabra \"" << word << "\" contiene letras no válidas" << endl;
                    }
                }
                else{
                    cout << "No existe la palabra \"" << word << "\"" << "." << endl;
                }

                cout << "Las mejores soluciones (longitud " << words[0].size() << ") son: " << endl;
                for (int i = 0; i < words.size(); i++){
                    cout << words[i] << endl;
                }

                break;
            }
            case 1: // Se añade una serie de palabras al diccionario:
            {
                for (int i = 3; i < argc; i++){
                    D.insert((string) argv[i]);
                }

                ofstream dic(dictionary_file);
                if(!dic){
                    throw runtime_error("Error al guardar el diccionario.");
                }
                
                dic << D << endl;
                break;
            }
            case 2: // Se busca una serie de palabras en el diccionario:
            {
                bool existe;
                for (int i = 3; i < argc; i++){
                    existe = D.find((string) argv[i]);
                    cout << (string) argv[i] << " -> " << (existe ? "Existe" : "No existe") << endl;
                }

                break;
            }
            case 3: // Calcula un archivo con las letras del diccionario:
            {
                LetterSet S((string)dictionary_file);

                if (argc == 4){
                    ofstream let(letters_file);
                    if(!let){
                        throw runtime_error("Error al guardar las letras obtenidas.");
                    }
                    let << S << endl;
                }
                else{
                    cout << S << endl;
                }
                break;
            }
            case 4: // Se eliminan una serie de palabras del diccionario:
            {
                bool eliminada;
                for (int i = 3; i < argc; i++){
                    eliminada = D.erase((string) argv[i]);
                    cout << (string) argv[i] << " -> " << (eliminada ? "Eliminada" : "No encontrada") << endl;
                }

                ofstream dic(dictionary_file);
                if(!dic){
                    throw runtime_error("Error al guardar el diccionario.");
                }
                
                dic << D << endl;
                break;
            }
            case 5: // Se obtienen las palabras del diccionario con una determinada longitud:
            {
                words = D.wordsWithLength(num_letters);
                if (words.size() > 0){
                    cout << "Palabras de longitud " << num_letters << ":" << endl;
                    for (int i = 0; i < words.size(); i++){
                        cout << words[i] << endl;
                    }                    
                }
                else{
                    cout << "No hay palabras de longitud " << num_letters << endl;
                }

                break;
            }
            case 6: // Se juega al juego de las Letras con puntuación:
            {
                LetterSet S(letters_file);
                LetterBag B(S.getLetterBag());
                S.printScore(cout);
            
                cout << "\nLETRAS: ";
            
                // Calculo las letras:
                multiset <char> letters;
                for (int i = 0; i < num_letters; i++){
                    letter = B.randomLetter();
                    cout << letter << " ";
                    letters.insert(letter);
                }
                cout << endl;
            
                // Preparo un map con las mismas:
                map<char, pair<int,int> > map_letters;
                letter = *(letters.begin());
                for (multiset<char>::iterator i = ++(letters.begin()); i != letters.end(); i++){
                    if (*i != letter){
                        map_letters.insert(pair<char,pair<int,int> >(letter, pair<int,int>(S.getLetterScore(letter), count_letter) ));
                        letter = *i;
                        count_letter = 1;
                    }
                    else{
                        count_letter++;
                    }
                }
                map_letters.insert(pair<char,pair<int,int> >(letter, pair<int,int>(S.getLetterScore(letter), count_letter)));

                // Calculo la palabra más larga formada por las letras anteriores:
                words = D.highestScoredWord(map_letters);                    

                cout << "Introduzca la palabra más larga formada por las " << num_letters << " letras anteriores: ";   
                cin >> word;
            
                if (D.find(word)){

                    bool es_valida = true;
                    map<char, pair<int,int> >::iterator it;
                    for (int i = 0; i < word.length() && es_valida; i++){
                        it = map_letters.find(word[i]);
                        if (it != map_letters.end() && it->second.second > 0){
                            it->second.second--;
                        }
                        else{
                            es_valida = false;
                        }
                    }

                    if (es_valida){
                        if (S.getWordScore(word) < S.getWordScore(words[0])){
                            cout << "Ha perdido. Su palabra tiene la siguiente puntuación: " << S.getWordScore(word) << endl;
                        }
                        else{
                            cout << "Ha ganado. Su palabra tiene la máxima puntuación posible." << endl;    
                        }
                    }
                    else{
                        cout << "La palabra \"" << word << "\" contiene letras no válidas" << endl;
                    }
                }
                else{
                    cout << "No existe la palabra \"" << word << "\"" << "." << endl;
                }

                cout << "Las mejores soluciones (puntuación " << S.getWordScore(words[0]) << ") son: " << endl;
                for (int i = 0; i < words.size(); i++){
                    cout << words[i] << endl;
                }

                break;
            }
            case 7: // Se unen dos diccionarios:
            {
                ifstream dic(argv[3]);
                if(!dic){
                    throw runtime_error("Error al abrir el segundo diccionario.");
                }
                dic >> D; // No sobrescribe las palabras anteriores.

                if (argc == 5){ // Si se ha indicado un nombre se guarda como tal.
                    ofstream out(argv[4]);
                    if(!out){
                        throw runtime_error("Error al guardar el diccionario.");
                    }
                    out << D << endl;
                }
                else{          // En caso contrario se imprime por pantalla. 
                    cout << D << endl;
                }

                break;
            }
        }
    }
    catch(runtime_error excepcion){
        cout << "ERROR DE EJECUCIÓN: " << excepcion.what() << endl;
        exit(-1);
    }    
}
