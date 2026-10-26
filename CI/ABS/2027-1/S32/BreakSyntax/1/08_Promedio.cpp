#include <iostream>
using namespace std;

class estadistica {
public:
    int calcular() {
        float n1, n2, n3, n4, n5;
        cout << "Ingresa el numero 1: ";
        cin >> n1;
        cout << "Ingresa el numero 2: ";
        cin >> n2;
        cout << "Ingresa el numero 3: ";
        cin >> n3;
        cout << "Ingresa el numero 4: ";
        cin >> n4;
        cout << "Ingresa el numero 5: ";
        cin >> n5;

        float suma = n1 + n2 + n3 + n4 + n5;
        float promedio = suma / 5.0f;

        float maximo = n1;
        if (n2 > maximo) maximo = n2;
        if (n3 > maximo) maximo = n3;
        if (n4 > maximo) maximo = n4;
        if (n5 > maximo) maximo = n5;

        float minimo = n1;
        if (n2 < minimo) minimo = n2;
        if (n3 < minimo) minimo = n3;
        if (n4 < minimo) minimo = n4;
        if (n5 < minimo) minimo = n5;

        cout << "\nSuma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media: " << promedio << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
        return 1;
    }
};

int main() {
    estadistica est;
    est.calcular();
    return 0;
}