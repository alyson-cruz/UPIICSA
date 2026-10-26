#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class mergesortPOO {
public:
    char letras[50];
    int numeros[50];
    persona lista[50];

    int mergechar(int izq, int med, int der) {
        char temp[50];
        int i = izq, j = med + 1, k = izq;
        while (i <= med && j <= der) {
            if (letras[i] <= letras[j]) temp[k++] = letras[i++];
            else temp[k++] = letras[j++];
        }
        while (i <= med) temp[k++] = letras[i++];
        while (j <= der) temp[k++] = letras[j++];
        for (int m = izq; m <= der; m++) letras[m] = temp[m];
        return 1;
    }

    int ordenarchar(int izq, int der) {
        if (izq < der) {
            int med = (izq + der) / 2;
            ordenarchar(izq, med);
            ordenarchar(med + 1, der);
            mergechar(izq, med, der);
        }
        return 1;
    }

    int mergeint(int izq, int med, int der) {
        int temp[50];
        int i = izq, j = med + 1, k = izq;
        while (i <= med && j <= der) {
            if (numeros[i] <= numeros[j]) temp[k++] = numeros[i++];
            else temp[k++] = numeros[j++];
        }
        while (i <= med) temp[k++] = numeros[i++];
        while (j <= der) temp[k++] = numeros[j++];
        for (int m = izq; m <= der; m++) numeros[m] = temp[m];
        return 1;
    }

    int ordenarint(int izq, int der) {
        if (izq < der) {
            int med = (izq + der) / 2;
            ordenarint(izq, med);
            ordenarint(med + 1, der);
            mergeint(izq, med, der);
        }
        return 1;
    }

    int mergepersona(int izq, int med, int der) {
        persona temp[50];
        int i = izq, j = med + 1, k = izq;
        while (i <= med && j <= der) {
            if (lista[i].edad <= lista[j].edad) temp[k++] = lista[i++];
            else temp[k++] = lista[j++];
        }
        while (i <= med) temp[k++] = lista[i++];
        while (j <= der) temp[k++] = lista[j++];
        for (int m = izq; m <= der; m++) lista[m] = temp[m];
        return 1;
    }

    int ordenarpersona(int izq, int der) {
        if (izq < der) {
            int med = (izq + der) / 2;
            ordenarpersona(izq, med);
            ordenarpersona(med + 1, der);
            mergepersona(izq, med, der);
        }
        return 1;
    }
};

int main() {
    mergesortPOO obj;
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