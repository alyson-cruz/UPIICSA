#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    string ap;
    string am;
    char genero;
    int edad;

    int capturar() {
        cout << "Nombre: ";
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
        cout << nombre << " " << ap << " " << am
             << " | Genero: " << genero << " | Edad: " << edad << endl;
        return 1;
    }
};

int main() {
    int n;
    cout << "Cuantas personas deseas registrar?: ";
    cin >> n;

    Persona lista[50];
    Persona *ptr = lista;

    for (int i = 0; i < n; i++) {
        cout << "\nPersona " << (i + 1) << endl;
        (ptr + i)->capturar();
    }

    cout << "\nLista de Personas con Puntero (POO)" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ") ";
        (ptr + i)->mostrar();
    }

    return 0;
}