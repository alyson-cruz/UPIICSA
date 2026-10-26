#include <iostream>
#include <string>
using namespace std;

struct persona {
    string nombre;
    int edad;
};

int mergechar(char arr[], int izq, int med, int der) {
    char temp[50];
    int i = izq, j = med + 1, k = izq;
    while (i <= med && j <= der) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= med) temp[k++] = arr[i++];
    while (j <= der) temp[k++] = arr[j++];
    for (int m = izq; m <= der; m++) arr[m] = temp[m];
    return 1;
}

int mergesortchar(char arr[], int izq, int der) {
    if (izq < der) {
        int med = (izq + der) / 2;
        mergesortchar(arr, izq, med);
        mergesortchar(arr, med + 1, der);
        mergechar(arr, izq, med, der);
    }
    return 1;
}

int mergeint(int arr[], int izq, int med, int der) {
    int temp[50];
    int i = izq, j = med + 1, k = izq;
    while (i <= med && j <= der) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= med) temp[k++] = arr[i++];
    while (j <= der) temp[k++] = arr[j++];
    for (int m = izq; m <= der; m++) arr[m] = temp[m];
    return 1;
}

int mergesortint(int arr[], int izq, int der) {
    if (izq < der) {
        int med = (izq + der) / 2;
        mergesortint(arr, izq, med);
        mergesortint(arr, med + 1, der);
        mergeint(arr, izq, med, der);
    }
    return 1;
}

int mergepersona(persona arr[], int izq, int med, int der) {
    persona temp[50];
    int i = izq, j = med + 1, k = izq;
    while (i <= med && j <= der) {
        if (arr[i].edad <= arr[j].edad) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= med) temp[k++] = arr[i++];
    while (j <= der) temp[k++] = arr[j++];
    for (int m = izq; m <= der; m++) arr[m] = temp[m];
    return 1;
}

int mergesortpersona(persona arr[], int izq, int der) {
    if (izq < der) {
        int med = (izq + der) / 2;
        mergesortpersona(arr, izq, med);
        mergesortpersona(arr, med + 1, der);
        mergepersona(arr, izq, med, der);
    }
    return 1;
}

int main() {
    int n;
    cout << "Ingresa la cantidad de elementos a ordenar: ";
    cin >> n;

    char letras[50];
    int numeros[50];
    persona lista[50];

    cout << "\nCaptura de caracteres" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Caracter " << i + 1 << ": ";
        cin >> letras[i];
    }

    cout << "\nCaptura de enteros" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << "\nCaptura de personas" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Edad " << i + 1 << ": ";
        cin >> lista[i].edad;
    }

    mergesortchar(letras, 0, n - 1);
    mergesortint(numeros, 0, n - 1);
    mergesortpersona(lista, 0, n - 1);

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