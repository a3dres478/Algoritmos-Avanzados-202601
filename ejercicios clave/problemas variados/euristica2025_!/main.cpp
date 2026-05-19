#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct ordenes {
    int idorden;
    int cantidad;
    int tiempo;
};

struct maquinas {
    int id;
    int tiempototal;
};

struct respuestas {
    int idlinea;
    int idorden;
    int cantidad;
};

bool comparacionlineas(maquinas a, maquinas b) {
    return a.tiempototal < b.tiempototal;
}

int main() {
    int lineasdeproduccion = 5;
    int ordenesdeproduccion = 20;

    ordenes listaordenes[20] = {
        {1, 103, 0},
        {2, 58, 0},
        {3, 88, 0},
        {4, 126, 0},
        {5, 195, 0},
        {6, 90, 0},
        {7, 54, 0},
        {8, 195, 0},
        {9, 124, 0},
        {10, 113, 0},
        {11, 193, 0},
        {12, 55, 0},
        {13, 97, 0},
        {14, 97, 0},
        {15, 169, 0},
        {16, 50, 0},
        {17, 167, 0},
        {18, 74, 0},
        {19, 79, 0},
        {20, 109, 0}
    };
    vector<ordenes>vordenes;
    for(int i = 0; i < ordenesdeproduccion; i++) {
        ordenes nodo= listaordenes[i];
        nodo.tiempo = nodo.cantidad*6;
        listaordenes[i]=nodo;
        vordenes.push_back(listaordenes[i]);
    }
    vector<maquinas>vmaquinas;

    for(int i = 0; i < lineasdeproduccion; i++) {
        maquinas nodo;
        nodo.id=i+1;
        nodo.tiempototal=0;
        vmaquinas.push_back(nodo);
    }
vector<respuestas>vrespuestas;
    sort(vmaquinas.begin(), vmaquinas.end(), comparacionlineas);

    for (int i=0;i<ordenesdeproduccion;i++) {
        ordenes nodoorden=vordenes[i];
        int tiempodeorden=nodoorden.tiempo;
        sort(vmaquinas.begin(), vmaquinas.end(), comparacionlineas);
        maquinas nodo_maquinas;
        nodo_maquinas=vmaquinas[0];
        nodo_maquinas.tiempototal=tiempodeorden+nodo_maquinas.tiempototal;
        int borrador=nodo_maquinas.tiempototal;
        vmaquinas[0]=nodo_maquinas;
        respuestas nodo_respuestas;
        nodo_respuestas.idorden=nodoorden.idorden;
        nodo_respuestas.idlinea=nodo_maquinas.id;
        nodo_respuestas.cantidad=nodoorden.cantidad;
        vrespuestas.push_back(nodo_respuestas);

    }
    for (int i=0;i<lineasdeproduccion;i++) {
        cout<<"Para la linea "<<i+1<<": ";
        for (int j=0;j<vrespuestas.size();j++) {
            respuestas nodo_respuestas=vrespuestas[j];
            int idlinea=nodo_respuestas.idlinea;

            if (nodo_respuestas.idlinea==i+1) {
                cout<<" ("<<nodo_respuestas.cantidad<<") ";
            }

        }
        int carga=0;
        for (int j=0;j<vmaquinas.size();j++) {
            if (vmaquinas[j].id==i+1) {
                carga=vmaquinas[j].tiempototal;
            }
        }


        cout<<","<<carga<<endl;
    }


    return 0;
}