#ifndef LISTA_H
#define LISTA_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};
typedef Nodo* Lista;

Lista crearLista();
Lista insertar(Lista L, int valor);
Lista borrar(Lista L);
void mostrar(Lista L);
bool esListaVacia(Lista L);
int longitud(Lista L);
int primerElemento(Lista L);
bool pertenece(Lista L, int valor);
Lista borrarUltimo(Lista L);
bool iguales(Lista* L1, Lista* L2);

#endif
