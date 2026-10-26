#include <iostream>
using namespace std;

class pilaestatica {
public:
    int arreglo[100];
    int tope;
    int maxtam;

    int inicializar(int tam) {
        maxtam = tam;
        tope = -1;
        return 1;
    }

    int push(int dato) {
        if (tope == maxtam - 1) {
            cout << "La pila esta llena" << endl;
            return 0;
        }
        tope++;
        arreglo[tope] = dato;
        return 1;
    }

    int pop() {
        if (tope == -1) {
            cout << "La pila esta vacia" << endl;
            return 0;
        }
        cout << "Elemento eliminado: " << arreglo[tope] << endl;
        tope--;
        return 1;
    }

    int mostrar() {
        if (tope == -1) {
            cout << "Pila vacia" << endl;
            return 0;
        }
        cout << "Contenido de la pila (de tope a base): ";
        for (int i = tope; i >= 0; i--) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
        return 1;
    }
};

int main() {
    pilaestatica pila;
    int tam, op = 0, dato;

    cout << "Ingresa el tamanio maximo de la pila: ";
    cin >> tam;
    pila.inicializar(tam);

    while (op != 4) {
        cout << "\n1. Insertar (Push)\n2. Eliminar (Pop)\n3. Mostrar Pila\n4. Salir\nElige una opcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Ingresa el numero a insertar: ";
            cin >> dato;
            pila.push(dato);
        } else if (op == 2) {
            pila.pop();
        } else if (op == 3) {
            pila.mostrar();
        }
    }
    return 0;
}