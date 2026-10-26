#include <iostream>
using namespace std;

class operacion {
public:
    int sumar(int a, int b) {
        return a + b;
    }
};

int main() {
    operacion op;
    int n1, n2;
    cout << "Ingresa el primer numero: ";
    cin >> n1;
    cout << "Ingresa el segundo numero: ";
    cin >> n2;
    cout << "El resultado de la suma es: " << op.sumar(n1, n2) << endl;
    return 0;
}