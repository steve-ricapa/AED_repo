#include <iostream>
#include <algorithm>

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    int altura;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr), altura(1) {}
};

class AVL {
    Nodo* raiz;

    int altura(Nodo* n) {
        return n ? n->altura : 0;
    }

    int balance(Nodo* n) {
        return n ? altura(n->izq) - altura(n->der) : 0;
    }

    void actualizarAltura(Nodo* n) {
        n->altura = 1 + std::max(altura(n->izq), altura(n->der));
    }

    Nodo* rotarDerecha(Nodo* y) {
        Nodo* x = y->izq;
        y->izq = x->der;
        x->der = y;
        actualizarAltura(y);
        actualizarAltura(x);
        return x;
    }

    Nodo* rotarIzquierda(Nodo* x) {
        Nodo* y = x->der;
        x->der = y->izq;
        y->izq = x;
        actualizarAltura(x);
        actualizarAltura(y);
        return y;
    }

    Nodo* insertar(Nodo* nodo, int valor) {
        if (!nodo) return new Nodo(valor);
        if (valor < nodo->valor) nodo->izq = insertar(nodo->izq, valor);
        else nodo->der = insertar(nodo->der, valor);

        actualizarAltura(nodo);

        int b = balance(nodo);

        if (b > 1 && valor < nodo->izq->valor)
            return rotarDerecha(nodo);
        if (b < -1 && valor > nodo->der->valor)
            return rotarIzquierda(nodo);
        if (b > 1 && valor > nodo->izq->valor) {
            nodo->izq = rotarIzquierda(nodo->izq);
            return rotarDerecha(nodo);
        }
        if (b < -1 && valor < nodo->der->valor) {
            nodo->der = rotarDerecha(nodo->der);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    void inorden(Nodo* nodo) {
        if (!nodo) return;
        inorden(nodo->izq);
        std::cout << nodo->valor << " ";
        inorden(nodo->der);
    }

public:
    AVL() : raiz(nullptr) {}

    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }

    void mostrar() {
        inorden(raiz);
        std::cout << std::endl;
    }
};