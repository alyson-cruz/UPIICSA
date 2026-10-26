#include <iostream>
using namespace std;

class colaestatica {
public:
    int arreglo[100];
    int frente;
    int fin;
    int maxtam;

    int inicializar(int tam) {
        maxtam = tam;
        frente = 0;
        fin = -1;
        return 1;
    }

    int insertar(int dato) {
        if (fin == maxtam - 1) {
            cout << "La cola esta llena" << endl;
            return 0;
        }
        fin++;
        arreglo[fin] = dato;
        return 1;
    }

    int eliminar() {
        if (frente > fin) {
            cout << "La cola esta vacia" << endl;
            return 0;
        }
        cout << "Elemento atendido: " << arreglo[frente] << endl;
        frente++;
        return 1;
    }

    int mostrar() {
        if (frente > fin) {
            cout << "Cola vacia" << endl;
            return 0;
        }
        cout << "Elementos en la cola: ";
        for (int i = frente; i <= fin; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
        return 1;
    }
};

int main() {
    colaestatica cola;
    int tam, op = 0, dato;

    cout << "Ingresa la capacidad de la cola: ";
    cin >> tam;
    cola.inicializar(tam);

    while (op != 4) {
        cout << "\n1. Encolar\n2. Desencolar\n3. Mostrar Cola\n4. Salir\nElige una opcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Ingresa el dato: ";
            cin >> dato;
            cola.insertar(dato);
        } else if (op == 2) {
            cola.eliminar();
        } else if (op == 3) {
            cola.mostrar();
        }
    }
    return 0;
}