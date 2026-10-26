#include <iostream>
#include <string>
using namespace std;

struct persona {
    string nombre;
    int edad;
};

int quicksortchar(char *p, int inicio, int fin) {
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
    if (inicio < j) quicksortchar(p, inicio, j);
    if (i < fin) quicksortchar(p, i, fin);
    return 1;
}

int quicksortint(int *p, int inicio, int fin) {
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
    if (inicio < j) quicksortint(p, inicio, j);
    if (i < fin) quicksortint(p, i, fin);
    return 1;
}

int quicksortpersona(persona *p, int inicio, int fin) {
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
    if (inicio < j) quicksortpersona(p, inicio, j);
    if (i < fin) quicksortpersona(p, i, fin);
    return 1;
}

int main() {
    int n;
    cout << "Cuantos elementos deseas ordenar?: ";
    cin >> n;

    char letras[50];
    int numeros[50];
    persona lista[50];

    char *pl = letras;
    int *pn = numeros;
    persona *pp = lista;

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

    quicksortchar(pl, 0, n - 1);
    quicksortint(pn, 0, n - 1);
    quicksortpersona(pp, 0, n - 1);

    cout << "\nCaracteres ordenados: ";
    for (int i = 0; i < n; i++) cout << *(pl + i) << " ";

    cout << "\nEnteros ordenados: ";
    for (int i = 0; i < n; i++) cout << *(pn + i) << " ";

    cout << "\nPersonas ordenadas por edad:" << endl;
    for (int i = 0; i < n; i++) {
        cout << (pp + i)->nombre << " (" << (pp + i)->edad << " anios)" << endl;
    }

    return 0;
}