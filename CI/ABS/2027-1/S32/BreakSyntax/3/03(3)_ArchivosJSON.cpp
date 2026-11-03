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

    int push(int v) {
        tope++;
        datos[tope] = v;
        return 1;
    }
};

class archivoJSON {
public:
    int procesarJSON() {
        int basico;
        int narr, nper, npila;
        int arr[50];
        persona p;
        persona arrp[50];
        pilaADT pila;
        pila.inicializar();

        cout << "Captura para archivo JSON" << endl;
        cout << "Ingresa un numero entero: ";
        cin >> basico;

        cout << "Tamaño del arreglo de enteros: ";
        cin >> narr;
        for (int i = 0; i < narr; i++) {
            cout << "Elemento " << i + 1 << ": ";
            cin >> arr[i];
        }

        cout << "Ingresa nombre y edad de una persona: ";
        cin >> p.nombre >> p.edad;

        cout << "Cuantas personas tendra el arreglo?: ";
        cin >> nper;
        for (int i = 0; i < nper; i++) {
            cout << "Persona " << i + 1 << " (nombre y edad): ";
            cin >> arrp[i].nombre >> arrp[i].edad;
        }

        cout << "Cuantos elementos tendra el ADT pila?: ";
        cin >> npila;
        for (int i = 0; i < npila; i++) {
            int v;
            cout << "Valor " << i + 1 << ": ";
            cin >> v;
            pila.push(v);
        }

        ofstream jsonout("datos.json");
        jsonout << "{" << endl;
        jsonout << "  \"datobasico\": " << basico << "," << endl;

        jsonout << "  \"arreglo\": [";
        for (int i = 0; i < narr; i++) {
            jsonout << arr[i];
            if (i < narr - 1) jsonout << ", ";
        }
        jsonout << "]," << endl;

        jsonout << "  \"persona\": {\"nombre\": \"" << p.nombre << "\", \"edad\": " << p.edad << "}," << endl;

        jsonout << "  \"listapersonas\": [" << endl;
        for (int i = 0; i < nper; i++) {
            jsonout << "    {\"nombre\": \"" << arrp[i].nombre << "\", \"edad\": " << arrp[i].edad << "}";
            if (i < nper - 1) jsonout << ",";
            jsonout << endl;
        }
        jsonout << "  ]," << endl;

        jsonout << "  \"adtpila\": [";
        for (int i = pila.tope; i >= 0; i--) {
            jsonout << pila.datos[i];
            if (i > 0) jsonout << ", ";
        }
        jsonout << "]" << endl;
        jsonout << "}" << endl;
        jsonout.close();

        cout << "\nContenido leido desde datos.json" << endl;
        ifstream jsonin("datos.json");
        string linea;
        while (getline(jsonin, linea)) {
            cout << linea << endl;
        }
        jsonin.close();

        return 1;
    }
};

int main() {
    archivoJSON app;
    app.procesarJSON();
    return 0;
}