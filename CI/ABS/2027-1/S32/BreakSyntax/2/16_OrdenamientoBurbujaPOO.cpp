#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class ordenamientoburbuja {
public:
    int n;
    char letras[50];
    int numeros[50];
    persona lista[50];

    int capturar() {
        cout << "Cuantos elementos deseas ordenar?: ";
        cin >> n;

        cout << "\nIngresa " << n << " caracteres" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Caracter " << i + 1 << ": ";
            cin >> letras[i];
        }

        cout << "\nIngresa " << n << " numeros enteros" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> numeros[i];
        }

        cout << "\nIngresa " << n << " personas" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Nombre " << i + 1 << ": ";
            cin >> lista[i].nombre;
            cout << "Edad " << i + 1 << ": ";
            cin >> lista[i].edad;
        }
        return 1;
    }

    int ordenar() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (letras[j] > letras[j + 1]) {
                    char aux = letras[j];
                    letras[j] = letras[j + 1];
                    letras[j + 1] = aux;
                }
                if (numeros[j] > numeros[j + 1]) {
                    int aux = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = aux;
                }
                if (lista[j].edad > lista[j + 1].edad) {
                    persona aux = lista[j];
                    lista[j] = lista[j + 1];
                    lista[j + 1] = aux;
                }
            }
        }
        return 1;
    }

    int mostrar() {
        cout << "\nCaracteres ordenados: ";
        for (int i = 0; i < n; i++) cout << letras[i] << " ";

        cout << "\nEnteros ordenados: ";
        for (int i = 0; i < n; i++) cout << numeros[i] << " ";

        cout << "\nPersonas ordenadas por edad:" << endl;
        for (int i = 0; i < n; i++) {
            cout << lista[i].nombre << " (" << lista[i].edad << " años)" << endl;
        }
        return 1;
    }
};

int main() {
    ordenamientoburbuja obj;
    obj.capturar();
    obj.ordenar();
    obj.mostrar();
    return 0;
}