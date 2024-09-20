# Proyecto: Simulador de Torneos de Tenis

Simulador de tour de torneos de Tenis con ranking ATP y rating UTR con los 100 jugadores mejor rankeados en ATP de Septiembre 2024

## Creación de clases y primer main

Creación de la estuctura de los objetos de clase *Tournament, Player y ATP.* En la clase *ATP* se incluye el método *sortPlayers(string)* el cual usa un insertion sort para ordenar el ranking de forma descendente ya sea por puntos ATP o UTR después de cada torneo.

Implementación de un *main* básico para poder visualizar los rankings, información de un jugador seleccionado por su nombre y adición de jugadores personalizados.

### Algoritmo de Ordenamiento

Se escogió el algoritmo de *insertion sort* ya que el vector a ordenar casi siempre estará ordenado o muy cerca de ordenado, estando los valores desordenados cercanos a su posición esperada, por lo tanto teniendo menos iteraciones a lo largo del vector.

#### Análisis de Complejidad (Tiempo)

* Mejor caso: O(n)
* Caso Promedio: O(n^2)
* Peor caso: O(n^2)

#### Análisis de Complejidad (Espacio)

* Mejor caso: O(1)
* Caso Promedio: O(1)
* Peor Caso: O(1)


## Instrucciones para compilar el avance de proyecto

Tener el archivo *jugadores.csv* en la misma carpeta que el *main.cpp.*

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

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

En el documento se incluye la explicación de la selección del algoritmo utilizado y el análisis de complejidad de tiempo y espacio para el mejor caso, caso promedio y peor caso, siendo este un análisis de todos los componentes con todos los casos base para tener un buen análisis de complejidad de nuestro algoritmo.


### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

En el documento se desarrolló la explicación de la selección del algoritmo de ordenamiento utilizando como justificación la naturaleza de los datos a ordenar y de la lógica del algoritmo.

En el insertion sort implementado en el método de *sortPlayers()* en la clase *ATP*, los elementos se comparan con sus localidades adyacentes, por lo tanto si tenemos un dataset con datos casi ordenados y en donde los datos no ordenados esten cerca entre sí será un algoritmo eficiente.
