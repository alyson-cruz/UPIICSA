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
    Auto miauto;
    Persona p;

    cout << "Datos del Auto (PE)" << endl;
    cout << "Ingresa el precio del auto: ";
    cin >> miauto.precio;
    cout << "Ingresa el anio del auto: ";
    cin >> miauto.anio;

    cout << "\nDatos de la Persona (PE)" << endl;
    cout << "Ingresa el nombre: ";
    cin >> p.nombre;
    cout << "Ingresa el apellido paterno: ";
    cin >> p.ap;
    cout << "Ingresa el apellido materno: ";
    cin >> p.am;
    cout << "Ingresa el genero (M/F): ";
    cin >> p.genero;
    cout << "Ingresa la edad: ";
    cin >> p.edad;

    cout << "\nInformacion Capturada" << endl;
    cout << "Auto -> Precio: $" << miauto.precio << " | Anio: " << miauto.anio << endl;
    cout << "Persona -> " << p.nombre << " " << p.ap << " " << p.am
         << " | Genero: " << p.genero << " | Edad: " << p.edad << endl;

    return 0;
}