#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class quicksortPOO {
public:
    char letras[50];
    int numeros[50];
    persona lista[50];

    int ordenarchar(int inicio, int fin) {
        int i = inicio, j = fin;
        char pivote = letras[(inicio + fin) / 2];
        while (i <= j) {
            while (letras[i] < pivote) i++;
            while (letras[j] > pivote) j--;
            if (i <= j) {
                char aux = letras[i];
                letras[i] = letras[j];
                letras[j] = aux;
                i++;
                j--;
            }
        }
        if (inicio < j) ordenarchar(inicio, j);
        if (i < fin) ordenarchar(i, fin);
        return 1;
    }

    int ordenarint(int inicio, int fin) {
        int i = inicio, j = fin;
        int pivote = numeros[(inicio + fin) / 2];
        while (i <= j) {
            while (numeros[i] < pivote) i++;
            while (numeros[j] > pivote) j--;
            if (i <= j) {
                int aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
                i++;
                j--;
            }
        }
        if (inicio < j) ordenarint(inicio, j);
        if (i < fin) ordenarint(i, fin);
        return 1;
    }

    int ordenarpersona(int inicio, int fin) {
        int i = inicio, j = fin;
        int pivote = lista[(inicio + fin) / 2].edad;
        while (i <= j) {
            while (lista[i].edad < pivote) i++;
            while (lista[j].edad > pivote) j--;
            if (i <= j) {
                persona aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
                i++;
                j--;
            }
        }
        if (inicio < j) ordenarpersona(inicio, j);
        if (i < fin) ordenarpersona(i, fin);
        return 1;
    }
};

int main() {
    quicksortPOO obj;
    int n;
    cout << "Cuantos elementos deseas ordenar?: ";
    cin >> n;

    cout << "\nIngresa caracteres" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Caracter " << i + 1 << ": ";
        cin >> obj.letras[i];
    }

    cout << "\nIngresa enteros" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> obj.numeros[i];
    }

    cout << "\nIngresa personas" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre " << i + 1 << ": ";
        cin >> obj.lista[i].nombre;
        cout << "Edad " << i + 1 << ": ";
        cin >> obj.lista[i].edad;
    }

    obj.ordenarchar(0, n - 1);
    obj.ordenarint(0, n - 1);
    obj.ordenarpersona(0, n - 1);

    cout << "\nCaracteres ordenados: ";
    for (int i = 0; i < n; i++) cout << obj.letras[i] << " ";

    cout << "\nEnteros ordenados: ";
    for (int i = 0; i < n; i++) cout << obj.numeros[i] << " ";

    cout << "\nPersonas ordenadas por edad:" << endl;
    for (int i = 0; i < n; i++) {
        cout << obj.lista[i].nombre << " (" << obj.lista[i].edad << " años)" << endl;
    }

    return 0;
}