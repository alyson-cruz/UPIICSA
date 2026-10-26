#include <iostream>
using namespace std;

class calculadora {
public:
    int sumar() {
        int a, b;
        cout << "Ingresa dos numeros para sumar: ";
        cin >> a >> b;
        return a + b;
    }
    int restar() {
        int a, b;
        cout << "Ingresa dos numeros para restar: ";
        cin >> a >> b;
        return a - b;
    }
    int multiplicar() {
        int a, b;
        cout << "Ingresa dos numeros para multiplicar: ";
        cin >> a >> b;
        return a * b;
    }
    float dividir() {
        float a, b;
        cout << "Ingresa dos numeros para dividir: ";
        cin >> a >> b;
        return (b != 0) ? (a / b) : 0;
    }

    int sumar(int a, int b) { return a + b; }
    int restar(int a, int b) { return a - b; }
    int multiplicar(int a, int b) { return a * b; }
    float dividir(float a, float b) { return (b != 0) ? (a / b) : 0; }

    int sumar(int a, int b, int c) { return a + b + c; }
    int restar(int a, int b, int c) { return a - b - c; }
    int multiplicar(int a, int b, int c) { return a * b * c; }
    float dividir(float a, float b, float c) {
        return (b != 0 && c != 0) ? (a / b / c) : 0;
    }
};

int main() {
    calculadora calc;
    int x, y, z;

    cout << "Prueba con 0 parametros" << endl;
    cout << "Resultado suma: " << calc.sumar() << endl;

    cout << "\nPrueba con 2 parametros" << endl;
    cout << "Ingresa 2 numeros: ";
    cin >> x >> y;
    cout << "Suma: " << calc.sumar(x, y) << endl;
    cout << "Resta: " << calc.restar(x, y) << endl;
    cout << "Multiplicacion: " << calc.multiplicar(x, y) << endl;
    cout << "Division: " << calc.dividir(x, y) << endl;

    cout << "\nPrueba con 3 parametros" << endl;
    cout << "Ingresa 3 numeros: ";
    cin >> x >> y >> z;
    cout << "Suma: " << calc.sumar(x, y, z) << endl;
    cout << "Resta: " << calc.restar(x, y, z) << endl;
    cout << "Multiplicacion: " << calc.multiplicar(x, y, z) << endl;
    cout << "Division: " << calc.dividir(x, y, z) << endl;

    return 0;
}