#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool contadordeunos(int arreglo[], int numero) {
    int data = 0;
    for (int i = 0; i < numero * 2; i++) {
        if (arreglo[i] == 1) {
            data++;
        }
    }
    if (data == numero && arreglo[0] == 1 && arreglo[numero * 2 - 1] == 0) {
        return true;
    } else {
        return false;
    }
}

bool balanceado(int arreglo[], int numero) {
    int contador = 0;
    for (int i = 0; i < numero * 2; i++) {
        if (arreglo[i] == 1) {
            contador++;
        } else {
            contador--;
        }

        if (contador < 0) {
            return false;
        }
    }
    return true;
}


void imprimir(int arreglo[], int numero) {
    for (int i = 0; i < numero * 2; i++) {
        if (arreglo[i] == 1) {
            cout << "(";
        } else {
            cout << ")";
        }
    }
    cout << endl;
}


void backtraking(int numero, int arreglo[], int posicion) {
    if (posicion > numero * 2) {
        return;
    }

    if (posicion == numero * 2) {
        if (contadordeunos(arreglo, numero) && balanceado(arreglo, numero)) {
            imprimir(arreglo, numero);
        }
        return;
    }

    // for (int i=posicion;i<numero*2;i++) {
    int borrador = arreglo[posicion];
    arreglo[posicion] = 0;
    backtraking(numero, arreglo, posicion + 1);
    //
    arreglo[posicion] = 1;
    backtraking(numero, arreglo, posicion + 1);
    //}
}

int main() {
    int numero = 3;
    int arreglo[numero * 2];
    for (int i = 0; i < numero * 2; i++) {
        arreglo[i]=0;

    }
    int posicion = 0;

    backtraking(numero, arreglo, posicion);

    return 0;
}
