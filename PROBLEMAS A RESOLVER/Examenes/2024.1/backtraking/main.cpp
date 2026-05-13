#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#define N 5

bool prueba1(int inix, int iniy, int matrizreferencia[5][5], int matrizfinal[5][5]) {
    if (inix < 0 || iniy < 0 || inix >= 5 || iniy >= 5 || matrizreferencia[inix][iniy] == 0 || matrizfinal[inix][iniy]
        == 1) {
        return false;
    } else {
        return true;
    }
}

void backtraking(int valoresx[], int valoresy[], int matrizreferencia[5][5],
                 int matrizfinal[5][5], int inix, int iniy, int finalx, int finaly, int &menorcosto, int sumatoria) {
    if (inix == finalx && iniy == finaly && menorcosto >= sumatoria) {
        menorcosto = sumatoria;
        cout<<"UNA POSIBLE SOLUCION: "<<sumatoria<<endl;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << matrizfinal[i][j] << " ";
            }

            cout << endl;
        }


        return;
    }


    //inicia el backtraking
    for (int i = 0; i < 4; i++) {
        int valordex = valoresx[i];
        int valordey = valoresy[i];
        int inixposible = inix + valordex;
        int iniyposible = iniy + valordey;
        if (prueba1(inixposible, iniyposible, matrizreferencia, matrizfinal)) {
            int data = matrizreferencia[inixposible][iniyposible];
            matrizfinal[inixposible][iniyposible] = 1;
            backtraking(valoresx, valoresy, matrizreferencia, matrizfinal,
                        inixposible, iniyposible, finalx, finaly, menorcosto, sumatoria + data);
            matrizfinal[inixposible][iniyposible] = 0;
        }
    }
}



int main() {
    int valoresx[4] = {0, 1, 0, -1};
    int valroesy[4] = {1, 0, -1, 0};

    int matriz[5][5] = {
        {1, 2, 0, 1, 0},
        {3, 2, 3, 1, 1},
        {0, 1, 2, 0, 0},
        {3, 1, 1, 2, 3},
        {0, 1, 3, 1, 1}
    };

    int iniciox = 0;
    int inicioy = 0;

    int finalx = 4;
    int finaly = 4;

    int menorcosto = 9999;

    int matriz2[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int sumatoria = 0;
    backtraking(valoresx, valroesy, matriz,
                matriz2, iniciox, inicioy, finalx, finaly, menorcosto, sumatoria);



    return 0;
}
