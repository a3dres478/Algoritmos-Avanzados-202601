#include <iostream>
#include <iomanip>
using namespace std;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool reymovimiento(int tablero[][9], int filasxcolumnas, int ubix, int ubiy, int pasos) {
    if (pasos == (filasxcolumnas * filasxcolumnas) - 1) {
        return true;
    }
    for (int i = 0; i < 8; i++) {
        int nx = ubix + dx[i];
        int ny = ubiy + dy[i];
        if (nx >= 0 && ny >= 0 && nx < filasxcolumnas && ny < filasxcolumnas && tablero[nx][ny] == -1) {
            tablero[nx][ny] = pasos;
            if (reymovimiento(tablero, filasxcolumnas, nx, ny, pasos + 1)) {
                return true;
            }
            tablero[nx][ny] = -1;
        }
    }
    return false;
}

int main() {
    int tablero[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            tablero[i][j] = -1;
        }
    }
    int ubix = 4;
    int ubiy = 4;

    tablero[ubix][ubiy] = 0;
    //matriz,tamaño del tablero,ubic,ubiy,pasos
    bool resolver = reymovimiento(tablero, 9, ubix, ubiy, 1);

    if (resolver) {
        cout << "SE ENCONTRO SOLUCIÓN" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << tablero[i][j] << "\t";
            cout << endl;
        }
    } else {
        cout << "no se encontro nada" << endl;



    }
    return 0;
}