#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

class Pila {
    Nodo* tope;

public:
    Pila() : tope(nullptr) {}

    void push(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    int pop() {
        if (!tope) throw std::runtime_error("Pila vacía");
        int valor = tope->valor;
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
        return valor;
    }
};