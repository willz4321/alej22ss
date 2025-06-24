//  Dado un vector de números enteros que está desordenado, diseñe una función (mediante 
// un algoritmo que siga el esquema de Divide y Vencerás) que devuelva el valor acumulado 
// de los elementos del vector teniendo en cuenta que los números pares se suman y los 
// números impares se restan.

#include <stdio.h> // Costo O(1) - Inclusión de librería estándar
#include <stdbool.h> // Costo O(1) - Inclusión de librería estándar
#include <string.h> // Costo O(1) - Inclusión de librería estándar

int sumaParesRestaImpares(int* vector, int inicio, int fin) {
    // Caso base: Si el rango es inválido, retornar 0
    if (inicio > fin) {
        return 0; // Costo O(1) - Retorno de valor constante
    }
    
    // Caso base: Si hay un solo elemento
    if (inicio == fin) {
        return (vector[inicio] % 2 == 0) ? vector[inicio] : -vector[inicio]; // Costo O(1)
    }
    
    // Dividir el vector en dos mitades
    int medio = (inicio + fin) / 2;
    
    // Llamadas recursivas para las dos mitades
    int sumaIzquierda = sumaParesRestaImpares(vector, inicio, medio);
    int sumaDerecha = sumaParesRestaImpares(vector, medio + 1, fin);
    
    // Combinar los resultados
    return sumaIzquierda + sumaDerecha; // Costo O(1)
}
int main(void) {
    // Definir un vector de números enteros desordenados
    int vector[] = {3, 5, 2, 8, 7, 4, 6, 1};
    int size = sizeof(vector) / sizeof(vector[0]); // Costo O(1) - Cálculo del tamaño del vector

    // Llamada a la función para obtener el valor acumulado
    int resultado = sumaParesRestaImpares(vector, 0, size - 1);

    // Imprimir el resultado
    printf("El valor acumulado es: %d\n", resultado); // Costo O(1)

    return 0; // Costo O(1) - Retorno de valor constante
}

/*
Costo final del algoritmo:

1. Análisis del algoritmo `sumaParesRestaImpares`:
   - El algoritmo sigue el esquema de Divide y Vencerás.
   - En cada llamada recursiva, el vector se divide en dos mitades.
   - El costo de dividir el vector y combinar los resultados es O(1).
   - La relación de recurrencia es:
     T(n) = 2 * T(n/2) + O(1)

2. Resolviendo la relación de recurrencia:
   - Usando el método maestro:
     a = 2, b = 2, f(n) = O(1)
     Comparando log_b(a) = log_2(2) = 1 con el crecimiento de f(n):
     - f(n) = O(n^c) con c = 0 (ya que O(1) es constante).
     - Como log_b(a) > c, el caso aplica al caso 1 del teorema maestro.
     - Por lo tanto, T(n) pertenece a O(n).

3. Conclusión:
   - El costo final del algoritmo `sumaParesRestaImpares` es O(n), donde n es el tamaño del vector.
   - Esto se debe a que el algoritmo realiza un recorrido completo del vector dividiéndolo recursivamente y combinando los resultados en tiempo constante.
*/