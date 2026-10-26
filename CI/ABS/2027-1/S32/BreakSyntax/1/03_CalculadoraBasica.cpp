#include <iostream>
using namespace std;

class calculadora {
public:
    int sumar(int a, int b) { return a + b; }
    int restar(int a, int b) { return a - b; }
    int multiplicar(int a, int b) { return a * b; }
    float dividir(float a, float b) { return (b != 0) ? (a / b) : 0; }
};

int main() {
    calculadora calc;
    int a, b;
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "Suma: " << calc.sumar(a, b) << endl;
    cout << "Resta: " << calc.restar(a, b) << endl;
    cout << "Multiplicacion: " << calc.multiplicar(a, b) << endl;
    if (b != 0) {
        cout << "Division: " << calc.dividir(a, b) << endl;
    } else {
        cout << "Division: No se puede dividir entre cero" << endl;
    }
    return 0;
}