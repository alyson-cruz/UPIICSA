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
    int entero;
    float flotante;
    double doble;
    char caracter;
    Auto a;
    Persona p;

    cout << "Ingresa un numero entero de prueba: ";
    cin >> entero;
    cout << "Ingresa un numero decimal de prueba: ";
    cin >> flotante;
    cout << "Ingresa un caracter de prueba: ";
    cin >> caracter;
    cout << "Ingresa el anio del auto: ";
    cin >> a.anio;
    cout << "Ingresa el nombre de la persona: ";
    cin >> p.nombre;

    cout << "\nTamanio en bytes (PE)" << endl;
    cout << "int: " << sizeof(entero) << " bytes" << endl;
    cout << "float: " << sizeof(flotante) << " bytes" << endl;
    cout << "double: " << sizeof(doble) << " bytes" << endl;
    cout << "char: " << sizeof(caracter) << " bytes" << endl;
    cout << "struct Auto: " << sizeof(a) << " bytes" << endl;
    cout << "struct Persona: " << sizeof(p) << " bytes" << endl;

    return 0;
}