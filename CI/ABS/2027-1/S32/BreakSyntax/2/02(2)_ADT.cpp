#include <iostream>
using namespace std;

class contenedorADT {
public:
    int *datos;
    int capacidad;
    int cantidad;

    int inicializar(int tam) {
        capacidad = tam;
        cantidad = 0;
        datos = new int[capacidad];
        return 1;
    }

    int agregar(int valor) {
        if (cantidad < capacidad) {
            datos[cantidad] = valor;
            cantidad++;
            return 1;
        }
        cout << "El ADT esta lleno." << endl;
        return 0;
    }

    int mostrar() {
        cout << "Elementos en el ADT: ";
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
        return 1;
    }
};

int main() {
    contenedorADT miAdt;
    int tam, valor;

    cout << "Ingresa la capacidad del ADT: ";
    cin >> tam;
    miAdt.inicializar(tam);

    for (int i = 0; i < tam; i++) {
        cout << "Ingresa el valor " << i + 1 << ": ";
        cin >> valor;
        miAdt.agregar(valor);
    }

    miAdt.mostrar();
    return 0;
}