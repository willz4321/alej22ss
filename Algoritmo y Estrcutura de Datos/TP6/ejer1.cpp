/*En el juego de cartas denominado la Guerra, dos contrincantes, J1 y J2, compiten 
para determinar quién gana. Se mezcla el mazo y se comienza repartiendo todas las 
cartas, alternando, una para J1 y otra para J2, y sin ver su valor, cada jugador guarda 
la siguiente carta recibida debajo de la anterior armando su mazo para comenzar el 
juego. De esta manera la primera carta recibida corresponde a la primera carta que 
debe ser jugada por cada jugador. El juego consiste en que cada jugador, J1 primero 
y luego J2, da vuelta la carta que se encuentra arriba de su mazo, gana el jugador que 
tiene la carta más alta y es el que se queda con las dos cartas. El ganador agrega 
debajo de su mazo de cartas las cartas que ganó en esa partida (primero agrega la 
carta de J1 y luego la de J2). Si al dar vueltas las cartas, éstas coinciden, se produce 
una guerra, en ese caso para desempatar, cada jugador coloca nuevamente una carta 
sobre la mesa. Si éstas coinciden, se debe colocar nuevamente una carta cada uno, 
y así sucesivamente hasta que alguno gane la jugada, si coloca la carta de mayor 
valor o si el otro jugador se queda sin cartas. El ganador de esta jugada se lleva todas 
las cartas que deben ser agregadas a su mazo respetando el orden de tirada, es decir, 
debe agregar al final de sus cartas la primera carta del J1, luego la primera carta del 
J2, y así sucesivamente hasta que no queden cartas en la mesa. La competencia 
termina cuando uno de los dos jugadores se queda con todas las cartas del mazo y 
es ese jugador el que gana la Guerra. */

#include <iostream>
#include <vector>
#include <string>

// Tipo item para las cartas
typedef int item;

// Nodo para la lista enlazada
struct Nodo {
    item dato;
    Nodo* sig;
    Nodo(item d): dato(d), sig(nullptr) {}
};

// ADT Fila con puntero a frente y final
struct Fila {
    Nodo* frente;
    Nodo* final;
    Fila(): frente(nullptr), final(nullptr) {}
};

// Operaciones de la fila
bool esFilaVacia(const Fila& F) {
    return F.frente == nullptr;
}

item frente(const Fila& F) {
    return esFilaVacia(F) ? -9999 : F.frente->dato;
}

void enfila(Fila& F, item x) {
    Nodo* n = new Nodo(x);
    if (esFilaVacia(F)) {
        F.frente = F.final = n;
    } else {
        F.final->sig = n;
        F.final = n;
    }
}

void defila(Fila& F) {
    if (esFilaVacia(F)) return;
    Nodo* aux = F.frente;
    F.frente = aux->sig;
    if (F.frente == nullptr) F.final = nullptr; // Ensure final is null when queue is empty
    delete aux;
    aux = nullptr; // Avoid dangling pointer
}

// Reparte alternando cartas del vector en J1 y J2
void repartirCartas(Fila& J1, Fila& J2, const std::vector<item>& mazo) {
    for (size_t i = 0; i < mazo.size(); ++i) {
        if (i % 2 == 0) enfila(J1, mazo[i]);
        else            enfila(J2, mazo[i]);
    }
}

// Recoge todas las cartas de 'mesa' y las encola al final de 'ganador'
void recogerCartas(Fila& ganador, Fila& mesa) {
    while (!esFilaVacia(mesa)) {
        item c = frente(mesa);
        defila(mesa);
        enfila(ganador, c);
    }
}

// Simula el juego de la Guerra y devuelve la fila ganadora
// (al terminar, la otra quedará vacía)
void guerra(Fila& J1, Fila& J2) {
    while (!esFilaVacia(J1) && !esFilaVacia(J2)) {
        Fila mesa;                // cartas en juego esta ronda
        item c1 = frente(J1); defila(J1);
        item c2 = frente(J2); defila(J2);
        enfila(mesa, c1);
        enfila(mesa, c2);

        // Resolver guerra anidada si c1 == c2
        while (c1 == c2 && !esFilaVacia(J1) && !esFilaVacia(J2)) {
            // una carta “boca abajo” de cada uno
            item x1 = frente(J1); defila(J1); enfila(mesa, x1);
            item x2 = frente(J2); defila(J2); enfila(mesa, x2);
            // luego vueltas para comparar
            c1 = frente(J1); defila(J1); enfila(mesa, c1);
            c2 = frente(J2); defila(J2); enfila(mesa, c2);
        }

        // Determinar quién gana esta batalla (o guerra)
        Fila* pGanador = (c1 > c2 ? &J1 : &J2);
        // El ganador recoge TODAS las cartas de la mesa
        recogerCartas(*pGanador, mesa);
    }
}

int main() {
    // Mazo dado de 24 cartas
    std::vector<item> mazo = {
        7,8,5,9,7,5,9,9,8,7,6,4,
        7,4,5,6,8,4,8,5,9,6,4,6
    };

    // Filas para ambos jugadores
    Fila J1, J2;
    repartirCartas(J1, J2, mazo);

        // Mostrar estado inicial (opcional)
        std::cout << "Mazo J1: ";
        for (Nodo* p = J1.frente; p != nullptr; p = p->sig) {
            std::cout << p->dato << ' ';
        }

        std::cout << "\nMazo J2: ";
        for (Nodo* p = J2.frente; p != nullptr; p = p->sig) {
            std::cout << p->dato << ' ';
        }
        std::cout << "\n\n";


    // Ejecutar la guerra
    guerra(J1, J2);

    // Imprimir ganador
    if (esFilaVacia(J1))
        std::cout << "Gana J2\n";
    else
        std::cout << "Gana J1\n";

    return 0;
}
