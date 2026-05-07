#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace  std;

struct lineaprod {
    int numero;
    int totaltiempo;
    vector<int>ordenes;
};
struct orden {
    int num_orden;
    int cantidad;
    int tiempo;
};

bool comparacion(lineaprod a, lineaprod b) {
    return a.totaltiempo < b.totaltiempo;
}

void heuristica(lineaprod arreglo[], orden arregloordenes[]) {
    vector<lineaprod> lineas;
    vector<orden> ordenes;


    for (int i=0;i<20;i++) {
        ordenes.push_back(arregloordenes[i]);
    }
    for (int i=0;i<5;i++) {
        lineas.push_back(arreglo[i]);
    }

    for (int i=0;i<20;i++) {
        orden nodo=ordenes[i];
        int tiemposs=nodo.tiempo;
        sort(lineas.begin(), lineas.end(), comparacion);

        lineaprod nodolinea=lineas[0];
        nodolinea.totaltiempo=tiemposs+nodolinea.totaltiempo;
        nodolinea.ordenes.push_back(nodo.num_orden);
        lineas[0]=nodolinea;
    }

    for (int i=0;i<5;i++) {
        cout<<"Para la linea numero: "<<i+1<<" |||||||||";
        lineaprod nodolinea=lineas[i];
        for(int j=0;j<nodolinea.ordenes.size();j++) {
            int data=nodolinea.ordenes[j];
            cout<<" Orden("<<nodolinea.ordenes[j]<<")";
        }
        cout<<" con tiempo final de "<<nodolinea.totaltiempo<<endl;


    }

}



int main() {
    int datos[20]={
        103 ,58, 88, 126, 195, 90, 54 ,195, 124 ,113, 193, 55 ,97 ,97 ,169 ,50, 167, 74, 79, 109
    };
    orden ordenes[20];
    lineaprod linea[5];
    for (int i=0;i<5;i++) {
        lineaprod nodolinea=linea[i];
        nodolinea.numero=i+1;
        nodolinea.totaltiempo=0;
        linea[i]=nodolinea;
    }


    for (int i=0;i<20;i++) {
        orden nodo=ordenes[i];
        nodo.num_orden=i+1;
        nodo.cantidad=datos[i];
        nodo.tiempo=datos[i]*6;
        ordenes[i]=nodo;
    }

    heuristica(linea,ordenes);
    return 0;
}