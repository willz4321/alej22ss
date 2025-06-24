#include <cstdio>

// Versión iterativa: suma las cifras de n
unsigned int sumaIterativa(unsigned int n) {
    unsigned int suma = 0; // Costo O(1)
    // Mientras n > 0:
    while (n > 0) { // Costo O(d), donde d es el número de dígitos de n
        suma += n % 10; // Costo O(1) por cada iteración
        n /= 10; // Costo O(1) por cada iteración
    }
    return suma; // Costo O(1)
}

// Complejidad total de sumaIterativa: O(d), donde d es el número de dígitos de n

// Versión recursiva: suma las cifras de n
unsigned int sumaRecursiva(unsigned int n) {
    if (n < 10) { // Costo O(1)
        return n; // Costo O(1)
    } else {
        return n % 10 + sumaRecursiva(n / 10); // Costo O(1) + llamada recursiva
    }
}

// Complejidad total de sumaRecursiva: O(d), donde d es el número de dígitos de n

int main(void) {
    unsigned int N1 = 1823; // Costo O(1)
    unsigned int N2 = 261; // Costo O(1)

    // Prueba iterativa
    printf("Iterativa %u → %u\n", N1, sumaIterativa(N1)); // Costo O(d1), donde d1 es el número de dígitos de N1
    printf("Iterativa %u → %u\n", N2, sumaIterativa(N2)); // Costo O(d2), donde d2 es el número de dígitos de N2

    // Prueba recursiva
    printf("Recursiva %u → %u\n", N1, sumaRecursiva(N1)); // Costo O(d1)
    printf("Recursiva %u → %u\n", N2, sumaRecursiva(N2)); // Costo O(d2)

    return 0; // Costo O(1)
}

// Complejidad total del programa: O(d1 + d2), donde d1 y d2 son los números de dígitos de N1 y N2 respectivamente
