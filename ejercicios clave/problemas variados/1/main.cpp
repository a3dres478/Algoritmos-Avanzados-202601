#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

int movx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int movy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

using namespace std;

bool corroboracion(int N, int ubix, int ubiy, int **matriz) {
    if (ubix < 0 || ubiy < 0 || ubix >= N || ubiy >= N) {
        return false;
    }
    if (matriz[ubix][ubiy] != 0) {
        return false;
    }
    return true;
}

bool corroboracion2(int **matriz, int N) {
    int numero = N*(N*N+1)/2;
    // for (int i = 0; i < N; i++) {
    //     int borra = matriz[0][i];
    //     //numero = numero + borra;
    // }
    for (int i = 0; i < N; i++) {
        int num1 = 0;
        for (int j = 0; j < N; j++) {
            num1 = num1 + matriz[i][j];
        }
        if (num1 != numero) {
            return false;
        }
    }

    // Revisar columnas
    for (int j = 0; j < N; j++) {
        int sumaColumna = 0;

        for (int i = 0; i < N; i++) {
            sumaColumna += matriz[i][j];
        }

        if (sumaColumna != numero) {
            return false;
        }
    }


    return true;
}

bool backtraking(int **matriz, int N, int ubix, int ubiy, int posicion) {
    if (posicion == N * N + 1) {

        /* Imprimir toda la matriz sin necesidad de revisar todas las filas*/


        // for (int i = 0; i < N; i++) {
        //
        //     for (int j = 0; j < N; j++) {
        //         cout << setw(4) << matriz[i][j];
        //     }
        //
        //     cout << endl;
        // }
        // return true;

        /* imrpimir todo revisando */
        if (corroboracion2(matriz, N)) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
            return true;
        } else {
            return false;
        }
    }

    for (int i = 0; i < 8; i++) {
        int nuevox = ubix + movx[i];
        int nuevoy = ubiy + movy[i];

        if (corroboracion(N, nuevox, nuevoy, matriz)) {
            int copia = matriz[nuevox][nuevoy];
            matriz[nuevox][nuevoy] = posicion;
            if (backtraking(matriz, N, nuevox, nuevoy, posicion + 1)) {
                return true;
            }
            matriz[nuevox][nuevoy] = 0;
        }
    }
    return false;
}


int main() {
    int N = 5;


    if ((N * (N*N + 1)) % 2 != 0) {
        cout << "Matematicamente no puede tener suma entera";
    }

    int **matriz = new int *[N];

    for (int i = 0; i < N; i++) {
        matriz[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }
    int iniciox = 0;
    int inicioy = 0;

    matriz[iniciox][inicioy] = 1;
    if (backtraking(matriz, N, iniciox, inicioy, 2)) {
        cout<<"si hay"<<endl;
    }else {
        cout<<" no hay"<<endl;
    }


    // Liberar memoria
    for (int i = 0; i < N; i++) {
        delete[] matriz[i];
    }

    delete[] matriz;


    return 0;
}
