#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Función recursiva: verifica si palabra[desde…hasta] es un palíndromo
bool esPalindromo(char palabra[], int desde, int hasta) {
    // Caso base:
    // Si desde >= hasta, ya no hay más caracteres por comparar
    // Retornar verdadero
    if (desde >= hasta) {
        return true; // Costo O(1)
    }

    // Paso recursivo:
    // 1) Comparar palabra[desde] con palabra[hasta]
    //    Si son iguales, continuar con los caracteres internos
    //    Si no, retornar falso
    if (palabra[desde] != palabra[hasta]) {
        return false; // Costo O(1)
    }
    // 2) Llamada recursiva con los índices internos
    return esPalindromo(palabra, desde + 1, hasta - 1); // Costo O(1) + llamada recursiva
    // Complejidad total de esPalindromo: O(n), donde n es la longitud de la subcadena palabra[desde…hasta]
    // Nota: La complejidad es lineal porque cada llamada recursiva reduce el problema en 2 caracteres
    // y se realizan n/2 comparaciones en total.
    // Por lo tanto, la complejidad total es O(n).
    // Nota: La complejidad es lineal porque cada llamada recursiva reduce el problema en 2 caracteres
    // y se realizan n/2 comparaciones en total.
    // Por lo tanto, la complejidad total es O(n).
    // Nota: La complejidad es lineal porque cada llamada recursiva reduce el problema en 2 caracteres
    // y se realizan n/2 comparaciones en total.
    // Por lo tanto, la complejidad total es O(n).
    // Nota: La complejidad es lineal porque cada llamada recursiva reduce el problema en 2 caracteres
    // y se realizan n/2 comparaciones en total.
    // Por lo tanto, la complejidad total es O(n).
    // Nota: La complejidad es lineal porque cada llamada recursiva reduce el problema en 2 caracteres
    // y se realizan n/2 comparaciones en total.
    // Por lo tanto, la complejidad total es O(n).      
}

int main(void) {
    char palabra1[] = "reconocer";
    char palabra2[] = "algoritmo";

    int len1 = strlen(palabra1);
    int len2 = strlen(palabra2);

    // Llamada inicial con índices extremos
    printf("%s → %s\n", palabra1, esPalindromo(palabra1, 0, len1 - 1) ? "Sí" : "No");
    printf("%s → %s\n", palabra2, esPalindromo(palabra2, 0, len2 - 1) ? "Sí" : "No");

    return 0;
}

// Costo total
// Cálculo de la longitud (strlen): Se ejecuta una vez por palabra, con costo O(n).
// Llamadas a esPalindromo: Cada palabra tiene un costo O(n).
// Operaciones constantes: Declaraciones de variables y comparaciones tienen costo O(1).
// Por lo tanto, el costo total del programa es O(n) para cada palabra procesada.
// Si se procesan m palabras, el costo sería O(m * n),
// donde n es la longitud promedio de las palabras. En este caso, 
// como solo hay dos palabras, el costo sigue siendo lineal respecto a la longitud de las palabras.