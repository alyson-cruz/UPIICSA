#include <iostream>
using namespace std;

class listaestatica {
public:
    int arreglo[100];
    int cantidad;
    int maxtam;

    int inicializar(int tam) {
        maxtam = tam;
        cantidad = 0;
        return 1;
    }

    int insertar(int dato) {
        if (cantidad == maxtam) {
            cout << "La lista esta llena" << endl;
            return 0;
        }
        arreglo[cantidad] = dato;
        cantidad++;
        return 1;
    }

    int eliminarposicion(int pos) {
        if (cantidad == 0 || pos < 0 || pos >= cantidad) {
            cout << "Posicion invalida o lista vacia" << endl;
            return 0;
        }
        cout << "Elemento eliminado: " << arreglo[pos] << endl;
        for (int i = pos; i < cantidad - 1; i++) {
            arreglo[i] = arreglo[i + 1];
        }
        cantidad--;
        return 1;
    }

    int mostrar() {
        if (cantidad == 0) {
            cout << "Lista vacia" << endl;
            return 0;
        }
        cout << "Elementos de la lista: ";
        for (int i = 0; i < cantidad; i++) {
            cout << "[" << i << "]:" << arreglo[i] << "  ";
        }
        cout << endl;
        return 1;
    }
};

int main() {
    listaestatica lista;
    int tam, op = 0, dato, pos;

    cout << "Ingresa el tamanio maximo de la lista: ";
    cin >> tam;
    lista.inicializar(tam);

    while (op != 4) {
        cout << "\n1. Insertar dato\n2. Eliminar por posicion\n3. Mostrar Lista\n4. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Ingresa el dato: ";
            cin >> dato;
            lista.insertar(dato);
        } else if (op == 2) {
            cout << "Ingresa el indice a eliminar: ";
            cin >> pos;
            lista.eliminarposicion(pos);
        } else if (op == 3) {
            lista.mostrar();
        }
    }
    return 0;
}