#include <iostream>
#include <list>
using namespace std;

class manejolistaIDE {
public:
    list<int> milista;

    int ejecutar() {
        int n, dato, op = 0;
        cout << "Cuantos elementos deseas agregar a la lista inicialmente?: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Ingresa el elemento " << i + 1 << ": ";
            cin >> dato;
            milista.push_back(dato);
        }

        while (op != 4) {
            cout << "\n1. Insertar al final\n2. Eliminar valor\n3. Mostrar Lista\n4. Salir\nOpcion: ";
            cin >> op;
            if (op == 1) {
                cout << "Ingresa el valor: ";
                cin >> dato;
                milista.push_back(dato);
            } else if (op == 2) {
                cout << "Ingresa el valor a eliminar: ";
                cin >> dato;
                milista.remove(dato);
                cout << "Operacion realizada." << endl;
            } else if (op == 3) {
                cout << "Elementos en la lista: ";
                for (int elem : milista) {
                    cout << elem << " ";
                }
                cout << endl;
            }
        }
        return 1;
    }
};

int main() {
    manejolistaIDE app;
    app.ejecutar();
    return 0;
}