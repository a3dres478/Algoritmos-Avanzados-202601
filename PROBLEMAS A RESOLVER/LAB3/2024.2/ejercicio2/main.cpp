#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct data1 {
    int requerimiento;
    int longitud;
    int altura;
    int conversion;
};

struct espacios {
    int longitud;
    int altura;
};

struct Lamina {
    vector<espacios> libres;
};

bool compare(data1 a, data1 b) {
    return a.conversion > b.conversion;
}

bool colocarlamina(Lamina &lamina, data1 piezaquesesaca) {
    for (int i = 0; i < lamina.libres.size(); i++) {
        espacios actual = lamina.libres[i];

        if (actual.longitud >= piezaquesesaca.longitud && actual.altura >= piezaquesesaca.altura) {
            lamina.libres.erase(lamina.libres.begin() + i);


            espacios derecha;
            derecha.longitud = actual.longitud - piezaquesesaca.longitud;
            derecha.altura = actual.altura;

            espacios abajo;
            abajo.longitud = actual.longitud;
            abajo.altura = actual.altura - piezaquesesaca.altura;

            if (derecha.longitud > 0 && derecha.altura > 0) {
                lamina.libres.push_back(derecha);
            }

            if (abajo.longitud > 0 && abajo.altura > 0) {
                lamina.libres.push_back(abajo);
            }

            return true;
        }
    }
    return false;
}


void euristica(data1 matriz[5], int L, int H) {
    vector<data1> proyectos;
    data1 nodo;
    int areausada = 0;

    for (int i = 0; i < 5; i++) {
        nodo = matriz[i];
        proyectos.push_back(nodo);
    }
    sort(proyectos.begin(), proyectos.end(), compare);

    vector<Lamina> laminas;

    for (int i = 0; i < 5; i++) {
        data1 piezaquesesaca = proyectos[i];


        for (int j = 0; j < piezaquesesaca.requerimiento; j++) {
            bool colocado = false;

            for (int k = 0; k < laminas.size(); k++) {
                if (colocarlamina(laminas[k], piezaquesesaca)) {
                    colocado = true;
                    break;
                }
            }


            if (!colocado) {
                Lamina nueva;
                nueva.libres.push_back({50, 50});
                colocarlamina(nueva, piezaquesesaca);
                laminas.push_back(nueva);
            }
            areausada += piezaquesesaca.conversion;

        }
    }
    int numeroLaminas = laminas.size();
    int areaTotal = numeroLaminas * L * H;
    int merma = areaTotal - areausada;

    double porcentajeMerma = (merma * 100.0) / areaTotal;

    cout << "Numero de laminas usadas: " << numeroLaminas << endl;
    cout << "Area total disponible: " << areaTotal << endl;
    cout << "Area usada: " << areausada << endl;
    cout << "Merma residual: " << merma << endl;
    cout << fixed << setprecision(2);
    cout << "Porcentaje de merma: " << porcentajeMerma << "%" << endl;
}

int main() {
    struct data1 matriz[5] = {
        {5, 2, 3, 2 * 3},
        {10, 9, 3, 9 * 3},
        {15, 14, 7, 14 * 7},
        {20, 15, 20, 15 * 20},
        {20, 22, 18, 22 * 18}
    };
    int L = 50;
    int H = 50;

    euristica(matriz, L, H);
    return 0;
}
