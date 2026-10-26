#include <iostream>
using namespace std;

class calculadora {
public:
    int sumar(int a, int b) { return a + b; }
    int restar(int a, int b) { return a - b; }
};

class calculadorarecursiva : public calculadora {
public:
    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    int fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    int mulpositivos(int a, int b) {
        if (b == 0) return 0;
        return sumar(a, mulpositivos(a, b - 1));
    }

    int multiplicar(int a, int b) {
        int posa = (a < 0) ? -a : a;
        int posb = (b < 0) ? -b : b;
        int res = mulpositivos(posa, posb);
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            return -res;
        }
        return res;
    }

    int divpositivos(int a, int b) {
        if (a < b) return 0;
        return sumar(1, divpositivos(restar(a, b), b));
    }

    int dividir(int a, int b) {
        if (b == 0) return 0;
        int posa = (a < 0) ? -a : a;
        int posb = (b < 0) ? -b : b;
        int res = divpositivos(posa, posb);
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            return -res;
        }
        return res;
    }

    int potpositiva(int a, int b) {
        if (b == 0) return 1;
        return multiplicar(a, potpositiva(a, b - 1));
    }

    float potencia(int a, int b) {
        int exp = (b < 0) ? -b : b;
        int res = potpositiva(a, exp);
        if (b < 0) {
            return (res != 0) ? (1.0f / res) : 0;
        }
        return res;
    }
};

int main() {
    calculadorarecursiva calc;
    int n, a, b;

    cout << "Ingresa un numero entero positivo: ";
    cin >> n;
    cout << "Factorial de " << n << ": " << calc.factorial(n) << endl;
    cout << "Serie Fibonacci hasta " << n << ": ";
    for (int i = 0; i <= n; i++) {
        cout << calc.fibonacci(i) << " ";
    }
    cout << endl;

    cout << "\nIngresa el primer numero para la calculadora recursiva (positivo o negativo): ";
    cin >> a;
    cout << "Ingresa el segundo numero para la calculadora recursiva (positivo o negativo): ";
    cin >> b;

    cout << "Multiplicacion recursiva: " << calc.multiplicar(a, b) << endl;
    if (b != 0) {
        cout << "Division recursiva: " << calc.dividir(a, b) << endl;
    } else {
        cout << "Division recursiva: No se puede dividir entre 0" << endl;
    }
    cout << "Potencia recursiva: " << calc.potencia(a, b) << endl;

    return 0;
}