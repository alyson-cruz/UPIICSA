#include <iostream>
#include <string>
using namespace std;

struct persona {
    string nombre;
    int edad;
};

int quicksortchar(char arr[], int inicio, int fin) {
    int i = inicio, j = fin;
    char pivote = arr[(inicio + fin) / 2];
    while (i <= j) {
        while (arr[i] < pivote) i++;
        while (arr[j] > pivote) j--;
        if (i <= j) {
            char aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }
    if (inicio < j) quicksortchar(arr, inicio, j);
    if (i < fin) quicksortchar(arr, i, fin);
    return 1;
}

int quicksortint(int arr[], int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = arr[(inicio + fin) / 2];
    while (i <= j) {
        while (arr[i] < pivote) i++;
        while (arr[j] > pivote) j--;
        if (i <= j) {
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }
    if (inicio < j) quicksortint(arr, inicio, j);
    if (i < fin) quicksortint(arr, i, fin);
    return 1;
}

int quicksortpersona(persona arr[], int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = arr[(inicio + fin) / 2].edad;
    while (i <= j) {
        while (arr[i].edad < pivote) i++;
        while (arr[j].edad > pivote) j--;
        if (i <= j) {
            persona aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }
    if (inicio < j) quicksortpersona(arr, inicio, j);
    if (i < fin) quicksortpersona(arr, i, fin);
    return 1;
}

int main() {
    int n;
    cout << "Cuantos elementos deseas ordenar?: ";
    cin >> n;

    char letras[50];
    int numeros[50];
    persona lista[50];

    cout << "\nIngresa caracteres" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Caracter " << i + 1 << ": ";
        cin >> letras[i];
    }

    cout << "\nIngresa enteros" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "\nIngresa personas" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Edad " << i + 1 << ": ";
        cin >> lista[i].edad;
    }

    quicksortchar(letras, 0, n - 1);
    quicksortint(numeros, 0, n - 1);
    quicksortpersona(lista, 0, n - 1);

    cout << "\nCaracteres ordenados: ";
    for (int i = 0; i < n; i++) cout << letras[i] << " ";

    cout << "\nEnteros ordenados: ";
    for (int i = 0; i < n; i++) cout << numeros[i] << " ";

    cout << "\nPersonas ordenadas por edad:" << endl;
    for (int i = 0; i < n; i++) {
        cout << lista[i].nombre << " (" << lista[i].edad << " años)" << endl;
    }

    return 0;
}