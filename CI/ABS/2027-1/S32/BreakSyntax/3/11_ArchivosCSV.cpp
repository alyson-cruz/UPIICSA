#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class pilaADT {
public:
    int datos[50];
    int tope;

    int inicializar() {
        tope = -1;
        return 1;
    }

    int push(int val) {
        tope++;
        datos[tope] = val;
        return 1;
    }
};

class archivoCSV {
public:
    int guardaryleer() {
        int enterobasico;
        float flotantebasico;
        int narr, nper, npila;
        int arreglo[50];
        persona punica;
        persona listapersonas[50];
        pilaADT mipila;
        mipila.inicializar();

        cout << "1. Datos basicos" << endl;
        cout << "Ingresa un numero entero: ";
        cin >> enterobasico;
        cout << "Ingresa un numero decimal: ";
        cin >> flotantebasico;

        cout << "\n2. Arreglo de enteros" << endl;
        cout << "De que tamaño quieres el arreglo?: ";
        cin >> narr;
        for (int i = 0; i < narr; i++) {
            cout << "Elemento " << i + 1 << ": ";
            cin >> arreglo[i];
        }

        cout << "\n3. Tipo de dato creado (persona)" << endl;
        cout << "Nombre: ";
        cin >> punica.nombre;
        cout << "Edad: ";
        cin >> punica.edad;

        cout << "\n4. Arreglo de tipos creados (personas)" << endl;
        cout << "Cuantas personas deseas registrar en el arreglo?: ";
        cin >> nper;
        for (int i = 0; i < nper; i++) {
            cout << "Nombre persona " << i + 1 << ": ";
            cin >> listapersonas[i].nombre;
            cout << "Edad persona " << i + 1 << ": ";
            cin >> listapersonas[i].edad;
        }

        cout << "\n5. ADT (pila)" << endl;
        cout << "Cuantos elementos deseas apilar en el ADT?: ";
        cin >> npila;
        for (int i = 0; i < npila; i++) {
            int val;
            cout << "Valor " << i + 1 << " para la pila: ";
            cin >> val;
            mipila.push(val);
        }

        ofstream archivosalida("datos.csv");
        archivosalida << "Tipo, valores" << endl;
        archivosalida << "Datos basicos," << enterobasico << "," << flotantebasico << endl;

        archivosalida << "Arreglo";
        for (int i = 0; i < narr; i++) {
            archivosalida << "," << arreglo[i];
        }
        archivosalida << endl;

        archivosalida << "Dato creado," << punica.nombre << "," << punica.edad << endl;

        for (int i = 0; i < nper; i++) {
            archivosalida << "Arreglo creado," << listapersonas[i].nombre << "," << listapersonas[i].edad << endl;
        }

        archivosalida << "ADT_pila";
        for (int i = mipila.tope; i >= 0; i--) {
            archivosalida << "," << mipila.datos[i];
        }
        archivosalida << endl;
        archivosalida.close();

        cout << "\nContenido leido desde datos.csv" << endl;
        ifstream archivoentrada("datos.csv");
        string linea;
        while (getline(archivoentrada, linea)) {
            cout << linea << endl;
        }
        archivoentrada.close();

        return 1;
    }
};

int main() {
    archivoCSV app;
    app.guardaryleer();
    return 0;
}
