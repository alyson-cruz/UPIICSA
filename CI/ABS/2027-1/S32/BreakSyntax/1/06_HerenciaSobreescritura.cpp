#include <iostream>
using namespace std;

class calculadora {
public:
    int sumar(int a, int b) { return a + b; }
    int restar(int a, int b) { return a - b; }
    int multiplicar(int a, int b) { return a * b; }
    int dividir(int a, int b) { return (b != 0) ? (a / b) : 0; }
};

class calculadoranueva : public calculadora {
public:
    int multiplicar(int a, int b) {
        int resultado = 0;
        int posa = (a < 0) ? -a : a;
        int posb = (b < 0) ? -b : b;

        for (int i = 0; i < posb; i++) {
            resultado = sumar(resultado, posa);
        }

        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            return -resultado;
        }
        return resultado;
    }

    int dividir(int a, int b) {
        if (b == 0) {
            return 0;
        }
        int cociente = 0;
        int posa = (a < 0) ? -a : a;
        int posb = (b < 0) ? -b : b;

        while (posa >= posb) {
            posa = restar(posa, posb);
            cociente = sumar(cociente, 1);
        }

        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            return -cociente;
        }
        return cociente;
    }

    float potencia(int a, int b) {
        int exp = (b < 0) ? -b : b;
        int resultado = 1;

        for (int i = 0; i < exp; i++) {
            resultado = multiplicar(resultado, a);
        }

        if (b < 0) {
            return (resultado != 0) ? (1.0f / resultado) : 0;
        }
        return resultado;
    }
};

int main() {
    calculadoranueva calc;
    int a, b;
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "Multiplicacion: " << calc.multiplicar(a, b) << endl;
    if (b != 0) {
        cout << "Division: " << calc.dividir(a, b) << endl;
    } else {
        cout << "Division: No se puede dividir entre 0" << endl;
    }
    cout << "Potencia: " << calc.potencia(a, b) << endl;

    return 0;
}