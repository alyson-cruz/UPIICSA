#include <iostream>
#include <stack>
using namespace std;

class manejopilaIDE {
public:
    stack<int> mipila;

    int ejecutar() {
        int n, dato, op = 0;
        cout << "Cuantos elementos deseas apilar inicialmente?: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Ingresa el elemento " << i + 1 << ": ";
            cin >> dato;
            mipila.push(dato);
        }

        while (op != 4) {
            cout << "\n1. Agregar (push)\n2. Quitar (pop)\n3. Mostrar Pila\n4. Salir\nOpcion: ";
            cin >> op;
            if (op == 1) {
                cout << "Ingresa el valor: ";
                cin >> dato;
                mipila.push(dato);
            } else if (op == 2) {
                if (!mipila.empty()) {
                    cout << "Se elimino el tope: " << mipila.top() << endl;
                    mipila.pop();
                } else {
                    cout << "La pila esta vacia." << endl;
                }
            } else if (op == 3) {
                stack<int> copia = mipila;
                cout << "Elementos en la pila: ";
                while (!copia.empty()) {
                    cout << copia.top() << " ";
                    copia.pop();
                }
                cout << endl;
            }
        }
        return 1;
    }
};

int main() {
    manejopilaIDE app;
    app.ejecutar();
    return 0;
}