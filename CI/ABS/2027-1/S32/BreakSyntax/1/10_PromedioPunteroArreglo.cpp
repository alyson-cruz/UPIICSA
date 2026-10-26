#include <iostream>
using namespace std;

class estadisticapuntero {
public:
    int procesar() {
        float nums[5];
        float *p = nums;
        float suma = 0;

        for (int i = 0; i < 5; i++) {
            cout << "Ingresa el numero " << (i + 1) << ": ";
            cin >> *(p + i);
            suma = suma + *(p + i);
        }

        float maximo = *p;
        float minimo = *p;

        for (int i = 1; i < 5; i++) {
            if (*(p + i) > maximo) maximo = *(p + i);
            if (*(p + i) < minimo) minimo = *(p + i);
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 - i; j++) {
                if (*(p + j) > *(p + j + 1)) {
                    float temp = *(p + j);
                    *(p + j) = *(p + j + 1);
                    *(p + j + 1) = temp;
                }
            }
        }

        float promedio = suma / 5.0f;

        cout << "\nSuma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media: " << *(p + 2) << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
        return 1;
    }
};

int main() {
    estadisticapuntero app;
    app.procesar();
    return 0;
}