#include <iostream>
#include <iomanip>
using namespace std;

bool analisis(int matriz[9][9], int posicion,int arreglo[], int etiqueta, int N) {
    for (int i=0; i<N; i++) {
        if (i!=posicion) {
            if (matriz[posicion][i]>0 || matriz[posicion][i] > 0) {
                if (arreglo[i]==etiqueta) {
                    return false;
                }


            }
        }


    }
    return true;
}

bool backtracking(int matriz[9][9], int arreglo[], int N, int posicion) {
    if (posicion == N) {
        for (int i=0; i<N; i++) {
            cout << arreglo[i] << " ";
        }
        return true;
    }

    for (int i = 1; i < N; i++) {
        if (analisis(matriz,posicion,arreglo,i,N)) {
            arreglo[posicion] = i;
            if (backtracking(matriz,arreglo,N,posicion+1)) {
                return true;
            }
            arreglo[posicion] = 0;
        }




    }

    return false;
}


int main() {
    int matriz[9][9] = {
        {1, 2, 0, 6, 0, 0, 0, 0, 2},
        {7, 1, 5, 2, 0, 0, 0, 0, 7},
        {0, 3, 1, 2, 3, 8, 9, 7, 5},
        {2, 7, 5, 1, 2, 0, 0, 0, 0},
        {0, 0, 5, 3, 1, 4, 0, 0, 0},
        {0, 0, 9, 0, 6, 1, 2, 0, 0},
        {0, 0, 3, 0, 0, 7, 1, 4, 0},
        {0, 0, 4, 0, 0, 0, 9, 1, 9},
        {5, 3, 6, 0, 0, 0, 0, 4, 1}
    };


    int N = 9;
    int arreglo[N];
    for (int i = 0; i < N; i++) {
        arreglo[i] = 0;
    }
    arreglo[0] = 1;

    backtracking(matriz,arreglo,N,1);


    return 0;
}
