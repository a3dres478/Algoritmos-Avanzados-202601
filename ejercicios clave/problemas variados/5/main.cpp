#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct subconjunto {
    int id;
    vector<int>numbers;
    bool taken;
    int dissmmis;
};
//
// struct respuestas {
//
// }


bool comparacion(subconjunto a, subconjunto b) {
    return a.dissmmis>b.dissmmis;
}

int main() {
    int array[7];

    for (int i=0;i<7;i++) {
        array[i] = i+1;
    }

    vector<subconjunto> subconjuntos;

    subconjunto nodo;

    nodo.id=1;
    nodo.dissmmis = 3;
    nodo.taken = false;

    nodo.numbers.push_back(1);
    nodo.numbers.push_back(2);
    nodo.numbers.push_back(3);

    subconjuntos.push_back(nodo);

    nodo={};

    nodo.id=2;
    nodo.dissmmis = 3;
    nodo.taken = false;

    nodo.numbers.push_back(2);
    nodo.numbers.push_back(4);
    nodo.numbers.push_back(5);

    subconjuntos.push_back(nodo);

    nodo={};

    nodo.id=3;
    nodo.dissmmis = 3;
    nodo.taken = false;

    nodo.numbers.push_back(3);
    nodo.numbers.push_back(5);
    nodo.numbers.push_back(6);

    subconjuntos.push_back(nodo);

    nodo={};

    nodo.id=4;
    nodo.dissmmis = 2;
    nodo.taken = false;

    nodo.numbers.push_back(6);
    nodo.numbers.push_back(7);

    subconjuntos.push_back(nodo);



    int bandera=0;
    while (true) {
        int contador=0;
        for (int l=0;l<7;l++) {
            if (array[l]==-1) {
                contador++;
            }
        }
        if (contador==7) {
            cout<<"se completo todo"<<endl;
            break;
        }

        if (bandera>subconjuntos.size()) {
            break;
        }

        sort(subconjuntos.begin(), subconjuntos.end(), comparacion);


        subconjunto bbva=subconjuntos[0];

        bbva.taken=true;
        int cantidadedatos=bbva.numbers.size();
        for (int i=0;i<cantidadedatos;i++) {
            int info=bbva.numbers[i];
            for (int j=0;j<7;j++) {
                if (info==array[j]) {
                    array[j]=-1;
                }
            }
        }
        bbva.dissmmis=0;
        subconjuntos[0]=bbva;
        //actualizamos los demás datos
        cout<<"Elegimos al subconjunto numero: "<<subconjuntos[0].id<<endl;
        for (int i=1;i<subconjuntos.size();i++) {
            subconjunto nodoreal=subconjuntos[i];
            int borrador=0;
            for (int j=0;j<nodoreal.numbers.size();j++) {
                int info=nodoreal.numbers[j];
                for (int k=0;k<7;k++) {
                    if (array[k]==info) {
                        borrador++;
                    }
                }

            }
            nodoreal.dissmmis=borrador;
            subconjuntos[i]=nodoreal;
        }



        bandera++;
    }



    return 0;
}