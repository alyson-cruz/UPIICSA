#include <iostream>
using namespace std;

struct nodo {
    int dato;
    nodo *izq;
    nodo *der;
};

nodo* crearnodo(int valor) {
    nodo *nuevo = new nodo();
    nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

int insertar(nodo *&raiz, int valor) {
    if (raiz == NULL) {
        raiz = crearnodo(valor);
        return 1;
    }
    if (valor < raiz->dato) {
        return insertar(raiz->izq, valor);
    } else {
        return insertar(raiz->der, valor);
    }
}

int inorden(nodo *raiz) {
    if (raiz == NULL) return 0;
    inorden(raiz->izq);
    cout << raiz->dato << " ";
    inorden(raiz->der);
    return 1;
}

int preorden(nodo *raiz) {
    if (raiz == NULL) return 0;
    cout << raiz->dato << " ";
    preorden(raiz->izq);
    preorden(raiz->der);
    return 1;
}

int postorden(nodo *raiz) {
    if (raiz == NULL) return 0;
    postorden(raiz->izq);
    postorden(raiz->der);
    cout << raiz->dato << " ";
    return 1;
}

int main() {
    nodo *raiz = NULL;
    int n, valor;

    cout << "Cuantos nodos deseas insertar en el arbol?: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingresa el valor del nodo " << i + 1 << ": ";
        cin >> valor;
        insertar(raiz, valor);
    }

    cout << "\nRecorrido inorden: ";
    inorden(raiz);
    cout << "\nRecorrido preorden: ";
    preorden(raiz);
    cout << "\nRecorrido postorden: ";
    postorden(raiz);
    cout << endl;

    return 0;
}