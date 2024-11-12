# Proyecto: Simulador de Torneos de Tenis

Simulador de tour de torneos de Tenis con ranking ATP y rating UTR con los 128 jugadores mejor rankeados en ATP de Semestre 2024

## Descripción del avance 1

### Ceación de clases y primer main

Creación de la estuctura de los objetos de clase *Tournament, Player y ATP.* En la clase *ATP* se incluye el método *sortPlayers(string)* el cual usa un insertion sort para ordenar el ranking de forma descendente ya sea por puntos ATP o UTR después de cada torneo.

Implementación de un *main* básico para poder visualizar los rankings, información de un jugador seleccionado por su nombre y adición de jugadores personalizados.

#### Algoritmo de Ordenamiento

Se escogió el algoritmo de *insertion sort* ya que el vector a ordenar casi siempre estará ordenado o muy cerca de ordenado, estando los valores desordenados cercanos a su posición esperada, por lo tanto teniendo menos iteraciones a lo largo del vector.

##### Análisis de Complejidad (Tiempo)

* Mejor caso: O(n)
* Caso Promedio: O(n^2)
* Peor caso: O(n^2)

##### Análisis de Complejidad (Espacio)

* Mejor caso: O(1)
* Caso Promedio: O(1)
* Peor Caso: O(1)

## Descripción del avance 2

Creación de la lógica para jugar torneos con un formato de copa.

¿Cómo se podrán almacenar los partidos a jugar para el desarrollo de cada una de las rondas del torneo?

#### Queue (Fila)

Se escogió la estructura de queue (fila) para almacenar los partidos a jugar como un atributo de la clase *Tournament.*

Ya que los partidos se crean en el orden en el cuál deben de ser jugados, el uso de una fila para esta implementación es la indicada al utilizar los partidos al inicio (front()) de la fila, eliminarlos (pop()) después de que se hayan jugado y añadir un partido de la siguiente ronda con los ganadores al final (push()), teniendo así una organización de los partidos dividida por rondas en una misma estructura.

##### Análisis de Complejidad (Tiempo) para push(), pop(), front(), back()


* Mejor caso: O(1)
* Caso Promedio: O(1)
* Peor caso: O(1)

##### Análisis de Complejidad (Espacio) para push(), pop(), front(), back()

* Mejor caso: O(1)
* Caso Promedio: O(1)
* Peor Caso: O(1)

#### Vector

Se escogió la estructura de vector para almacenar los jugadores.

##### Análisis de Complejidad (Tiempo) para push_back(), operador[]

* Mejor caso: O(1)
* Caso Promedio: O(1)
* Peor caso: O(1)

##### Análisis de Complejidad (Espacio) para push_back(), operador[]

* Mejor caso: O(1)
* Caso Promedio: O(1)
* Peor Caso: O(1)

### Cambios sobre el primer avance

1. Actualización de la clase Tournament y el main para terminar la implementación de simular torneos.

## Descripción del avance 3

Escribe aquí la descripción de lo que contiene este avance.

### Cambios sobre el segundo avance

1. Escribe la lista de cambios realizados sobre el planteamiento pasado: Argumenta la razón por la que decidiste el cambio. Estos argumentos puedes retomarlos más adelante en tu argumentación de competencias.
2. Cambio 2: Razón del cambio
3. Cambio 3: Razón del cambio
4. etc...: etc...

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance`

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:

`./primer_avance`

## Descripción de las entradas del avance de proyecto

**Archivo *jugadores.csv***

Archivo para cargar la información de los jugadores iniciales

Contiene:

* Nombre (string)
* UTR (float)
* ATP (int)
* Edad (int)
  **Ejemplo:**
  NOMBRE, UTR, ATP, EDAD
  Jannik Sinner, 16.07, 11180, 23
  Alexander Zverev, 15.85, 7075, 27

## Descripción de las salidas del avance de proyecto

Los resultados de la ejecución del programa son:

* Datos de los rankings ATP y UTR
* Datos de jugadores
* Información sobre el avance de los torneos
* Archivo archivo_a_escribir.txt
  * Escribe en el archivo un resumen de la información de los jugadores cargados en el programa

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En el documento se incluye la explicación de la selección del algoritmo utilizado y el análisis de complejidad de tiempo y espacio para el mejor caso, caso promedio y peor caso, siendo este un análisis de todos los componentes con todos los casos base para tener un buen análisis de complejidad de nuestro algoritmo.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En el documento se incluye la el análisis de complejidad para cada una de las funciones de la fila y  vector usadas en el programa. Este análisis es un análisis de complejidad de tiempo y espacio para el mejor caso, caso promedio y peor caso, siendo este un análisis completo de todos los componentes y funciones de las estructuras de datos seleccionadas.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Dentro del código, arriba de cada función se añadió un comentario que incluye un análisis de complejidad completo y correcto de su complejidad.

Además, en la función del main del programa está el comentario con la complejidad final completa del programa.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

En el documento se desarrolló la explicación de la selección del algoritmo de ordenamiento utilizando como justificación la naturaleza de los datos a ordenar y de la lógica del algoritmo.

En el insertion sort implementado en el método de *sortPlayers()* en la clase  *ATP* , los elementos se comparan con sus localidades adyacentes, por lo tanto si tenemos un dataset con datos casi ordenados y en donde los datos no ordenados esten cerca entre sí será un algoritmo eficiente.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

En el documento se presenta la problemática y el fundamento del uso de la estructura de datos utilizada para la solución de este. Al solo ocupar consultar y eliminar el primer elemento e insertar al fondo de la estructura de datos, la fila es la indicada para hacer estas operaciones de manera eficiente, teniemdo también una abstracción que facilita desarrollar esta implementación.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructras correctos.

Al utilizar front() en la fila para consultar y mandar como parámetro los jugadores a otro método para así simular el partido, obteniendo un ganador, se consulta de manera eficiente la información necesaria para avanzar en el torneo.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Se utiliza un archivo de tipo .csv (jugadores.csv) descrito en el apartado de entradas en este mismo documento para cargar 128 objetos de clase *Jugador* a un vector con el fin de poder utilizar el programa con datos predeterminados.lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta

Dentro del programa se utiliza la función *escribirArchivo* para añadir  correctamente información de los jugadores con un salto de línea al archivo *archivo_a_escribir.txt.*
