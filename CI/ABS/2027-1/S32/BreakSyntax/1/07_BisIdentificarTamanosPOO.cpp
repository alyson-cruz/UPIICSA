#include <iostream>
#include <string>
using namespace std;

class Auto {
public:
    float precio;
    int anio;
};

class persona {
public:
    string nombre;
    string ap;
    string am;
    char genero;
    int edad;
};

class evaluadortamanios {
public:
    int mostrartamanios(int e, float f, double d, char c, Auto a, persona p) {
        cout << "\nTamanio en bytes (POO)" << endl;
        cout << "int: " << sizeof(e) << " bytes" << endl;
        cout << "float: " << sizeof(f) << " bytes" << endl;
        cout << "double: " << sizeof(d) << " bytes" << endl;
        cout << "char: " << sizeof(c) << " bytes" << endl;
        cout << "class Auto: " << sizeof(a) << " bytes" << endl;
        cout << "class Persona: " << sizeof(p) << " bytes" << endl;
        return 1;
    }
};

int main() {
    int entero;
    float flotante;
    double doble = 0.0;
    char caracter;
    Auto miauto;
    persona mipersona;
    evaluadortamanios eval;

    cout << "Ingresa un numero entero: ";
    cin >> entero;
    cout << "Ingresa un numero flotante: ";
    cin >> flotante;
    cout << "Ingresa una letra: ";
    cin >> caracter;
    cout << "Ingresa el precio del auto: ";
    cin >> miauto.precio;
    cout << "Ingresa la edad de la persona: ";
    cin >> mipersona.edad;

    eval.mostrartamanios(entero, flotante, doble, caracter, miauto, mipersona);
    return 0;
}