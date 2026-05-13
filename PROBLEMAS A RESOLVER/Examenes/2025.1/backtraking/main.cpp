#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool comprobamosvisitado(int visitado[], int numero) {
    int data = 0;

    for (int i = 0; i < 5; i++) {
        int visit = visitado[i];
        if (numero == visit) {
            return false;
        }
        if (visit == -1) {
            return false;
        }
    }
    return true;
}

bool comprobamos(int visitado[], int ruta[]) {
    for (int i = 0; i < 6; i++) {
        int numero = visitado[i];
        int numero2 = ruta[i];
        if (numero == -1 || numero2 == -1) {
            return false;
        }
    }
    return true;
}


void backtraking(int ruta[], int visitado[], double matriz[6][6], double &minimo, int posicion,int mejoropcion[]) {
    if (posicion == 6) {
        if (comprobamos(visitado, ruta)) {
            double  info=0;
            for (int i = 0; i < 6; i++) {
                if (i>0) {
                    info=info+matriz[ruta[i-1]][ruta[i]];
                }
            }
            info=info+matriz[ruta[5]][0];
            if (info<minimo) {
                for (int j=0;j<6;j++) {
                    cout << ruta[j] << " ";
                }
                minimo = info;
                cout << "el minimo es: "<<minimo<<endl;
            }

        } else {
            return;
        }
    }

    for (int i = 1; i <= 5; i++) {
        if (visitado[i]==0) {
            int borrador = ruta[i];
            ruta[posicion] = i;
            visitado[i] = 1;
            backtraking(ruta, visitado, matriz, minimo, posicion + 1,mejoropcion);
            visitado[i] = 0;
            ruta[posicion] = -1;
        }


    }

}

int main() {
    double matriz[6][6] = {
        {0.00, 2.24, 2.69, 4.00, 2.06, 3.35},
        {2.24, 0.00, 4.50, 5.39, 1.50, 5.59},
        {2.69, 4.50, 0.00, 5.59, 4.74, 2.55},
        {4.00, 5.39, 5.59, 0.00, 4.03, 3.91},
        {2.06, 1.50, 4.74, 4.03, 0.00, 5.10},
        {3.35, 5.59, 2.55, 3.91, 5.10, 0.00}
    };

    int ruta[6];
    int visitados[6];
    int mejoropcion[6];

    for (int i = 0; i < 6; i++) {
        ruta[i] = -1;
        visitados[i] = 0;
        mejoropcion[i] = 0;
    }

    ruta[0] = 0;

    visitados[0] = 1;

    double minimaruta=9999;

    backtraking(ruta, visitados, matriz, minimaruta, 1,mejoropcion);


    return 0;
}
