#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class colaADT {
public:
    int datos[50];
    int fin;

    int inicializar() {
        fin = -1;
        return 1;
    }

    int encolar(int val) {
        fin++;
        datos[fin] = val;
        return 1;
    }
};

class archivoXML {
public:
    int procesarXML() {
        int datoint;
        int narr, nper, ncola;
        int arreglo[50];
        persona p;
        persona arrpersonas[50];
        colaADT micola;
        micola.inicializar();

        cout << "Captura para archivo XML" << endl;
        cout << "Ingresa un dato basico entero: ";
        cin >> datoint;

        cout << "Tamaño del arreglo basico: ";
        cin >> narr;
        for (int i = 0; i < narr; i++) {
            cout << "Arreglo[" << i << "]: ";
            cin >> arreglo[i];
        }

        cout << "Dato creado persona -> nombre y edad: ";
        cin >> p.nombre >> p.edad;

        cout << "Cantidad de personas para el arreglo de creados: ";
        cin >> nper;
        for (int i = 0; i < nper; i++) {
            cout << "Persona " << i + 1 << " (nombre y edad): ";
            cin >> arrpersonas[i].nombre >> arrpersonas[i].edad;
        }

        cout << "Cantidad de elementos para el ADT cola: ";
        cin >> ncola;
        for (int i = 0; i < ncola; i++) {
            int v;
            cout << "Elemento " << i + 1 << " de la cola: ";
            cin >> v;
            micola.encolar(v);
        }

        ofstream xmlout("datos.xml");
        xmlout << "<practicaXML>" << endl;
        xmlout << "  <datobasico>" << datoint << "</datobasico>" << endl;

        xmlout << "  <arreglobasico>" << endl;
        for (int i = 0; i < narr; i++) {
            xmlout << "    <item>" << arreglo[i] << "</item>" << endl;
        }
        xmlout << "  </arreglobasico>" << endl;

        xmlout << "  <personaunica>" << endl;
        xmlout << "    <nombre>" << p.nombre << "</nombre>" << endl;
        xmlout << "    <edad>" << p.edad << "</edad>" << endl;
        xmlout << "  </personaunica>" << endl;

        xmlout << "  <listapersonas>" << endl;
        for (int i = 0; i < nper; i++) {
            xmlout << "    <persona>" << endl;
            xmlout << "      <nombre>" << arrpersonas[i].nombre << "</nombre>" << endl;
            xmlout << "      <edad>" << arrpersonas[i].edad << "</edad>" << endl;
            xmlout << "    </persona>" << endl;
        }
        xmlout << "  </listapersonas>" << endl;

        xmlout << "  <adtcola>" << endl;
        for (int i = 0; i <= micola.fin; i++) {
            xmlout << "    <nodo>" << micola.datos[i] << "</nodo>" << endl;
        }
        xmlout << "  </adtcola>" << endl;
        xmlout << "</practicaXML>" << endl;
        xmlout.close();

        cout << "\nContenido leido desde datos.xml" << endl;
        ifstream xmlin("datos.xml");
        string linea;
        while (getline(xmlin, linea)) {
            cout << linea << endl;
        }
        xmlin.close();

        return 1;
    }
};

int main() {
    archivoXML app;
    app.procesarXML();
    return 0;
}