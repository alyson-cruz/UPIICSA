#include <iostream>
using namespace std;

class nodolista {
public:
    int dato;
    nodolista *siguiente;
};

class listadinamica {
public:
    int insertarfinal(nodolista *&cabeza, int valor) {
        nodolista *nuevo = new nodolista();
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        if (cabeza == NULL) {
            cabeza = nuevo;
        } else {
            nodolista *actual = cabeza;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        return 1;
    }

    int eliminardato(nodolista *&cabeza, int valor) {
        if (cabeza == NULL) {
            cout << "La lista esta vacia" << endl;
            return 0;
        }
        if (cabeza->dato == valor) {
            nodolista *aux = cabeza;
            cabeza = cabeza->siguiente;
            delete aux;
            cout << "Elemento eliminado" << endl;
            return 1;
        }
        nodolista *actual = cabeza;
        while (actual->siguiente != NULL && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }
        if (actual->siguiente != NULL) {
            nodolista *aux = actual->siguiente;
            actual->siguiente = aux->siguiente;
            delete aux;
            cout << "Elemento eliminado" << endl;
            return 1;
        }
        cout << "No se encontro el elemento" << endl;
        return 0;
    }

    int mostrar(nodolista *&cabeza) {
        if (cabeza == NULL) {
            cout << "Lista vacia" << endl;
            return 0;
        }
        nodolista *actual = cabeza;
        cout << "Lista dinamica: ";
        while (actual != NULL) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
        return 1;
    }
};

int main() {
    nodolista *cabeza = NULL;
    listadinamica lista;
    int n, valor, op = 0;

    cout << "Cuantos elementos iniciales deseas en la lista?: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ingresa dato " << i + 1 << ": ";
        cin >> valor;
        lista.insertarfinal(cabeza, valor);
    }

    while (op != 4) {
        cout << "\n1. Insertar\n2. Eliminar por valor\n3. Mostrar\n4. Salir\nOpcion: ";
        cin >> op;
        if (op == 1) {
            cout << "Dato a insertar: ";
            cin >> valor;
            lista.insertarfinal(cabeza, valor);
        } else if (op == 2) {
            cout << "Dato a eliminar: ";
            cin >> valor;
            lista.eliminardato(cabeza, valor);
        } else if (op == 3) {
            lista.mostrar(cabeza);
        }
    }
    return 0;
}