#include <iostream>
using namespace std;

struct digrafo {
    int matriz[50][50];
    int vertices;
    int arcos;
};

int main() {
    digrafo d;
    cout << "Ingresa la cantidad de vertices del digrafo: ";
    cin >> d.vertices;

    for (int i = 0; i < d.vertices; i++) {
        for (int j = 0; j < d.vertices; j++) {
            d.matriz[i][j] = 0;
        }
    }

    cout << "Ingresa la cantidad de arcos dirigidos: ";
    cin >> d.arcos;

    for (int k = 0; k < d.arcos; k++) {
        int origen, destino, peso;
        cout << "Arco " << k + 1 << " -> origen, destino y peso: ";
        cin >> origen >> destino >> peso;
        if (origen >= 0 && origen < d.vertices && destino >= 0 && destino < d.vertices) {
            d.matriz[origen][destino] = peso;
        }
    }

    cout << "\nMatriz de adyacencia del digrafo" << endl;
    for (int i = 0; i < d.vertices; i++) {
        for (int j = 0; j < d.vertices; j++) {
            cout << d.matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}