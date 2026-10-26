#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    string ap;
    int edad;
    persona *siguiente;

    int capturar() {
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido paterno: ";
        cin >> ap;
        cout << "Edad: ";
        cin >> edad;
        siguiente = NULL;
        return 1;
    }

    int mostrar() {
        cout << "Nombre: " << nombre << " " << ap << " | Edad: " << edad << endl;
        return 1;
    }
};

int main() {
    int n;
    cout << "Cuantas personas deseas enlazar en la clase?: ";
    cin >> n;

    persona lista[50];

    for (int i = 0; i < n; i++) {
        cout << "\nPersona " << i + 1 << endl;
        lista[i].capturar();
        if (i < n - 1) {
            lista[i].siguiente = &lista[i + 1];
        }
    }

    cout << "\nRecorrido mediante puntero al mismo tipo de dato (POO)" << endl;
    persona *actual = &lista[0];
    while (actual != NULL) {
        actual->mostrar();
        actual = actual->siguiente;
    }

    return 0;
}