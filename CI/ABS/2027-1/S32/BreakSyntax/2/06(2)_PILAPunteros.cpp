#include <iostream>
using namespace std;

class nodopila {
public:
    int dato;
    nodopila *siguiente;
};

class piladinamica {
public:
    int push(nodopila *&tope, int valor) {
        nodopila *nuevo = new nodopila();
        nuevo->dato = valor;
        nuevo->siguiente = tope;
        tope = nuevo;
        return 1;
    }

    int pop(nodopila *&tope) {
        if (tope == NULL) {
            cout << "La pila dinamica esta vacia" << endl;
            return 0;
        }
        nodopila *aux = tope;
        cout << "Elemento eliminado: " << aux->dato << endl;
        tope = tope->siguiente;
        delete aux;
        return 1;
    }

    int mostrar(nodopila *&tope) {
        if (tope == NULL) {
            cout << "Pila vacia" << endl;
            return 0;
        }
        nodopila *actual = tope;
        cout << "Pila dinamica: ";
        while (actual != NULL) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
        return 1;
    }
};

int main() {
    nodopila *tope = NULL;
    piladinamica pila;
    int n, valor, op = 0;

    cout << "Cuantos elementos iniciales deseas ingresar a la pila?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingresa dato " << i + 1 << ": ";
        cin >> valor;
        pila.push(tope, valor);
    }

    while (op != 4) {
        cout << "\n1. Push\n2. Pop\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Dato: ";
            cin >> valor;
            pila.push(tope, valor);
        } else if (op == 2) {
            pila.pop(tope);
        } else if (op == 3) {
            pila.mostrar(tope);
        }
    }
    return 0;
}