// 5. Diseñe una función recursiva que reciba un arreglo de n números enteros y retorne 
// verdadero si los elementos están ordenados en forma ascendente, caso contrario retorna 
// falso. 
#include <stdio.h> // Costo O(1) - Inclusión de librería estándar
#include <stdbool.h> // Costo O(1) - Inclusión de librería estándar
#include <string.h> // Costo O(1) - Inclusión de librería estándar

// Función recursiva para verificar si un arreglo está ordenado
bool estaOrdenado(int numeros[], int desde, int hasta) {
    // Caso base: Si desde >= hasta, ya no hay más elementos por comparar
    if (desde >= hasta) { // Costo O(1) - Comparación simple
        return true; // Costo O(1) - Retorno de valor constante
    }

    // Paso recursivo: Comparar el elemento actual con el siguiente
    if (numeros[desde] > numeros[desde + 1]) { // Costo O(1) - Comparación de dos elementos
        return false; // Costo O(1) - Retorno de valor constante
    }

    // Llamada recursiva con el siguiente índice
    return estaOrdenado(numeros, desde + 1, hasta); // Costo O(1) + llamada recursiva
}

// Complejidad de estaOrdenado: O(n), donde n es el tamaño del arreglo. 
// Esto se debe a que la función realiza una comparación y una llamada recursiva por cada elemento del arreglo.

int main(void) {
    int numeros[] = {3, 5, 7, 9, 11, 13, 15}; // Costo O(1) - Declaración de arreglo
    int numeros2[] = {3, 5, 7, 2, 11, 13, 15}; // Costo O(1) - Declaración de arreglo

    int len1 = sizeof(numeros) / sizeof(numeros[0]); // Costo O(1) - Cálculo de longitud del arreglo
    int len2 = sizeof(numeros2) / sizeof(numeros2[0]); // Costo O(1) - Cálculo de longitud del arreglo
    int *valor = numeros; // Costo O(1) - Asignación de puntero
    int *valor2 = numeros2; // Costo O(1) - Asignación de puntero

    // Llamada inicial con índices extremos
    printf("%s\n", estaOrdenado(valor, 0, len1 - 1) ? "El arreglo esta ordenado" : "No esta ordenado"); 
    // Costo O(n) - Llamada a la función recursiva para el primer arreglo

    printf("%s\n", estaOrdenado(valor2, 0, len1 - 1) ? "El arreglo esta ordenado" : "No esta ordenado"); 
    // Costo O(n) - Llamada a la función recursiva para el segundo arreglo

    return 0; // Costo O(1) - Retorno de valor constante
}

// Complejidad total del programa: O(n), donde n es el tamaño del arreglo más grande.
// Esto se debe a que la función `estaOrdenado` domina el costo total del programa, ya que es O(n).
