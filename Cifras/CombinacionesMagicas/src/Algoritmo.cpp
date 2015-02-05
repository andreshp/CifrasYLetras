//////////////////////////////////////////////////////////////
///
/// Autor: Andrés Herrera Poyatos
/// 2º DGMII, Estructura de Datos, Reto 2
/// Combinaciones Mágicas del Problema de la Cifras.
/// 
//////////////////////////////////////////////////////////////

# include "Algoritmo.h"

/////////////////////////////* FUNCIONES AUXILIARES *///////////////////////

//  Función auxiliar que devuelve si un número positivo si i tiene más unos en binario
//  que j, 0 si tienen igual número de unos y un número negativo si tiene menos.
bool comparar(int i,int j){ 
    return (numeroUnos(i) < numeroUnos(j)); 
}

// Función auxiliar que devuelve el número de unos en binario del número dado.
int numeroUnos(int numero){
    int potencia2 = 1;
    int num_unos = 0;
    // Se ve el número de unos a través de potencias de 2:
    // Si numero & potencia2 = potencia2 entonces numero contiene el 
    // uno  característico de la potencia de 2 usada.
    while(potencia2 <= numero){
        if ( (numero & potencia2) == potencia2){
            num_unos++;
        }
        potencia2 *= 2;
    }
    return num_unos;
}

///////////////////////////* MÉTODOS PRIVADOS: *//////////////////////////

// Método que ordena las clave por número de unos de las mismas.
void Algoritmo::ordenarClaves(){
    sort(clave, clave + num_clases, comparar);
}

// Método privado que inicializa clase así como su representación numérica (clave).
void Algoritmo::crearClases(){
    num_clases = pow(2, num_elementos_iniciales); // Hay 2^num_elementos_iniciales clase.
    clase = new set <Solucion> [num_clases];     // Se reserva espacio para las clase y clave.
    clave = new int [num_clases];
    for (int i = 0; i < num_clases; i++){
        clave[i] = i;
    }
    ordenarClaves(); // Se ordenan las clave por números de unos.
}

///////////////////////////* MÉTODOS PÚBLICOS: *//////////////////////////
// Constructor:
Algoritmo::Algoritmo(const vector <int> & elementos_iniciales, int limite_inferior, int limite_superior){
    
    num_elementos_iniciales  = elementos_iniciales.size();

    // Se crean las clase donde se almacenarán las soluciones:
    crearClases();
    
    this->limite_inferior = limite_inferior; 
    this->limite_superior = limite_superior; 
    num_a_conseguir = limite_superior - limite_inferior + 1;

    conseguidos = new bool [num_a_conseguir];
    num_conseguidos = 0;
    for (int i = 0; i < num_a_conseguir; i++){
        conseguidos[i] = false;
    }

    // Se almacenan los elementos iniciales en las clase de clave: 000001 000010 000100 001000 010000 100000
    for (int i = 1; i <= num_elementos_iniciales; i++){
        Solucion elemental(elementos_iniciales[i-1], NULL, NULL, -1);
        clase[clave[i]].insert(elemental);
        if (elementos_iniciales[i-1] >= limite_inferior && elementos_iniciales[i-1] <= limite_superior){
            conseguidos[elementos_iniciales[i-1]] = true;
            num_conseguidos++;
        }
    }
}

// Destructor de la clase:
Algoritmo::~Algoritmo(){
    delete [] clase;
    delete [] clave;
    delete [] conseguidos;
}

// Se resuelve el problema de las cifras:
void Algoritmo::resolver(){
    static int num_combinaciones_magicas = 1;
    int subclases_usadas, numero_subclases, num_unos;
    bool *usados = new bool[num_clases]; // Array que indica si una clase se ha usado o no para generar la clase actual.

    // En cada iteración se crea una clase de las 2^num_elementos_iniciales posibles.
    // Nótese que las num_elementos_iniciales primeras clase ya están creadas (junto con la  vacía):
    for (int i = num_elementos_iniciales + 1; i < num_clases  && num_conseguidos < num_a_conseguir; i++){
        subclases_usadas = 0;
        num_unos = numeroUnos(clave[i]);
        numero_subclases = pow(2,num_unos-1) - 1; // Número de posibles combinaciones de subclases para generar la clase de clave clave[i].
        for (int k = 1; k < i; k++)
            usados[clave[k]] = false;
        if (num_unos > 6)
            break;
        // En cada iteración se comprueba si clase[clave[j]] es una subclase de clase[clave[i]] y no se ha usado para generar clase[clave[i]].
        // En tal caso clase[clave[i]-clave[j]] y clase[clave[j]] generan parte de las soluciones de clase[clave[i]] por las operaciones
        // definidas en Definición 6 y se añaden los resultados posibles.
        // Esto es: clave[j] ha sido generado por n elementos iniciales, clave[i]-clave[j] por otros m elementos iniciales distintos
        // de manera que n+m = numUnos(clave[i]). En tal caso se añaden los posibles resultados obtenidos al operar clave[j] con clave[i]-clave[j].
        for (int j = 1; subclases_usadas < numero_subclases && num_conseguidos < num_a_conseguir; j++){
            
            if ( (clave[j] & clave[i]) == clave[j] && usados[clave[i] - clave[j]] == false){
                subclases_usadas++;
                usados[clave[j]] = usados[clave[i] - clave[j]] = true;
                generarSoluciones(clave[i], clave[j]);
            }
        }
    }
    delete [] usados;

    if (num_conseguidos == num_a_conseguir){
        cout << "Combinación mágica " << num_combinaciones_magicas << ": ";
        for (int i = 1; i <= num_elementos_iniciales; i++){
            cout << clase[clave[i]].begin()->getResultado() << " ";
        }
        cout << endl;
        num_combinaciones_magicas++;
    }
}

// Método que añade las soluciones generadas por las clase clase[j] y clase[i-j], subclases disjuntas de clase[i],
// a esta última.
void Algoritmo::generarSoluciones(int i, int j){
    
    int k = i - j;
    set <Solucion>::iterator m;
    set <Solucion>::iterator n;
    int operacion;

    // Se añaden las soluciones generadas por cada posible par (s,s')
    // con s perteneciente a clase[j] y s' pertenecient a clase[k].
    // Nótese que solo se añade una solución si su valor no lo tiene ya una
    // solución de la clase pues serían equivalentes entre sí.
    for (m = clase[j].begin(); m != clase[j].end(); m++){
        for (n = clase[k].begin(); n != clase[k].end(); n++){
            // Suma:
            operacion = m->getResultado() + n->getResultado();
            clase[i].insert(Solucion(operacion, &(*m), &(*n), 1));
            if (operacion >= limite_inferior && operacion <= limite_superior && ! conseguidos[operacion-limite_inferior]){
                conseguidos[operacion-limite_inferior] = true;
                num_conseguidos++;
            }

            // Producto:
            if (n->getResultado() > 1 && m->getResultado() > 1){
                operacion = m->getResultado() * n->getResultado();
                clase[i].insert(Solucion(operacion, &(*m), &(*n), 2));
                if (operacion >= limite_inferior && operacion <= limite_superior && ! conseguidos[operacion-limite_inferior]){
                    conseguidos[operacion-limite_inferior] = true;
                    num_conseguidos++;
                }
            }

            // Resta padre1-padre2:
            if (m->getResultado() - n->getResultado() > 0){
                operacion = m->getResultado() - n->getResultado();
                clase[i].insert(Solucion(operacion, &(*m), &(*n), 3));
                if (operacion >= limite_inferior && operacion <= limite_superior && ! conseguidos[operacion-limite_inferior]){
                    conseguidos[operacion-limite_inferior] = true;
                    num_conseguidos++;
                }
            } // Resta padre2-padre1:
            else if (m->getResultado() - n->getResultado() < 0){
                operacion = n->getResultado() - m->getResultado();
                clase[i].insert(Solucion(operacion, &(*n), &(*m), 3));
                if (operacion >= limite_inferior && operacion <= limite_superior && ! conseguidos[operacion-limite_inferior]){
                    conseguidos[operacion-limite_inferior] = true;
                    num_conseguidos++;
                }
            }

            // Division:
            if (n->getResultado() > 1 && m->getResultado() > 1){
                if (m->getResultado() % n->getResultado() == 0){
                    operacion = m->getResultado() / n->getResultado();
                    clase[i].insert(Solucion(operacion, &(*m), &(*n), 4));
                    if (operacion >= limite_inferior && operacion <= limite_superior && ! conseguidos[operacion-limite_inferior]){
                        conseguidos[operacion-limite_inferior] = true;
                        num_conseguidos++;
                    }
                }
                else if (n->getResultado() % m->getResultado() == 0){
                    operacion = n->getResultado() / m->getResultado();
                    clase[i].insert(Solucion(operacion, &(*n), &(*m), 4));
                    if (operacion >= limite_inferior && operacion <= limite_superior && ! conseguidos[operacion-limite_inferior]){
                        conseguidos[operacion-limite_inferior] = true;
                        num_conseguidos++;
                    }
                }
            }            
        }
    }
}