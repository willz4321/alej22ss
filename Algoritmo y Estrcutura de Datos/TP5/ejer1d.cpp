#include "Pila.h"
#include<iostream>

// Costo: O(1)
Pila pilavacia() {
    return nullptr; // Retorna una pila vacía
}

// Costo: O(1)
Pila push(Pila p, item x) {
    Pila nuevo = new nodo; // Crea un nuevo nodo (O(1))
    nuevo->dato = x;       // Asigna el valor al nodo (O(1))
    nuevo->sig = p;        // El siguiente del nuevo nodo es la pila actual (O(1))
    return nuevo;          // Retorna la nueva pila con el elemento agregado (O(1))
}

// Costo: O(n), donde n es el número de elementos en la pila
void imprimirPila(Pila p) {
    if (esPilaVacia(p)) { // Verifica si la pila está vacía (O(1))
        std::cout << "Pila vacía" << std::endl; // Imprime mensaje (O(1))
        return; // Retorna (O(1))
    }
    std::cout << "Pila: "; // Imprime mensaje (O(1))
    while (p != nullptr) { // Itera sobre los elementos de la pila (O(n))
        std::cout << p->dato << " "; // Imprime el dato del nodo actual (O(1) por iteración)
        p = p->sig; // Avanza al siguiente nodo (O(1) por iteración)
    }
    std::cout << std::endl; // Imprime un salto de línea (O(1))
}

// Costo: O(1)
item top(Pila p) {
    if (esPilaVacia(p)) { // Verifica si la pila está vacía (O(1))
        std::cerr << "Error: Pila vacía, no se puede obtener el elemento en la cima." << std::endl; // Imprime mensaje de error (O(1))
        return indefinido; // Retorna un valor indefinido (O(1))
    }
    return p->dato; // Retorna el dato del nodo en la cima de la pila (O(1))
}

// Costo: O(1)
int esPilaVacia(Pila p) {
    return p == nullptr; // Retorna 1 si la pila está vacía, 0 en caso contrario (O(1))
}

// Costo: O(1)
Pila pop(Pila p) {
    if (esPilaVacia(p)) { // Verifica si la pila está vacía (O(1))
        std::cerr << "Error: Pila vacía, no se puede eliminar el elemento en la cima." << std::endl; // Imprime mensaje de error (O(1))
        return p; // Retorna la pila sin cambios (O(1))
    }
    Pila temp = p; // Guarda la pila original (O(1))
    p = p->sig; // Avanza al siguiente nodo (O(1))
    delete temp; // Libera la memoria del nodo eliminado (O(1))
    return p; // Retorna la pila actualizada (O(1))
}

// Costo: O(n), donde n es el número de elementos en la pila
item fondo(Pila p) {
    if (esPilaVacia(p)) { // Verifica si la pila está vacía (O(1))
        std::cerr << "Error: Pila vacía, no se puede obtener el elemento en el fondo." << std::endl; // Imprime mensaje de error (O(1))
        return indefinido; // Retorna un valor indefinido (O(1))
    }
    while (p->sig != nullptr) { // Itera hasta el último nodo (O(n))
        p = p->sig; // Avanza al siguiente nodo (O(1) por iteración)
    }
    return p->dato; // Retorna el dato del nodo en el fondo de la pila (O(1))
}

// Costo: O(n), donde n es el número de elementos en la pila
void destruirPila(Pila* p) {
    while (!esPilaVacia(*p)) { // Itera sobre los elementos de la pila (O(n))
        *p = pop(*p); // Elimina los nodos uno por uno (O(1) por iteración)
    }
    delete p; // Libera la memoria del puntero de pila (O(1))
}

int main() {
    Pila p = pilavacia(); // Crea una pila vacía (O(1))
    p = push(p, 10); // Inserta un elemento (O(1))
    p = push(p, 20); // Inserta un elemento (O(1))
    p = push(p, 30); // Inserta un elemento (O(1))
    
    std::cout << "Pila después de insertar elementos: "; // Imprime mensaje (O(1))
    imprimirPila(p); // Imprime la pila (O(n))
    
    std::cout << "Elemento en la cima: " << top(p) << std::endl; // Obtiene el elemento en la cima (O(1))
    
    p = pop(p); // Elimina el elemento en la cima (O(1))
    std::cout << "Pila después de eliminar la cima: "; // Imprime mensaje (O(1))
    imprimirPila(p); // Imprime la pila (O(n))
    
    std::cout << "Elemento en el fondo: " << fondo(p) << std::endl; // Obtiene el elemento en el fondo (O(n))
    
    destruirPila(&p); // Destruye la pila (O(n))
    
    return 0; // Retorna (O(1))
}