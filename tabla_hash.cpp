#include <iostream>

const int TABLE_SIZE = 10;

struct Nodo {
    int clave;
    Nodo* siguiente;
    Nodo(int c) : clave(c), siguiente(nullptr) {}
};

class TablaHash {
    Nodo* tabla[TABLE_SIZE];

    int hash(int clave) {
        return clave % TABLE_SIZE;
    }

public:
    TablaHash() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            tabla[i] = nullptr;
    }

    void insertar(int clave) {
        int idx = hash(clave);
        Nodo* nuevo = new Nodo(clave);
        nuevo->siguiente = tabla[idx];
        tabla[idx] = nuevo;
    }

    void mostrar() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "[" << i << "]: ";
            Nodo* actual = tabla[i];
            while (actual) {
                std::cout << actual->clave << " -> ";
                actual = actual->siguiente;
            }
            std::cout << "NULL\n";
        }
    }
};