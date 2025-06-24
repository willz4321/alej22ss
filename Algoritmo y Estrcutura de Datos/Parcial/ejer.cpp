#include <iostream>
#include <cassert>

typedef int item;
const item indefinido = -9999;

// Nodo de la lista circular
struct Nodo {
    item dato;
    Nodo* next;
};

// El ADT MISTERIO queda representado por un puntero al tail
// y un contador de elementos para size() en O(1).
struct Misterio {
    Nodo* tail;
    int   len;
};

// M1: crear MISTERIO vacío
void M1_crear(Misterio &M) {
    M.tail = nullptr;
    M.len  = 0;
}

// M2: insertar un item al final
// Semántica: Push al final de la lista circular
void M2_insertar(Misterio &M, item x) {
    Nodo* n = new Nodo{x, nullptr};
    if (!M.tail) {
        // lista vacía
        n->next = n;
        M.tail  = n;
    } else {
        // enlazar nuevo nodo tras tail
        // El nuevo nodo apunta al primer nodo de la lista (head)
        n->next    = M.tail->next;
        // El nodo tail actual apunta al nuevo nodo
        M.tail->next = n;
        // Actualizamos tail para que sea el nuevo nodo
        M.tail       = n; // Se actualiza el puntero tail para que apunte al nuevo último nodo
    }
    ++M.len;
}

// M3: test de vacío
bool M3_esVacia(const Misterio &M) {
    return M.tail == nullptr;
}

// M4: primer elemento (head)
// devuelve indefinido si está vacía
item M4_primero(const Misterio &M) {
    if (M3_esVacia(M)) return indefinido;
    return M.tail->next->dato;
}

// M5: último elemento (tail)
// devuelve indefinido si está vacía
item M5_ultimo(const Misterio &M) {
    if (M3_esVacia(M)) return indefinido;
    return M.tail->dato;
}

// M6: eliminar primer elemento (pop front)
void M6_popFront(Misterio &M) {
    if (M3_esVacia(M)) return;
    Nodo* head = M.tail->next;
    if (head == M.tail) {
        // solo un nodo
        delete head;
        M.tail = nullptr;
    } else {
        M.tail->next = head->next;
        delete head;
    }
    --M.len;
}

// M7: tamaño
int M7_size(const Misterio &M) {
    return M.len;
}

// --- Función de prueba rápida ---
int main() {
    Misterio M;
    M1_crear(M);
    assert(M3_esVacia(M));
    std::cout << "vacía? " << M3_esVacia(M) << "\n";  // 1

    M2_insertar(M, 5);
    M2_insertar(M, 7);
    M2_insertar(M, 9);
    std::cout << "primero: " << M4_primero(M) << "\n"; // 5
    std::cout << "último:  " << M5_ultimo(M)  << "\n"; // 9
    std::cout << "size:   " << M7_size(M)    << "\n"; // 3

    M6_popFront(M);
    std::cout << "primero: " << M4_primero(M) << "\n"; // 7
    std::cout << "último:  " << M5_ultimo(M)  << "\n"; // 9
    std::cout << "size:   " << M7_size(M)    << "\n"; // 2

    // Liberar toda la estructura
    while (!M3_esVacia(M)) M6_popFront(M);

    return 0;
}
