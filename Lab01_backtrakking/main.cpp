#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


bool back1(int matriz[9][9], int solu[9], int numacti, int cantidaddeuni, int cantidepara) {
    if (numacti == cantidepara) {
        //si llega a tener la cantidad de paradas y numeros acti encontr
        return true;
    }
    //recorre todas las posibles soluciones
    for (int i = 1; i <= cantidaddeuni; i++) {
        bool posible = true;
        for (int j = 0; j < cantidepara; j++) {
            int valormatri=matriz[numacti][j];
            int solum=solu[j];
            if (valormatri > 1) {
                if (i == solum) {
                    posible = false;
                    break;
                }
            }
        }
        if (posible) {
            solu[numacti] = i;
            int numact2 = numacti + 1;
            if (back1(matriz, solu, numact2, cantidaddeuni, cantidepara)) {
                return true;
            }
            solu[numacti] = 0;
        }
    }
    return false;
}

int main(int argc, char** argv) {
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

    int solu[9] = {};
    int cantidaddeuni = 4;
    //tomara en consideracion la cantidad de paradas que tendrá el sistema
    int cantidepara = 9;
    //crea el bool donde se llenará en caso que complete la tarea de manera exitosa
    bool rpta = back1(matriz, solu, 0, cantidaddeuni, cantidepara);

    if (rpta) {
        for (int i = 0; i < cantidepara; i++) {
            cout << solu[i] << " ";
        }
    }else{
        cout<<"imposible"<<endl;
    }



    return 0;
}