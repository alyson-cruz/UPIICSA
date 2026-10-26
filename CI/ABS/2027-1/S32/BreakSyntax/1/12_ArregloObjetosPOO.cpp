#include <iostream>
#include <string>
using namespace std;

class Auto {
public:
    float precio;
    int anio;

    int capturar() {
        cout << "Precio del auto: ";
        cin >> precio;
        cout << "Año del auto: ";
        cin >> anio;
        return 1;
    }

    int mostrar() {
        cout << "Auto: $" << precio << " (" << anio << ")";
        return 1;
    }
};

class Persona {
public:
    string nombre;
    string ap;
    string am;
    char genero;
    int edad;

    int capturar() {
        cout << "Nombre de la persona: ";
        cin >> nombre;
        cout << "Apellido paterno: ";
        cin >> ap;
        cout << "Apellido materno: ";
        cin >> am;
        cout << "Genero (M/F): ";
        cin >> genero;
        cout << "Edad: ";
        cin >> edad;
        return 1;
    }

    int mostrar() {
        cout << "Persona: " << nombre << " " << ap << " " << am
             << ", " << genero << ", " << edad << " anios" << endl;
        return 1;
    }
};

int main() {
    int n;
    cout << "Cuantos registros de personas y autos deseas ingresar?: ";
    cin >> n;

    Auto listaautos[50];
    Persona listapersonas[50];

    for (int i = 0; i < n; i++) {
        cout << "\nRegistro " << (i + 1) << endl;
        listaautos[i].capturar();
        listapersonas[i].capturar();
    }

    cout << "\nLista de Autos y Personas (POO)" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ") ";
        listaautos[i].mostrar();
        cout << " | ";
        listapersonas[i].mostrar();
    }

    return 0;
}