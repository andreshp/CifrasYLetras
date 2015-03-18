# Cifras

## Definición del problema

Dado un conjunto *C* de 6 enteros sacados aleatoriamente con remplazamiento del conjunto:

*A* = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100}

se plantea conseguir otro entero aleatorio de 3 cifras usando para ello solo las operaciones de suma, resta, producto y división entera, teniendo en cuenta que solo se puede usar cada número (de los 6) como mucho una vez y que es posible no utilizar los 6 para conseguir el número de 3 cifras. Solo se permite utilizar la resta si el resultado es mayor que 0. Análogamente, solo se permite el uso de la división entera en el caso de ser esta exacta (su resto
es 0).

## Solución

La solución propuesta se basa en definir una relación de equivalencia y construir dinámicamente los representantes necesarios de cada clase de equivalencia. Un desarrollo teórico de la misma se encuentra en el archivo *Cifras-AndresHerreraPoyatos.pdf*.

## Uso del programa

Se proporcionan dos implementaciones diferentes para el problema, una que utiliza solo vectores y otra que usa la clase *set* de la STL para eliminación de elementos repetidos. La interfaz de ambas implementaciones es equivalente. Ambas constan de una carpeta llamada ProblemaCifras* con la correspondiente implementación. Dicha carpeta consta a su vez de las subcarpetas:

- bin : Aquí se guarda el ejecutable tras la compilación.
- doc : Aquí se guarda la documentación generada por Doxygen tras hacer make documentacion
- include : Aquí se encuentran los archivos .h
- src : Aquí se encuentran los archivos .cpp

Y los archivos:

- makefile : Compila el programa.
- parametros.par : Datos que se pasan como argumento al programa.

El archivo parametros.par tiene el siguiente contenido:

~~~
*************** Problemas De las Cifras ****************
NumeroDatos=6
Datos= 2 6 7 9 50 75
ValorObjetivo= 234
~~~

NumeroDatos es el cardinal del conjunto *C* y Datos los elementos del mismo. ValorObjetivo responde al valor objetivo del problema a resolver. La llamada al programa se realiza de la siguiente forma:

~~~bash
./bin/problemaCifras parametros.par
~~~

El resultado de la ejecución se muestra en la terminal. Por ejemplo, este sería el resultado obtenido para los datos anteriores usando solo vectores:

~~~
Tiempo de ejecución: 0.000574 segundos
Se ha conseguido el valor objetivo.
Operaciones realizadas:
2 * (75 + (6 * 7))
~~~

## Combinaciones Mágicas

Se resuelve también este problema particular que se deduce del anterior:

Existen combinaciones de 6 números del conjunto *A* dado en la introducción con las que puede obtenerse cualquier número de 3 cifras. Un ejemplo es el siguiente conjunto:

*C* = {2, 6, 7, 9, 50, 75}

A estas combinaciones se las denominan **Combinaciones Mágicas**. Utilizo mi solución al Problema de las Cifras para calcular todas las Combinaciones Mágicas posibles. Para generalizar el problema, propongo un algoritmo que encuentre aquellas combinaciones (con repetición) de números de un conjunto dado tales que generen todos los valores entre un intervalo acotado de números enteros positivos dado por su máximo y mínimo. El programa se adjunta en la carpeta **CombinacionesMagicas**, que sigue la misma estructura de directorios que los dos programas anteriores. Para su uso basta compilarlo y
llamarlo de la siguiente forma:

~~~bash
./bin/combinacionesMagicas parametros.par
~~~

En este caso el archivo parámetros responde a:

~~~
*************** Problemas De las Cifras, Combinaciones Mágicas ****************
NumeroDatos= 14                             // Número de datos de donde obtener combinaciones
Datos= 1 2 3 4 5 6 7 8 9 10 25 50 75 100    // Datos de donde obtener las combinaciones
LongitudCombinacion= 6                      // Longitud de las combinaciones a obtener
LimiteInferior= 100                         // Mímimo del intervalo
LimiteSuperior= 999                         // Máximo del intervalo
~~~

Para los datos anteriores obtengo **1248 Combinaciones Magicas** en 655.395 segundos de cómputo. La ejecución se ha realizado en un ordenador portátil con 8 GB de RAM y procesador Intel i5 a 2,5 GH.

La explicación de la solución se incluye en el archivo *Cifras-AndresHerreraPoyatos .pdf*.
