#ifndef PILA_H
#define PILA_H

typedef int item;
const item indefinido = -9999;

typedef struct nodo {
    item dato;
    struct nodo* sig;
} nodo;

typedef nodo* Pila;

// Constructoras
Pila pilavacia();
int esPilaVacia(Pila p);
Pila push(Pila p, item x);
Pila pop(Pila p);
item top(Pila p);

// Agregadas
item fondo(Pila p);
Pila popf(Pila p);
Pila popn(Pila p, int n);
int esSimetrica(Pila p);
Pila eliminarMayores(Pila p, item x);

// Utilidades
void imprimirPila(Pila p);
void destruirPila(Pila* p);

#endif
