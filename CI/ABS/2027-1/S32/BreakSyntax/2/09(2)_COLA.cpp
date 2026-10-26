#include <iostream>
#include <queue>
using namespace std;

class manejocolaIDE {
public:
    queue<int> micola;

    int ejecutar() {
        int n, dato, op = 0;
        cout << "Cuantos elementos deseas encolar inicialmente?: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Ingresa el elemento " << i + 1 << ": ";
            cin >> dato;
            micola.push(dato);
        }

        while (op != 4) {
            cout << "\n1. Encolar (push)\n2. Desencolar (pop)\n3. Mostrar Cola\n4. Salir\nOpcion: ";
            cin >> op;
            if (op == 1) {
                cout << "Ingresa el valor: ";
                cin >> dato;
                micola.push(dato);
            } else if (op == 2) {
                if (!micola.empty()) {
                    cout << "Se atendio al elemento: " << micola.front() << endl;
                    micola.pop();
                } else {
                    cout << "La cola esta vacia." << endl;
                }
            } else if (op == 3) {
                queue<int> copia = micola;
                cout << "Elementos en la cola: ";
                while (!copia.empty()) {
                    cout << copia.front() << " ";
                    copia.pop();
                }
                cout << endl;
            }
        }
        return 1;
    }
};

int main() {
    manejocolaIDE app;
    app.ejecutar();
    return 0;
}