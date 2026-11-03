#include <iostream>
#include <fstream>
using namespace std;

class Auto {
public:
    float precio;
    int anio;
};

class archivobinario {
public:
    int procesarbinario() {
        int datobasico;
        int narr;
        int arreglo[50];
        Auto miauto;

        cout << "Captura para archivo binario (.dat)" << endl;
        cout << "Ingresa un numero entero: ";
        cin >> datobasico;

        cout << "Ingresa el tamaño del arreglo: ";
        cin >> narr;
        for (int i = 0; i < narr; i++) {
            cout << "Elemento " << i + 1 << ": ";
            cin >> arreglo[i];
        }

        cout << "Ingresa el precio y el año del auto: ";
        cin >> miauto.precio >> miauto.anio;

        ofstream binout("datos.dat", ios::binary);
        binout.write((char*)&datobasico, sizeof(datobasico));
        binout.write((char*)&narr, sizeof(narr));
        binout.write((char*)arreglo, narr * sizeof(int));
        binout.write((char*)&miauto, sizeof(Auto));
        binout.close();

        int leidobasico = 0, leidon = 0;
        int leidoarreglo[50];
        Auto leidoauto;

        ifstream binin("datos.dat", ios::binary);
        binin.read((char*)&leidobasico, sizeof(leidobasico));
        binin.read((char*)&leidon, sizeof(leidon));
        binin.read((char*)leidoarreglo, leidon * sizeof(int));
        binin.read((char*)&leidoauto, sizeof(Auto));
        binin.close();

        cout << "\nDatos recuperados del archivo binario" << endl;
        cout << "Dato basico: " << leidobasico << endl;
        cout << "Arreglo: ";
        for (int i = 0; i < leidon; i++) {
            cout << leidoarreglo[i] << " ";
        }
        cout << "\nauto -> precio: $" << leidoauto.precio << " | año: " << leidoauto.anio << endl;

        return 1;
    }
};

int main() {
    archivobinario app;
    app.procesarbinario();
    return 0;
}