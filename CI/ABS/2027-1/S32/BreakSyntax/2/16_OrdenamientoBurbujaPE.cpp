#include <iostream>
#include <string>
using namespace std;

struct persona {
    string nombre;
    int edad;
};

int main() {
    int n;
    cout << "Cuantos elementos deseas ordenar?: ";
    cin >> n;

    char letras[50];
    int numeros[50];
    persona lista[50];

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
        cout << "Nombre de persona " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Edad de persona " << i + 1 << ": ";
        cin >> lista[i].edad;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (letras[j] > letras[j + 1]) {
                char aux = letras[j];
                letras[j] = letras[j + 1];
                letras[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (lista[j].edad > lista[j + 1].edad) {
                persona aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    cout << "\nCaracteres ordenados: ";
    for (int i = 0; i < n; i++) cout << letras[i] << " ";

    cout << "\nEnteros ordenados: ";
    for (int i = 0; i < n; i++) cout << numeros[i] << " ";

    cout << "\nPersonas ordenadas por edad:" << endl;
    for (int i = 0; i < n; i++) {
        cout << lista[i].nombre << " (" << lista[i].edad << " años)" << endl;
    }

    return 0;
}
