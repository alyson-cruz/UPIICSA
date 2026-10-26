#include <iostream>
#include <string>
using namespace std;

class persona {
public:
    string nombre;
    int edad;
};

class mergeindirectoPOO {
public:
    char letras[50];
    int numeros[50];
    persona lista[50];

    int mergechar(char *p, int izq, int med, int der) {
        char temp[50];
        int i = izq, j = med + 1, k = izq;
        while (i <= med && j <= der) {
            if (*(p + i) <= *(p + j)) temp[k++] = *(p + i++);
            else temp[k++] = *(p + j++);
        }
        while (i <= med) temp[k++] = *(p + i++);
        while (j <= der) temp[k++] = *(p + j++);
        for (int m = izq; m <= der; m++) *(p + m) = temp[m];
        return 1;
    }

    int ordenarchar(char *p, int izq, int der) {
        if (izq < der) {
            int med = (izq + der) / 2;
            ordenarchar(p, izq, med);
            ordenarchar(p, med + 1, der);
            mergechar(p, izq, med, der);
        }
        return 1;
    }

    int mergeint(int *p, int izq, int med, int der) {
        int temp[50];
        int i = izq, j = med + 1, k = izq;
        while (i <= med && j <= der) {
            if (*(p + i) <= *(p + j)) temp[k++] = *(p + i++);
            else temp[k++] = *(p + j++);
        }
        while (i <= med) temp[k++] = *(p + i++);
        while (j <= der) temp[k++] = *(p + j++);
        for (int m = izq; m <= der; m++) *(p + m) = temp[m];
        return 1;
    }

    int ordenarint(int *p, int izq, int der) {
        if (izq < der) {
            int med = (izq + der) / 2;
            ordenarint(p, izq, med);
            ordenarint(p, med + 1, der);
            mergeint(p, izq, med, der);
        }
        return 1;
    }

    int mergepersona(persona *p, int izq, int med, int der) {
        persona temp[50];
        int i = izq, j = med + 1, k = izq;
        while (i <= med && j <= der) {
            if ((p + i)->edad <= (p + j)->edad) temp[k++] = *(p + i++);
            else temp[k++] = *(p + j++);
        }
        while (i <= med) temp[k++] = *(p + i++);
        while (j <= der) temp[k++] = *(p + j++);
        for (int m = izq; m <= der; m++) *(p + m) = temp[m];
        return 1;
    }

    int ordenarpersona(persona *p, int izq, int der) {
        if (izq < der) {
            int med = (izq + der) / 2;
            ordenarpersona(p, izq, med);
            ordenarpersona(p, med + 1, der);
            mergepersona(p, izq, med, der);
        }
        return 1;
    }
};

int main() {
    mergeindirectoPOO obj;
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
        cout << (pp + i)->nombre << " (" << (pp + i)->edad << " anios)" << endl;
    }

    return 0;
}