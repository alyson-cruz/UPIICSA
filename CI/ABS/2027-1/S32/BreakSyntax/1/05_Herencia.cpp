#include <iostream>
using namespace std;

class calculadora {
public:
    int sumar(int a, int b) { return a + b; }
    int restar(int a, int b) { return a - b; }
    int multiplicar(int a, int b) { return a * b; }
    float dividir(float a, float b) { return (b != 0) ? (a / b) : 0; }
};

class calculadoranueva : public calculadora {
public:
    int modulo(int a, int b) {
        return (b != 0) ? (a % b) : 0;
    }
};

int main() {
    calculadoranueva calc;
    int a, b;
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "Suma: " << calc.sumar(a, b) << endl;
    cout << "Resta: " << calc.restar(a, b) << endl;
    cout << "Multiplicacion: " << calc.multiplicar(a, b) << endl;
    cout << "Division: " << calc.dividir(a, b) << endl;
    cout << "Modulo: " << calc.modulo(a, b) << endl;

    return 0;
}