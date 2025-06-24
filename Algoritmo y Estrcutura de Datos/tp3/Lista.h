#ifndef LISTA_H
#define LISTA_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};
typedef Nodo* Lista;

bool pertenece(Lista L, int valor);
Lista crearLista();

#endif
