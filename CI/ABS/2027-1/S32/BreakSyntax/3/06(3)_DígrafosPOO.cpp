#include <iostream>
using namespace std;

class digrafo {
public:
    int matriz[50][50];
    int vertices;
    int arcos;

    int inicializar() {
        cout << "Ingresa el numero de vertices del digrafo: ";
        cin >> vertices;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                matriz[i][j] = 0;
            }
        }
        return 1;
    }

    int capturararcos() {
        cout << "Ingresa el numero de arcos dirigidos: ";
        cin >> arcos;
        for (int k = 0; k < arcos; k++) {
            int u, v, peso;
            cout << "Arco " << k + 1 << " (origen, destino y peso): ";
            cin >> u >> v >> peso;
            if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
                matriz[u][v] = peso;
            }
        }
        return 1;
    }

    int mostrar() {
        cout << "\nMatriz del digrafo (POO)" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matriz[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nGrados de los vertices" << endl;
        for (int i = 0; i < vertices; i++) {
            int entrada = 0, salida = 0;
            for (int j = 0; j < vertices; j++) {
                if (matriz[i][j] != 0) salida++;
                if (matriz[j][i] != 0) entrada++;
            }
            cout << "Vertice " << i << " -> grado salida: " << salida << " | grado entrada: " << entrada << endl;
        }
        return 1;
    }
};

int main() {
    digrafo dg;
    dg.inicializar();
    dg.capturararcos();
    dg.mostrar();
    return 0;
}