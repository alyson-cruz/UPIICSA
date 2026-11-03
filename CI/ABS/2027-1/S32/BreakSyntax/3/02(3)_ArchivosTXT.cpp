#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Auto {
public:
    float precio;
    int anio;
};

class listaADT {
public:
    int elementos[50];
    int cantidad;

    int inicializar() {
        cantidad = 0;
        return 1;
    }

    int agregar(int d) {
        elementos[cantidad] = d;
        cantidad++;
        return 1;
    }
};

class archivoTXT {
public:
    int procesarTXT() {
        int numero;
        int narr, nautos, nlista;
        int arr[50];
        Auto unauto;
        Auto listaautos[50];
        listaADT milista;
        milista.inicializar();

        cout << "Captura para archivo TXT" << endl;
        cout << "Ingresa un numero entero: ";
        cin >> numero;

        cout << "Cuantos numeros tendra el arreglo?: ";
        cin >> narr;
        for (int i = 0; i < narr; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> arr[i];
        }

        cout << "Ingresa precio y año de un auto: ";
        cin >> unauto.precio >> unauto.anio;

        cout << "Cuantos autos deseas guardar en el arreglo de autos?: ";
        cin >> nautos;
        for (int i = 0; i < nautos; i++) {
            cout << "Auto " << i + 1 << " (precio y año): ";
            cin >> listaautos[i].precio >> listaautos[i].anio;
        }

        cout << "Cuantos datos deseas insertar en el ADT lista?: ";
        cin >> nlista;
        for (int i = 0; i < nlista; i++) {
            int val;
            cout << "Dato " << i + 1 << ": ";
            cin >> val;
            milista.agregar(val);
        }

        ofstream txtout("datos.txt");
        txtout << "Archivo de texto" << endl;
        txtout << "Dato basico: " << numero << endl;

        txtout << "Arreglo basico: ";
        for (int i = 0; i < narr; i++) {
            txtout << arr[i] << " ";
        }
        txtout << endl;

        txtout << "Dato creado auto -> precio: $" << unauto.precio << " año: " << unauto.anio << endl;

        txtout << "Arreglo de autos:" << endl;
        for (int i = 0; i < nautos; i++) {
            txtout << "  Auto " << i + 1 << ": $" << listaautos[i].precio << " (" << listaautos[i].anio << ")" << endl;
        }

        txtout << "ADT lista: ";
        for (int i = 0; i < milista.cantidad; i++) {
            txtout << milista.elementos[i] << " -> ";
        }
        txtout << "Fin" << endl;
        txtout.close();

        cout << "\nContenido leido desde datos.txt" << endl;
        ifstream txtin("datos.txt");
        string linea;
        while (getline(txtin, linea)) {
            cout << linea << endl;
        }
        txtin.close();

        return 1;
    }
};

int main() {
    archivoTXT app;
    app.procesarTXT();
    return 0;
}