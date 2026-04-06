#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int mejor = 999999;
int ropasinlavar = 99999;
int matrizfinal[5][7] = {};
int lavadorasfinales[5] = {};

void backtraging(int matriz[][7], int filas, int columnas, int lavadoras[], int costos[], int punterofila,
                 int punterocolumna, int sumatoria, int ropanolavada) {
    if (filas == punterofila) {
        if (ropanolavada < ropasinlavar ||
            (ropanolavada == ropasinlavar && sumatoria < mejor)) {
            ropasinlavar = ropanolavada;
            mejor = sumatoria;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 7; j++) {
                    matrizfinal[i][j] = matriz[i][j];
                }
                lavadorasfinales[i] = lavadoras[i];
            }
        }

        return;
    }
    int dx = punterofila;
    int dy = punterocolumna ;

    int nx=dx;
    int ny=dy+1;

    if (ny == columnas) {
        nx++;
        ny = 0;
    }

    if (matriz[dx][dy] == 0) {
        backtraging(matriz, filas, columnas, lavadoras, costos, nx, ny, sumatoria, ropanolavada);
        return;
    }

    int peso = matriz[dx][dy];
    backtraging(matriz, filas, columnas, lavadoras, costos, nx, ny, sumatoria, ropanolavada + peso);

    if (lavadoras[dx] >= peso) {
        int temp = matriz[dx][dy];
        matriz[dx][dy] = 0;
        lavadoras[dx] -= peso;
        int costoporkg = costos[dx];
        int total = peso * costoporkg;
        backtraging(matriz, filas, columnas, lavadoras, costos, nx, ny, sumatoria + total, ropanolavada);
        lavadoras[dx] += peso;
        matriz[dx][dy] = temp;
    }
}

int main() {
    int costos[5] = {5, 6, 8, 5, 9};
    int lavadoras[5] = {50, 50, 50, 50, 50};
    int kilos_de_ropa[5][7] = {
        {14, 11, 10, 19, 14, 11, 0},
        {20, 11, 11, 10, 15, 17, 8},
        {15, 16, 15, 16, 0, 0, 0},
        {11, 4, 19, 12, 10, 0, 0},
        {18, 12, 0, 0, 0, 0, 0}
    };
    int filas = 5;
    int columnas = 7;

    backtraging(kilos_de_ropa, filas, columnas, lavadoras, costos, 0, 0, 0, 0);


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            cout << matrizfinal[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "______";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << lavadorasfinales[i] << " ";
    }

cout<<endl<<"ganancias: "<<mejor<<endl;
    cout<<"ropa sin lavar; "<<ropasinlavar<<endl;

    cout <<endl<< "fin" << endl;

    return 0;
}
