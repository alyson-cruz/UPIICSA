#include <iostream>
#include <string>
using namespace std;

struct Auto {
    float precio;
    int anio;
};

struct Persona {
    string nombre;
    string ap;
    string am;
    char genero;
    int edad;
};

int main() {
    int n;
    cout << "Cuantos registros de personas y autos deseas ingresar?: ";
    cin >> n;

    Auto listaautos[50];
    Persona listapersonas[50];

    for (int i = 0; i < n; i++) {
        cout << "\nRegistro " << (i + 1) << endl;
        cout << "Precio del auto: ";
        cin >> listaautos[i].precio;
        cout << "Año del auto: ";
        cin >> listaautos[i].anio;

        cout << "Nombre de la persona: ";
        cin >> listapersonas[i].nombre;
        cout << "Apellido paterno: ";
        cin >> listapersonas[i].ap;
        cout << "Apellido materno: ";
        cin >> listapersonas[i].am;
        cout << "Genero (M/F): ";
        cin >> listapersonas[i].genero;
        cout << "Edad: ";
        cin >> listapersonas[i].edad;
    }

    cout << "\nLista de Autos y Personas (PE)" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ") Auto: $" << listaautos[i].precio << " (" << listaautos[i].anio << ") | "
             << "Persona: " << listapersonas[i].nombre << " " << listapersonas[i].ap << " "
             << listapersonas[i].am << ", " << listapersonas[i].genero << ", "
             << listapersonas[i].edad << " anios" << endl;
    }

    return 0;
}