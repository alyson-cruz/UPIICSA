#include <iostream>
using namespace std;

class estadisticarreglo {
public:
    int procesar() {
        float nums[5];
        float suma = 0;

        for (int i = 0; i < 5; i++) {
            cout << "Ingresa el numero " << (i + 1) << ": ";
            cin >> nums[i];
            suma = suma + nums[i];
        }

        float maximo = nums[0];
        float minimo = nums[0];

        for (int i = 1; i < 5; i++) {
            if (nums[i] > maximo) maximo = nums[i];
            if (nums[i] < minimo) minimo = nums[i];
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    float temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }

        float promedio = suma / 5.0f;

        cout << "\nSuma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media: " << nums[2] << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
        return 1;
    }
};

int main() {
    estadisticarreglo app;
    app.procesar();
    return 0;
}