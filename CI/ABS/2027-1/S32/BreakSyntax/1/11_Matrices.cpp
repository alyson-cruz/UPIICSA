#include <iostream>
using namespace std;

class operacionesmatrices {
public:
    int ejecutar() {
        int fa, ca, fb, cb, k;

        cout << "Ingresa el numero de filas de la matriz A: ";
        cin >> fa;
        cout << "Ingresa el numero de columnas de la matriz A: ";
        cin >> ca;

        int A[50][50];
        cout << "Captura de la matriz A" << endl;
        for (int i = 0; i < fa; i++) {
            for (int j = 0; j < ca; j++) {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }
        }

        cout << "\nIngresa la constante para multiplicar por A: ";
        cin >> k;

        cout << "\nResultado de A * " << k << ":" << endl;
        for (int i = 0; i < fa; i++) {
            for (int j = 0; j < ca; j++) {
                cout << (A[i][j] * k) << "\t";
            }
            cout << endl;
        }

        cout << "\nIngresa el numero de filas de la matriz B: ";
        cin >> fb;
        cout << "Ingresa el numero de columnas de la matriz B: ";
        cin >> cb;

        if (ca != fb) {
            cout << "No se puede multiplicar A * B porque las columnas de A deben ser iguales a las filas de B." << endl;
            return 0;
        }

        int B[50][50];
        int C[50][50];

        cout << " Captura de la matriz B" << endl;
        for (int i = 0; i < fb; i++) {
            for (int j = 0; j < cb; j++) {
                cout << "B[" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }
        }

        for (int i = 0; i < fa; i++) {
            for (int j = 0; j < cb; j++) {
                C[i][j] = 0;
                for (int m = 0; m < ca; m++) {
                    C[i][j] = C[i][j] + (A[i][m] * B[m][j]);
                }
            }
        }

        cout << "\nResultado de A * B:" << endl;
        for (int i = 0; i < fa; i++) {
            for (int j = 0; j < cb; j++) {
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }

        return 1;
    }
};

int main() {
    operacionesmatrices mat;
    mat.ejecutar();
    return 0;
}