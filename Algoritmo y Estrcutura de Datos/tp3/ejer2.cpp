/**
 * Este programa contiene un procedimiento recursivo que toma un número natural 
 * (un número entero no negativo, es decir, 0, 1, 2, 3, ...) y escribe sus dígitos 
 * en orden inverso, separados por un espacio. Por ejemplo, si el número de entrada 
 * es 1825, la salida será: "5 2 8 1".
 *
 * La función `imprimirInvertido` utiliza recursión para procesar cada dígito del 
 * número, comenzando por el último (unidad) y avanzando hacia el primero (más significativo).
 */
// Diseñe un procedimiento recursivo que, dado un número natural, escriba sus dígitos en 
// orden inverso y separados por un espacio. Ej. N = 1825 → Salida por pantalla: 5 2 8 1

#include <stdio.h>

/**
 * @brief Imprime los dígitos de un número entero no negativo en orden inverso.
 * 
 * Esta función utiliza un enfoque recursivo para imprimir los dígitos de un número
 * en orden inverso. Si el número tiene un solo dígito, lo imprime directamente.
 * En caso contrario, imprime el último dígito y luego llama recursivamente a sí
 * misma con el número sin el último dígito.
 * 
 * @param n Número entero no negativo a procesar.
 * 
 * @note Complejidad temporal: O(d), donde d es la cantidad de dígitos en el número n.
 *       Esto se debe a que la función realiza una llamada recursiva por cada dígito.
 */
void imprimirInvertido(unsigned int n) {
    if (n < 10) { // O(n) - Caso base
        // Caso base: un solo dígito
        printf("%u ", n); // O(1)
    } else {
        // Paso recursivo: imprime el último dígito...
        printf("%u ", n % 10); // O(1)
        // ...y luego procesa el resto
        imprimirInvertido(n / 10); // O(n)
    }
}

int main(void) {
    unsigned int N = 1825;
    imprimirInvertido(N);
    return 0;
}


// La función **imprimirInvertido** tiene una complejidad de tiempo de **O(log(n))**, no **O(n)**, porque el número de llamadas recursivas depende de la cantidad de dígitos en el número de entrada **n**. He aquí por qué:

// ### Análisis Paso a Paso:

// **Comportamiento recursivo:**

// - En cada llamada recursiva, la función divide el número **n** entre 10 (es decir, **n / 10**).  
//   Esta operación elimina efectivamente el último dígito del número. Por ejemplo:  
//   - Si **n = 1825**, la primera llamada procesa **1825 % 10** (el último dígito) y luego llama a **imprimirInvertido(182)**.  
//   - La siguiente llamada procesa **182 % 10** y llama a **imprimirInvertido(18)**, y así sucesivamente.

// **Número de llamadas recursivas:**

// - La recursión se detiene cuando **n < 10**, es decir, cuando queda un solo dígito.  
// - La cantidad de veces que se puede dividir un número **n** entre 10 antes de que se convierta en un dígito es proporcional al número de dígitos en **n**.  
// - El número de dígitos de un número **n** es aproximadamente **log10(n)**. Por ejemplo:  
//   - **1825** tiene 4 dígitos porque **log10(1825) ≈ 3.26**.  
//   - **100000** tiene 6 dígitos porque **log10(100000) = 5**.

// **Complejidad temporal:**

// - Cada llamada recursiva realiza una cantidad constante de trabajo: calcular **n % 10** e imprimirlo (operaciones de **O(1)**).  
// - El total de llamadas recursivas es proporcional a la cantidad de dígitos en **n**, lo que equivale a **O(log10(n))**.  
// - Por lo tanto, la complejidad temporal global es **O(log(n))**.

// **¿Por qué no O(n)?**

// La confusión puede surgir al pensar que la función procesa cada “unidad” del número. Sin embargo, la función no itera directamente sobre el valor de **n**, sino que procesa los dígitos de **n**, y la cantidad de dígitos crece de forma logarítmica con el tamaño de **n**.

// **Resumen:**

// La complejidad temporal de **imprimirInvertido** es **O(log(n))** porque el número de llamadas recursivas es proporcional a la cantidad de dígitos en **n**, la cual se determina por el logaritmo de **n** en base 10.