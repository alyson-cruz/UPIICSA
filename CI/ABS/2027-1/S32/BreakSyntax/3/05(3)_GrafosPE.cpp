#include <iostream>
using namespace std;

struct grafo {
    int matriz[50][50];
    int numvertices;
    int numaristas;
};

int main() {
    grafo g;
    cout << "Ingresa el numero de vertices del grafo: ";
    cin >> g.numvertices;

    for (int i = 0; i < g.numvertices; i++) {
        for (int j = 0; j < g.numvertices; j++) {
            g.matriz[i][j] = 0;
        }
    }

    cout << "Ingresa el numero de aristas (conexiones): ";
    cin >> g.numaristas;

    for (int k = 0; k < g.numaristas; k++) {
        int u, v;
        cout << "Arista " << k + 1 << " - Ingresa vertice origen y destino (0 a " << g.numvertices - 1 << "): ";
        cin >> u >> v;
        if (u >= 0 && u < g.numvertices && v >= 0 && v < g.numvertices) {
            g.matriz[u][v] = 1;
            g.matriz[v][u] = 1; 
        }
    }

    cout << "\nMatriz de adyacencia del grafo" << endl;
    for (int i = 0; i < g.numvertices; i++) {
        for (int j = 0; j < g.numvertices; j++) {
            cout << g.matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}