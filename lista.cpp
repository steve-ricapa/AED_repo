#include <iostream>

const int MAX = 1000;

class Lista {
    int datos[MAX];
    int size;

public:
    Lista() : size(0) {}

    bool insertar(int valor) {
        if (size >= MAX) return false;
        datos[size++] = valor;
        return true;
    }

    void mostrar() {
        for (int i = 0; i < size; ++i)
            std::cout << datos[i] << " ";
        std::cout << std::endl;
    }
};