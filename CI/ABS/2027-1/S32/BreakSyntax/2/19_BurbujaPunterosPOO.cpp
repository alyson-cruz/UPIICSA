#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class burbujaindirecta {
public:
    int n;
    char letras[50];
    int numeros[50];
    persona lista[50];

    char *pletras;
    int *pnumeros;
    persona *plista;

    int iniciar() {
        pletras = letras;
        pnumeros = numeros;
        plista = lista;

        cout << "Cuantos elementos deseas ordenar?: ";
        cin >> n;

        cout << "\nIngresa caracteres" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Caracter " << i + 1 << ": ";
            cin >> *(pletras + i);
        }

        cout << "\nIngresa enteros" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> *(pnumeros + i);
        }

        cout << "\nIngresa personas" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Nombre " << i + 1 << ": ";
            cin >> (plista + i)->nombre;
            cout << "Edad " << i + 1 << ": ";
            cin >> (plista + i)->edad;
        }
        return 1;
    }

    int ordenar() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (*(pletras + j) > *(pletras + j + 1)) {
                    char aux = *(pletras + j);
                    *(pletras + j) = *(pletras + j + 1);
                    *(pletras + j + 1) = aux;
                }
                if (*(pnumeros + j) > *(pnumeros + j + 1)) {
                    int aux = *(pnumeros + j);
                    *(pnumeros + j) = *(pnumeros + j + 1);
                    *(pnumeros + j + 1) = aux;
                }
                if ((plista + j)->edad > (plista + j + 1)->edad) {
                    persona aux = *(plista + j);
                    *(plista + j) = *(plista + j + 1);
                    *(plista + j + 1) = aux;
                }
            }
        }
        return 1;
    }

    int mostrar() {
        cout << "\nCaracteres ordenados: ";
        for (int i = 0; i < n; i++) cout << *(pletras + i) << " ";

        cout << "\nEnteros ordenados: ";
        for (int i = 0; i < n; i++) cout << *(pnumeros + i) << " ";

        cout << "\nPersonas ordenadas por edad:" << endl;
        for (int i = 0; i < n; i++) {
            cout << (plista + i)->nombre << " (" << (plista + i)->edad << " años)" << endl;
        }
        return 1;
    }
};

int main() {
    burbujaindirecta app;
    app.iniciar();
    app.ordenar();
    app.mostrar();
    return 0;
}