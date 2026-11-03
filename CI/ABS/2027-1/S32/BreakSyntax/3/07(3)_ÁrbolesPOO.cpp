#include <iostream>
using namespace std;

class nodoarbol {
public:
    int dato;
    nodoarbol *izq;
    nodoarbol *der;
};

class arbolbinario {
public:
    nodoarbol *raiz;

    int inicializar() {
        raiz = NULL;
        return 1;
    }

    int insertar(nodoarbol *&nodo, int valor) {
        if (nodo == NULL) {
            nodo = new nodoarbol();
            nodo->dato = valor;
            nodo->izq = NULL;
            nodo->der = NULL;
            return 1;
        }
        if (valor < nodo->dato) {
            return insertar(nodo->izq, valor);
        } else {
            return insertar(nodo->der, valor);
        }
    }

    int inorden(nodoarbol *nodo) {
        if (nodo == NULL) return 0;
        inorden(nodo->izq);
        cout << nodo->dato << " ";
        inorden(nodo->der);
        return 1;
    }

    int preorden(nodoarbol *nodo) {
        if (nodo == NULL) return 0;
        cout << nodo->dato << " ";
        preorden(nodo->izq);
        preorden(nodo->der);
        return 1;
    }

    int postorden(nodoarbol *nodo) {
        if (nodo == NULL) return 0;
        postorden(nodo->izq);
        postorden(nodo->der);
        cout << nodo->dato << " ";
        return 1;
    }

    int buscar(nodoarbol *nodo, int valor) {
        if (nodo == NULL) return 0;
        if (nodo->dato == valor) return 1;
        if (valor < nodo->dato) return buscar(nodo->izq, valor);
        return buscar(nodo->der, valor);
    }
};

int main() {
    arbolbinario arbol;
    arbol.inicializar();
    int n, valor, buscado;

    cout << "Cuantos nodos deseas insertar en el arbol?: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Valor del nodo " << i + 1 << ": ";
        cin >> valor;
        arbol.insertar(arbol.raiz, valor);
    }

    cout << "\nRecorrido inorden: ";
    arbol.inorden(arbol.raiz);
    cout << "\nRecorrido preorden: ";
    arbol.preorden(arbol.raiz);
    cout << "\nRecorrido postorden: ";
    arbol.postorden(arbol.raiz);

    cout << "\n\nIngresa un numero para buscar en el arbol: ";
    cin >> buscado;
    if (arbol.buscar(arbol.raiz, buscado) == 1) {
        cout << "El numero " << buscado << " SI se encuentra en el arbol." << endl;
    } else {
        cout << "El numero " << buscado << " NO se encuentra en el arbol." << endl;
    }

    return 0;
}