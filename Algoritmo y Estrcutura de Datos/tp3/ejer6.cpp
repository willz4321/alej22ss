// . Teniendo en cuenta la lista enlazada de números enteros implementada en el TP N° 1:
// a. Diseñe una versión recursiva de la función pertenece (TP Nº 1 – Ejercicio 2.h).
// b. Diseñe una versión recursiva de la función contarComunes (TP Nº 2 – Ejercicio 1.g).
// c. Como usuario de la lista, diseñe una función recursiva que devuelva el dato de mayor 
// valor que contiene la lista.


#include <stdio.h> // Costo O(1) - Inclusión de librería estándar
#include <stdbool.h> // Costo O(1) - Inclusión de librería estándar
#include <string.h> // Costo O(1) - Inclusión de librería estándar
#include "Lista.h" // Costo O(1) - Inclusión de la cabecera de la lista enlazada

Lista crearLista() {
  Lista L;
  L = nullptr;
  return L;
}

bool pertenece(Lista L, int valor) {
  Nodo* actual = L;
    // Caso base: Si la lista está vacía, retornar falso
    if (actual == NULL) {
        return false; // Costo O(1) - Retorno de valor constante
    }
    // Paso recursivo: Comparar el dato del nodo actual con el valor buscado
    if (actual->dato == valor) {
        return true; // Costo O(1) - Retorno de valor constante
    }
  return pertenece(L->siguiente, valor); // Llamada recursiva con el siguiente nodo
}

int main(void) {

    Lista L = crearLista(); // Costo O(1) - Creación de la lista
    // Agregar algunos nodos a la lista (esto es solo un ejemplo, la implementación de agregar nodos no está incluida)
    Nodo* nodo1 = new Nodo{10, nullptr}; // Costo O(1) - Creación de un nodo
    Nodo* nodo2 = new Nodo{20, nullptr}; // Costo O(1) - Creación de un nodo
    Nodo* nodo3 = new Nodo{30, nullptr}; // Costo O(1) - Creación de un nodo
    L = nodo1; // Costo O(1) - Asignación del primer nodo
    nodo1->siguiente = nodo2; // Costo O(1) - Enlazar el primer nodo al segundo
    nodo2->siguiente = nodo3; // Costo O(1) - Enlazar el segundo nodo al tercero    

    // Definir el valor a buscar
    int valorBuscado = 20;

    // Llamada a la función pertenece
    if (pertenece(L, valorBuscado)) {
        printf("El valor %d pertenece a la lista.\n", valorBuscado);
    } else {
        printf("El valor %d no pertenece a la lista.\n", valorBuscado);
    }

    return 0; // Costo O(1) - Retorno de valor constante
}