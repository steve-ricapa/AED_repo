#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v = -1) : valor(v), siguiente(this) {}
};

class ListaCircularSentinel {
    Nodo* sentinel;

public:
    ListaCircularSentinel() {
        sentinel = new Nodo();
    }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = sentinel->siguiente;
        sentinel->siguiente = nuevo;
    }

    void mostrar() {
        Nodo* actual = sentinel->siguiente;
        while (actual != sentinel) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};