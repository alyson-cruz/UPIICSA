#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class quickindirectoPOO {
public:
    char letras[50];
    int numeros[50];
    persona lista[50];

    int ordenarchar(char *p, int inicio, int fin) {
        int i = inicio, j = fin;
        char pivote = *(p + (inicio + fin) / 2);
        while (i <= j) {
            while (*(p + i) < pivote) i++;
            while (*(p + j) > pivote) j--;
            if (i <= j) {
                char aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
                i++;
                j--;
            }
        }
        if (inicio < j) ordenarchar(p, inicio, j);
        if (i < fin) ordenarchar(p, i, fin);
        return 1;
    }

    int ordenarint(int *p, int inicio, int fin) {
        int i = inicio, j = fin;
        int pivote = *(p + (inicio + fin) / 2);
        while (i <= j) {
            while (*(p + i) < pivote) i++;
            while (*(p + j) > pivote) j--;
            if (i <= j) {
                int aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
                i++;
                j--;
            }
        }
        if (inicio < j) ordenarint(p, inicio, j);
        if (i < fin) ordenarint(p, i, fin);
        return 1;
    }

    int ordenarpersona(persona *p, int inicio, int fin) {
        int i = inicio, j = fin;
        int pivote = (p + (inicio + fin) / 2)->edad;
        while (i <= j) {
            while ((p + i)->edad < pivote) i++;
            while ((p + j)->edad > pivote) j--;
            if (i <= j) {
                persona aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
                i++;
                j--;
            }
        }
        if (inicio < j) ordenarpersona(p, inicio, j);
        if (i < fin) ordenarpersona(p, i, fin);
        return 1;
    }
};

int main() {
    quickindirectoPOO obj;
    int n;
    cout << "Cuantos elementos deseas ordenar?: ";
    cin >> n;

    char *pl = obj.letras;
    int *pn = obj.numeros;
    persona *pp = obj.lista;

    cout << "\nIngresa caracteres" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Caracter " << i + 1 << ": ";
        cin >> *(pl + i);
    }

    cout << "\nIngresa enteros" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> *(pn + i);
    }

    cout << "\nIngresa personas" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre " << i + 1 << ": ";
        cin >> (pp + i)->nombre;
        cout << "Edad " << i + 1 << ": ";
        cin >> (pp + i)->edad;
    }

    obj.ordenarchar(pl, 0, n - 1);
    obj.ordenarint(pn, 0, n - 1);
    obj.ordenarpersona(pp, 0, n - 1);

    cout << "\nCaracteres ordenados: ";
    for (int i = 0; i < n; i++) cout << *(pl + i) << " ";

    cout << "\nEnteros ordenados: ";
    for (int i = 0; i < n; i++) cout << *(pn + i) << " ";

    cout << "\nPersonas ordenadas por edad:" << endl;
    for (int i = 0; i < n; i++) {
        cout << (pp + i)->nombre << " (" << (pp + i)->edad << " años)" << endl;
    }

    return 0;
}