#include <iostream>

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo(int v) : valor(v), siguiente(nullptr) {}
};

class Cola {
    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void encolar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!final) frente = final = nuevo;
        else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    int desencolar() {
        if (!frente) throw std::runtime_error("Cola vacía");
        int valor = frente->valor;
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (!frente) final = nullptr;
        delete temp;
        return valor;
    }
};