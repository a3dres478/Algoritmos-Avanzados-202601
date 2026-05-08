#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tareas {
    int numero;
    int horasmaximas;
    int ganancias;
};

struct rptas {
    int hora;
    int quetarea;
    bool ocupado;
};

bool comparacion(tareas t1, tareas t2) {
    return t1.ganancias > t2.ganancias;
}


int main() {

    int datosdeingreso=5;

    tareas arreglos[5]={
        {1,2,100},
        {2,1,19},
        {3,2,27},
        {4,1,25},
        {5,3,15}
    };

    int maximo=0;
    for(int i=0;i<5;i++) {
        tareas nodo=arreglos[i];
        int data=nodo.horasmaximas;
        if (data>maximo) {
            maximo=data;
        }
    }
    vector<tareas> tareasarre;
    for (int i=0;i<5;i++) {
        tareas nodo=arreglos[i];
        tareasarre.push_back(nodo);
    }

    vector<rptas> respuestas;
    for(int i=0;i<maximo;i++) {
        rptas nodo;
        nodo.hora=i+1;
        nodo.quetarea=0;
        nodo.ocupado=false;
        respuestas.push_back(nodo);
    }

    sort(tareasarre.begin(), tareasarre.end(), comparacion);

    for(int i=0;i<datosdeingreso;i++) {
        tareas nodo=tareasarre[i];
        int numeronodo=nodo.horasmaximas;
        rptas nodorpta1=respuestas[numeronodo-1];
        if (nodorpta1.ocupado==false) {
            nodorpta1.ocupado=true;
            nodorpta1.quetarea=nodo.numero;
            respuestas[numeronodo-1]=nodorpta1;
        }else {
            //se lo busca un espacio disponible
            for (int j=numeronodo-1;j>=0;j--) {
                nodorpta1=respuestas[j];
                if (nodorpta1.ocupado==false) {
                    nodorpta1.ocupado=true;
                    nodorpta1.quetarea=nodo.numero;
                    respuestas[j]=nodorpta1;
                    break;
                }
            }
        }

    }


    int gananciaTotal = 0;

    cout << "Tareas seleccionadas: ";

    for (int i = 0; i < respuestas.size(); i++) {
        if (respuestas[i].ocupado) {
            cout << respuestas[i].quetarea << " ";

            for (int j = 0; j < datosdeingreso; j++) {
                if (arreglos[j].numero == respuestas[i].quetarea) {
                    gananciaTotal += arreglos[j].ganancias;
                }
            }
        }
    }

    cout << endl;
    cout << "Ganancia total: " << gananciaTotal << endl;


    return 0;
}