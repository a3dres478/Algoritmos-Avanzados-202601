#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct discos {
    int numero;
    int velocidad;
};

struct tablas {
    int numero;
    int velocidad;
};

struct respuesta {
    int disco;
    int tabla;
};

bool comparartablas(tablas a, tablas b) {
    return a.velocidad > b.velocidad;
}

bool comparardiscos(discos a, discos b) {
    return a.velocidad > b.velocidad;
}

void euristica(int numerodisco,int numtablas, tablas arretabl_tablas[],discos arredisc[]) {
    vector <tablas> tablas_;
    vector <discos> discos_;
    vector <respuesta> rpta;

    for (int i=0;i<numtablas;i++) {
        tablas_.push_back(arretabl_tablas[i]);
    }

    for (int i=0;i<numerodisco;i++) {
        discos_.push_back(arredisc[i]);
    }
    cout<<"entró"<<endl;
    int puntero=0;
    while (true) {
        if (puntero>numtablas) {
            cout<<"salida mala "<<endl;
            break;
        }

        if (tablas_.size()==0) {
            break;
        }


        sort(tablas_.begin(),tablas_.end(),comparartablas);

        sort(discos_.begin(),discos_.end(),comparardiscos);

        bool bandera=false;

        tablas nodotablas=tablas_[puntero];
        int velocidadtablas=tablas_[puntero].velocidad;
        int numerotablas=tablas_[puntero].numero;
        int ubideldisco=0;
        for (int i=0;i<numerodisco;i++) {
            discos nodo=discos_[i];
            int espacio=nodo.velocidad;
            int numerodedisco=nodo.numero;
            if (espacio>=velocidadtablas) {
                int a=velocidadtablas-espacio;
                int b=espacio-velocidadtablas;
                nodo.velocidad=espacio-velocidadtablas;
                discos_[i]=nodo;
                respuesta nodorespuesta;
                nodorespuesta.disco=numerodedisco;
                nodorespuesta.tabla=numerotablas;
                rpta.push_back(nodorespuesta);
                ubideldisco=i;
                bandera=true;
                break;
            }
        }

        if (bandera) {
            //discos_.erase(discos_.begin()+ubideldisco);
            tablas_.erase(tablas_.begin()+puntero);
            puntero=0;
        }else {
            puntero++;
        }


    }

    for (int i=0;i<rpta.size();i++) {
        cout<<"disco numero:"<<rpta[i].disco<<" tabla numero:"<<rpta[i].tabla<<endl;
    }


}


int main() {
    tablas tablas[6]={
        {1,150},
        {2,100},
        {3,180},
        {4,50},
        {5,120},
        {6,10}
    };

    discos discos[4]={
        {1,250},
        {2,200},
        {3,200},
        {4,100}
    };

    int numtablas=6;
    int numdiscos=4;

    euristica(numdiscos,numtablas,tablas,discos);


    return 0;
}