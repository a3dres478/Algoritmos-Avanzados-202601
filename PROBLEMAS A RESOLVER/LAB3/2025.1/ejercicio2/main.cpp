#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct lavadora {
    int numero;
    int enuso;
    int tiempofaltante;
};

struct rpta {
    int numero;
    int totaltiempo;
    int ropita;
};

struct ropa {
    int tipo;
    int peso;
    int tiempo;
};

bool comparacion(lavadora a, lavadora b) {
    return a.tiempofaltante < b.tiempofaltante;
}


void euristica(ropa arregloropa[], lavadora lavadoras[], int totalropas, int totallavadoras) {
    vector<lavadora> lavadorasv;
    vector<ropa> ropasv;
    vector<rpta> respuestas;

    for (int i = 0; i < totallavadoras; i++) {
        lavadorasv.push_back(lavadoras[i]);
    }
    for (int i = 0; i < totalropas; i++) {
        ropasv.push_back(arregloropa[i]);
    }

    for (int i = 0; i < totalropas; i++) {
        ropa nodo = ropasv[i];
        int tiempoderopa = nodo.tiempo;
        sort(lavadorasv.begin(), lavadorasv.end(), comparacion);
        lavadora nodolavadora = lavadorasv[0];

        int tiempomenor = nodolavadora.tiempofaltante;
        rpta nodorpt;
        nodorpt.ropita = i+1;
        if (tiempomenor != 0) {
            for (int j = 0; j < totallavadoras; j++) {
                lavadora nodo2 = lavadorasv[j];
                nodo2.tiempofaltante -= tiempomenor;
                lavadorasv[j] = nodo2;
            }
        }
        lavadorasv[0].tiempofaltante = tiempoderopa;

        nodorpt.numero = lavadorasv[0].numero;
        nodorpt.totaltiempo = tiempoderopa;
        respuestas.push_back(nodorpt);
    }

    for (int i = 0; i < 5; i++) {
        int total = 0;
        cout << "Numero de lavadora: " << i + 1 <<" con los partes de ";
        for (int j = 0; j < respuestas.size(); j++) {
            rpta nodo = respuestas[j];
            if (nodo.numero == i + 1) {
                total += nodo.totaltiempo;
                cout<<nodo.ropita<<" ";
            }
        }

        cout << " tiempo ejecutado" << total <<
                endl;
    }
}


int main() {
    ropa arregloropa[20] = {
        {1, 10, 0},
        {1, 10, 0},
        {2, 8, 0},
        {1, 15, 0},
        {2, 9, 0},
        {2, 11, 0},
        {1, 12, 0},
        {2, 15, 0},
        {1, 6, 0},
        {2, 10, 0},
        {1, 8, 0},
        {2, 15, 0},
        {1, 11, 0},
        {1, 7, 0},
        {1, 7, 0},
        {2, 8, 0},
        {2, 9, 0},
        {1, 11, 0},
        {2, 12, 0},
        {1, 15, 0}
    };

    lavadora arrelavadoras[5] = {
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 0},
        {4, 0, 0},
        {5, 0, 0}
    };

    //calculamos los tiempos
    for (int i = 0; i < 20; i++) {
        int numerodetipo = arregloropa[i].tipo;
        int pesoparte = arregloropa[i].peso;
        int total;
        if (numerodetipo == 1) {
            total = (pesoparte ) * 4;
        } else {
            total = (pesoparte ) * 2;
        }
        arregloropa[i].tiempo = total;
    }

    int ROPAS = 20;
    int lavadoras = 5;

    euristica(arregloropa, arrelavadoras, ROPAS, lavadoras);
    return 0;
}
