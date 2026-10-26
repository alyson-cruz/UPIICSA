#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string ap;
    string am;
    char genero;
    int edad;
};

int main() {
    int n;
    cout << "Cuantas personas deseas registrar?: ";
    cin >> n;

    Persona lista[50];
    Persona *ptr = lista;

    for (int i = 0; i < n; i++) {
        cout << "\nPersona " << (i + 1) << endl;
        cout << "Nombre: ";
        cin >> (ptr + i)->nombre;
        cout << "Apellido paterno: ";
        cin >> (ptr + i)->ap;
        cout << "Apellido materno: ";
        cin >> (ptr + i)->am;
        cout << "Genero (M/F): ";
        cin >> (ptr + i)->genero;
        cout << "Edad: ";
        cin >> (ptr + i)->edad;
    }

    cout << "\nLista de Personas con Puntero (PE)" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ") " << (ptr + i)->nombre << " "
             << (ptr + i)->ap << " " << (ptr + i)->am
             << " | Genero: " << (ptr + i)->genero
             << " | Edad: " << (ptr + i)->edad << endl;
    }

    return 0;
}