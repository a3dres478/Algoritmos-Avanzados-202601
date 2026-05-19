#include <iostream>
#include <iomanip>
#include <fstream>
using namespace  std;

void backtra(double matriz[6][6],int N,double&minimo,int posicion,int valorestomados[],double sumaparcial,int arreglo[]) {
    if (posicion>=N) {
        sumaparcial=sumaparcial+0;
        if (sumaparcial<minimo) {
            for (int i=0;i<N;i++) {
                cout<< arreglo[i]<<" ";
            }
            cout<<sumaparcial+matriz[0][arreglo[5]]<<endl;
            minimo=sumaparcial;
        }

        return;
    }

    for (int i=1;i<N;i++) {
        if (valorestomados[i]==-1) {
            valorestomados[i]=1;
            int bandera= arreglo[posicion-1];
            double valor=matriz[arreglo[posicion-1]][i];
            arreglo[posicion]=i;
            if (valor!=0) {
                backtra(matriz,N,minimo,posicion+1,valorestomados,sumaparcial+valor,arreglo);
            }
            valorestomados[i]=-1;
            arreglo[posicion]=-1;
        }


    }


}

int main() {
    double matriz[6][6]={
        {0   , 2.24, 2.69, 4.00, 2.06, 3.35},
        {2.24, 0   ,  4.5, 5.39,  1.5, 5.59},
        {2.69, 4.5 ,    0, 5.59, 4.74, 2.55},
        {4   ,5.39 ,5.59 ,0    , 4.03, 3.91},
        {2.06,  1.5,4.74,  4.03,    0,  5.1},
        {3.35, 5.59, 2.55, 3.91, 5.10, 0.00}
    };

    int valorestomados[6];
    int arreglo[6];
    for (int i=0;i<6;i++) {
        valorestomados[i] =-1;
        arreglo[i] =-1;
    }
    //valorestomados[0]=1;
    arreglo[0]=0;
    double minimo=99999;
    backtra(matriz,6,minimo,1,valorestomados,0,arreglo);

    cout<<"c logro"<<endl;
    return 0;
}
