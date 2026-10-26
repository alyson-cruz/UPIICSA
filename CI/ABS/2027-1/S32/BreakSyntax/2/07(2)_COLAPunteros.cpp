#include <iostream>
using namespace std;

class nodocola {
public:
    int dato;
    nodocola *siguiente;
};

class coladinamica {
public:
    int encolar(nodocola *&frente, nodocola *&fin, int valor) {
        nodocola *nuevo = new nodocola();
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        if (frente == NULL) {
            frente = nuevo;
        } else {
            fin->siguiente = nuevo;
        }
        fin = nuevo;
        return 1;
    }

    int desencolar(nodocola *&frente, nodocola *&fin) {
        if (frente == NULL) {
            cout << "La cola dinamica esta vacia" << endl;
            return 0;
        }
        nodocola *aux = frente;
        cout << "Elemento eliminado: " << aux->dato << endl;
        frente = frente->siguiente;
        if (frente == NULL) {
            fin = NULL;
        }
        delete aux;
        return 1;
    }

    int mostrar(nodocola *&frente) {
        if (frente == NULL) {
            cout << "Cola vacia" << endl;
            return 0;
        }
        nodocola *actual = frente;
        cout << "Cola dinamica: ";
        while (actual != NULL) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
        return 1;
    }
};

int main() {
    nodocola *frente = NULL;
    nodocola *fin = NULL;
    coladinamica cola;
    int n, valor, op = 0;

    cout << "Cuantos elementos iniciales deseas agregar a la cola?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingresa dato " << i + 1 << ": ";
        cin >> valor;
        cola.encolar(frente, fin, valor);
    }

    while (op != 4) {
        cout << "\n1. Encolar\n2. Desencolar\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Dato: ";
            cin >> valor;
            cola.encolar(frente, fin, valor);
        } else if (op == 2) {
            cola.desencolar(frente, fin);
        } else if (op == 3) {
            cola.mostrar(frente);
        }
    }
    return 0;
}