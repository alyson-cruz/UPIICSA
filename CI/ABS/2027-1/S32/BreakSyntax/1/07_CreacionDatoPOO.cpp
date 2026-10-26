#include <iostream>
#include <string>
using namespace std;

class Auto {
public:
    float precio;
    int anio;

    int capturar() {
        cout << "Ingresa el precio del auto: ";
        cin >> precio;
        cout << "Ingresa el anio del auto: ";
        cin >> anio;
        return 1;
    }

    int mostrar() {
        cout << "Auto -> Precio: $" << precio << " | Anio: " << anio << endl;
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
        cout << "Ingresa el nombre: ";
        cin >> nombre;
        cout << "Ingresa el apellido paterno: ";
        cin >> ap;
        cout << "Ingresa el apellido materno: ";
        cin >> am;
        cout << "Ingresa el genero (M/F): ";
        cin >> genero;
        cout << "Ingresa la edad: ";
        cin >> edad;
        return 1;
    }

    int mostrar() {
        cout << "Persona -> " << nombre << " " << ap << " " << am
             << " | Genero: " << genero << " | Edad: " << edad << endl;
        return 1;
    }
};

int main() {
    Auto miauto;
    Persona p;

    cout << "Datos del Auto (POO)" << endl;
    miauto.capturar();

    cout << "\nDatos de la Persona (POO)" << endl;
    p.capturar();

    cout << "\nInformacion Capturada" << endl;
    miauto.mostrar();
    p.mostrar();

    return 0;
}