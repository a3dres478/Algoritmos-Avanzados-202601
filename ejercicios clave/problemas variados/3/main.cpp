#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


void backtraking(double matriz[6][6],int visitados[],int arreglo[], int posicion,double &menor) {
    if (posicion == 6) {
        double informacion=0;
        for (int i=1; i<6; i++) {
            double copia = matriz[arreglo[i - 1]][arreglo[i]];
            informacion = informacion + copia;
        }
        informacion = matriz[arreglo[5]][0]+informacion;
        if (informacion<menor) {
            menor = informacion;
            for (int i=0; i<6; i++) {
                cout << arreglo[i] << " ";
            }
            cout<< menor<<endl;
        }



        return;
    }

    for (int i=1; i<6; i++) {
        if (visitados[i] ==-1) {
            visitados[i] = 1;

            int copia=arreglo[posicion];
            arreglo[posicion] =i;
            backtraking(matriz,visitados,arreglo,posicion+1,menor);
            arreglo[posicion] = -1;
            visitados[i] = -1;

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

    int visitados[6];
    int arreglo[6];
    for (int i=0; i<6; i++) {
        visitados[i] = -1;
        arreglo[i] = -1;
    }
    visitados[0] = 1;
    arreglo[0] = 0;
    double menor=9999;


    backtraking(matriz,visitados,arreglo,1,menor);

    return 0;
}
