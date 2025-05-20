#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

class ListaEnlazada {
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void mostrar() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};