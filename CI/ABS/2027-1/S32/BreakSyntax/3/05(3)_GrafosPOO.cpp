#include <iostream>
using namespace std;

class grafo {
public:
    int matriz[50][50];
    int numvertices;
    int numaristas;

    int inicializar() {
        cout << "Ingresa el numero de vertices del grafo: ";
        cin >> numvertices;
        for (int i = 0; i < numvertices; i++) {
            for (int j = 0; j < numvertices; j++) {
                matriz[i][j] = 0;
            }
        }
        return 1;
    }

    int capturararistas() {
        cout << "Ingresa el numero de aristas: ";
        cin >> numaristas;
        for (int k = 0; k < numaristas; k++) {
            int u, v;
            cout << "Arista " << k + 1 << " (origen y destino de 0 a " << numvertices - 1 << "): ";
            cin >> u >> v;
            if (u >= 0 && u < numvertices && v >= 0 && v < numvertices) {
                matriz[u][v] = 1;
                matriz[v][u] = 1;
            }
        }
        return 1;
    }

    int mostrarmatriz() {
        cout << "\nMatriz de adyacencia" << endl;
        for (int i = 0; i < numvertices; i++) {
            for (int j = 0; j < numvertices; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        return 1;
    }

    int recorridoBFS(int inicio) {
        int visitado[50];
        int cola[50];
        int frente = 0, fin = 0;

        for (int i = 0; i < numvertices; i++) visitado[i] = 0;

        visitado[inicio] = 1;
        cola[fin++] = inicio;

        cout << "Recorrido BFS desde el vertice " << inicio << ": ";
        while (frente < fin) {
            int actual = cola[frente++];
            cout << actual << " ";
            for (int i = 0; i < numvertices; i++) {
                if (matriz[actual][i] == 1 && visitado[i] == 0) {
                    visitado[i] = 1;
                    cola[fin++] = i;
                }
            }
        }
        cout << endl;
        return 1;
    }
};

int main() {
    grafo migrafo;
    int inicial;
    migrafo.inicializar();
    migrafo.capturararistas();
    migrafo.mostrarmatriz();

    cout << "\nIngresa el vertice inicial para el recorrido BFS: ";
    cin >> inicial;
    migrafo.recorridoBFS(inicial);

    return 0;
}