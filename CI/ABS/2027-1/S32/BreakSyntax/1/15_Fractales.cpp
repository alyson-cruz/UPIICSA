#include <iostream>
using namespace std;

class fractales {
public:
    int espacios(int n) {
        if (n <= 0) return 0;
        cout << " ";
        return espacios(n - 1);
    }

    int columnasierpinski(int fila, int col, int tam) {
        if (col >= tam) return 1;
        if ((fila & col) == 0) {
            cout << "* ";
        } else {
            cout << "  ";
        }
        return columnasierpinski(fila, col + 1, tam);
    }

    int filasierpinski(int fila, int tam) {
        if (fila < 0) return 1;
        espacios(fila);
        columnasierpinski(fila, 0, tam - fila);
        cout << endl;
        return filasierpinski(fila - 1, tam);
    }

    int segmentocantor(int inicio, int longitud, int nivel) {
        if (nivel == 0) {
            for (int i = 0; i < longitud; i++) {
                cout << "*";
            }
            return 1;
        }
        int tercio = longitud / 3;
        segmentocantor(inicio, tercio, nivel - 1);
        for (int i = 0; i < tercio; i++) {
            cout << " ";
        }
        segmentocantor(inicio + 2 * tercio, tercio, nivel - 1);
        return 1;
    }

    int nivelescantor(int actual, int maxnivel, int longitud) {
        if (actual > maxnivel) return 1;
        segmentocantor(0, longitud, actual);
        cout << endl;
        return nivelescantor(actual + 1, maxnivel, longitud);
    }

    fractales() {
        int nivelsierpinski, nivelcantor;

        cout << "Ingresa el tamaño del Triangulo de Sierpinski: ";
        cin >> nivelsierpinski;
        cout << "\nTriangulo de Sierpinski\n" << endl;
        filasierpinski(nivelsierpinski - 1, nivelsierpinski);

        cout << "\nIngresa el numero de niveles para el Polvo de Cantor: ";
        cin >> nivelcantor;
        int longitud = 1;
        for (int i = 0; i < nivelcantor; i++) {
            longitud = longitud * 3;
        }

        cout << "\nPolvo de Cantor\n" << endl;
        nivelescantor(0, nivelcantor, longitud);
    }
};

int main() {
    fractales();
    return 0;
}