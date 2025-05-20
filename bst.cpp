#include <iostream>

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}
};

class BST {
    Nodo* raiz;

    void insertar(Nodo*& nodo, int valor) {
        if (!nodo) nodo = new Nodo(valor);
        else if (valor < nodo->valor) insertar(nodo->izq, valor);
        else insertar(nodo->der, valor);
    }

    void inorden(Nodo* nodo) {
        if (!nodo) return;
        inorden(nodo->izq);
        std::cout << nodo->valor << " ";
        inorden(nodo->der);
    }

public:
    BST() : raiz(nullptr) {}

    void insertar(int valor) {
        insertar(raiz, valor);
    }

    void mostrar() {
        inorden(raiz);
        std::cout << std::endl;
    }
};