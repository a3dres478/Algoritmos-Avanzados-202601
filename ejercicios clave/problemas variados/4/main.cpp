#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace  std;

struct orden {
    int id;
    int cantidad;

    int tiempo;


};

struct linea {
    int id;
    int tiempo;
};

struct respuestas {
    int idlinea;
    int cantidadbotellas;
};

bool comparar(linea a, linea b) {
    return a.tiempo<b.tiempo;
}

int main() {
    int lineastotales=5;
    int ordenes=20;


     orden ordenas[20]={
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


    vector<orden>vorden;
    for (int i=0;i<ordenes;i++) {
        orden nodo=ordenas[i];
        int data=nodo.cantidad*6;
        nodo.tiempo=data;
        ordenas[i]=nodo;
        vorden.push_back(nodo);
    }


    vector<linea> vlineas;
    for (int i=0;i<lineastotales;i++) {
        linea nodo;
        nodo.id=i+1;
        nodo.tiempo=0;
        vlineas.push_back(nodo);
    }

    vector<respuestas>vrespuestas;
    for (int i=0;i<ordenes;i++) {
        orden nodo=ordenas[i];
        sort(vlineas.begin(),vlineas.end(),comparar);
        int tiempo=nodo.tiempo;
        linea nodolinea=vlineas[0];
        nodolinea.tiempo=nodolinea.tiempo+tiempo;
        vlineas[0]=nodolinea;
        respuestas nodorespuestas;
        nodorespuestas.cantidadbotellas=nodo.cantidad;
        nodorespuestas.idlinea=nodolinea.id;
        vrespuestas.push_back(nodorespuestas);

    }
    int dataxd=1;
while (true) {
    if (dataxd>lineastotales) {
        break;
    }
    cout<<"Para la linea: "<<dataxd;
    int botellas=0;
    for (int i=0;i<vrespuestas.size();i++) {
        respuestas nodorespuestas=vrespuestas[i];
        if (nodorespuestas.idlinea==dataxd) {
            cout<<" ("<<nodorespuestas.cantidadbotellas<<") ";
            botellas=botellas+nodorespuestas.cantidadbotellas;
        }

    }
    cout<<" con una totalidad de tiempo de : "<<botellas*6<<endl;


    dataxd++;
}



    return 0;
}