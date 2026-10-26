#include <iostream>
#include <string>
using namespace std;

class Mensaje {
public:
    int saludar(string nombre) {
        cout << "Hola mundo, bienvenido " << nombre << endl;
        return 1;
    }
};

int main() {
    Mensaje m;
    string usuario;
    cout << "Ingresa tu nombre para mostrar el saludo: ";
    cin >> usuario;
    m.saludar(usuario);
    return 0;
}
