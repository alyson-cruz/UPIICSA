#include <iostream>
#include <string>
using namespace std;

struct persona {
    string nombre;
    string ap;
    int edad;
    persona *siguiente;
};

int main() {
    int n;
    cout << "Cuantas personas deseas enlazar en la estructura?: ";
    cin >> n;

    persona lista[50];

    for (int i = 0; i < n; i++) {
        cout << "\nPersona " << i + 1 << endl;
        cout << "Nombre: ";
        cin >> lista[i].nombre;
        cout << "Apellido paterno: ";
        cin >> lista[i].ap;
        cout << "Edad: ";
        cin >> lista[i].edad;

        if (i < n - 1) {
            lista[i].siguiente = &lista[i + 1];
        } else {
            lista[i].siguiente = NULL;
        }
    }

    cout << "\nRecorrido mediante el puntero al mismo tipo de dato (PE)" << endl;
    persona *actual = &lista[0];
    while (actual != NULL) {
        cout << "Nombre: " << actual->nombre << " " << actual->ap
             << " | Edad: " << actual->edad << endl;
        actual = actual->siguiente;
    }

    return 0;
}