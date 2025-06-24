#include "Lista.h"
#include<stdio.h>

Lista crearLista() {
  Lista L;
  L = nullptr;
  return L;
}

void mostrar(Lista L) {
  if (esListaVacia(L)) {
    printf("Lista Vacia\n");
  } else {
    Nodo* actual = L;
    while (actual != nullptr) {
      printf("%d ", actual->dato);
      actual = actual->siguiente;
    }
    printf("\n");
  }
}
bool esListaVacia(Lista L) {
  return L == nullptr;
}
int longitud(Lista L) {
  int count = 0;
  Nodo* actual = L;
  while (actual != nullptr) {
    count++;
    actual = actual->siguiente;
  }
  return count;
}
int primerElemento(Lista L) {
  if (esListaVacia(L)) {
    return -99999; // Valor por defecto si la lista está vacía
  }
  return L->dato;
}
bool pertenece(Lista L, int valor) {
  Nodo* actual = L;
  while (actual != nullptr) {
    if (actual->dato == valor) {
      return true;
    }
    actual = actual->siguiente;
  }
  return false;
}
Lista insertar(Lista L, int valor) {
  Nodo* nuevoNodo = new Nodo;
  nuevoNodo->dato = valor;
  nuevoNodo->siguiente = nullptr;

  if (esListaVacia(L)) {
    return nuevoNodo; // Si la lista está vacía, el nuevo nodo es el primer elemento
  }

  Nodo* actual = L;
  while (actual->siguiente != nullptr) {
    actual = actual->siguiente; // Avanzar al final de la lista
  }
  actual->siguiente = nuevoNodo; // Insertar el nuevo nodo al final
  return L;
}
Lista borrar(Lista L) {
  if (esListaVacia(L)) {
    return L; // No hay nada que borrar
  }

  Nodo* nodoAEliminar = L;
  L = L->siguiente; // Mover la cabeza de la lista al siguiente nodo
  delete nodoAEliminar; // Liberar memoria del nodo eliminado
  return L;
}
Lista borrarUltimo(Lista L) {
  if (esListaVacia(L)) {
    return L; // No hay nada que borrar
  }

  if (L->siguiente == nullptr) {
    delete L; // Si solo hay un nodo, lo eliminamos y retornamos lista vacía
    return nullptr;
  }

  Nodo* actual = L;
  while (actual->siguiente->siguiente != nullptr) {
    actual = actual->siguiente; // Avanzar hasta el penúltimo nodo
  }
  
  delete actual->siguiente; // Eliminar el último nodo
  actual->siguiente = nullptr; // Hacer que el penúltimo nodo apunte a nullptr
  return L;
}
bool iguales(Lista* L1, Lista* L2) {
  Nodo* actual1 = *L1;
  Nodo* actual2 = *L2;

  while (actual1 != nullptr && actual2 != nullptr) {
    if (actual1->dato != actual2->dato) {
      return false; // Los datos no son iguales
    }
    actual1 = actual1->siguiente;
    actual2 = actual2->siguiente;
  }

  return (actual1 == nullptr && actual2 == nullptr); // Ambas listas deben ser del mismo tamaño
}