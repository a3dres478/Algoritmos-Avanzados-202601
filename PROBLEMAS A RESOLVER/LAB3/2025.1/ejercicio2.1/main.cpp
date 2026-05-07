#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



struct lavadora {
    int numero;
    int tiempodado;
    vector<int>numeros;
};

struct ropa {
    int numeroorden;
    int tipo;
    int peso;
    int tiempo;
};

bool comparacion(lavadora a, lavadora b) {
    return a.tiempodado < b.tiempodado;
}

void euristicas(ropa arreglo1[],lavadora arreglo2[],int cantidadropa,int cantidadlavdora) {
    vector<lavadora>lavadoras;
    vector<ropa>ropas;

    for (int i=0;i<cantidadropa;i++) {
        ropas.push_back(arreglo1[i]);
    }
    for (int i=0;i<cantidadlavdora;i++) {
        lavadoras.push_back(arreglo2[i]);
    }

    for (int i=0;i<cantidadropa;i++) {
        ropa nodo=ropas[i];
        sort(lavadoras.begin(),lavadoras.end(),comparacion);
        lavadora menor=lavadoras[0];
        menor.tiempodado=menor.tiempodado+nodo.tiempo;
        menor.numeros.push_back(nodo.numeroorden);
        lavadoras[0]=menor;
    }
    for (int i=0;i<cantidadlavdora;i++) {
        lavadora nodo=lavadoras[i];
        cout<<"para la lavadora numero: "<<i+1<<"se tiene el tiempo de: "<<nodo.tiempodado<<"  con los numeros de ordenes de: ";
        for (int j=0;j<nodo.numeros.size();j++) {
            cout<<nodo.numeros[j]<<" ";
        }
        cout<<endl;
    }


}

int main() {

    ropa ropas[20] = {
        {1, 1, 10, 0},
        {2, 1, 10, 0},
        {3, 2, 8, 0},
        {4, 1, 15, 0},
        {5, 2, 9, 0},
        {6, 2, 11, 0},
        {7, 1, 12, 0},
        {8, 2, 15, 0},
        {9, 1, 6, 0},
        {10, 2, 10, 0},
        {11, 1, 8, 0},
        {12, 2, 15, 0},
        {13, 1, 11, 0},
        {14, 1, 7, 0},
        {15, 1, 7, 0},
        {16, 2, 8, 0},
        {17, 2, 9, 0},
        {18, 1, 11, 0},
        {19, 2, 12, 0},
        {20, 1, 15, 0}
    };

    lavadora lavadoras[5] = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0}
    };

    int numeroderopas=20;
    int numerodelavadoras=5;

    for (int i=0;i<numeroderopas;i++) {
        ropa nodo=ropas[i];
        int tiempo;
        if (nodo.tipo==1) {
            tiempo=nodo.peso*4;
        }else {
            tiempo=nodo.peso*2;
        }
        nodo.tiempo=tiempo;
        ropas[i]=nodo;
    }

    euristicas(ropas,lavadoras,numeroderopas,numerodelavadoras);

    return 0;
}