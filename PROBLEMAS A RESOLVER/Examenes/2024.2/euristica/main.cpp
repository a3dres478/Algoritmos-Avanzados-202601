#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct subconjunto {
    int numerosubconjunto;
    vector<int> numeros;
    int cumplen;
};

struct rpta {
    int numerosubconjunto;
};

bool comparacion(subconjunto a, subconjunto b) {
    return a.cumplen > b.cumplen;
}

int main() {
    int arre[7] = {1, 2, 3, 4, 5, 6, 7};

    vector<subconjunto> subconjuntos;
    vector<rpta> rptas;

    subconjunto nodo;

    // S1 = {1,2,3}
    nodo.numeros.clear();
    nodo.numerosubconjunto = 1;
    nodo.cumplen = 0;
    nodo.numeros.push_back(1);
    nodo.numeros.push_back(2);
    nodo.numeros.push_back(3);
    subconjuntos.push_back(nodo);

    // S2 = {2,4,5}
    nodo.numeros.clear();
    nodo.numerosubconjunto = 2;
    nodo.cumplen = 0;
    nodo.numeros.push_back(2);
    nodo.numeros.push_back(4);
    nodo.numeros.push_back(5);
    subconjuntos.push_back(nodo);

    // S3 = {3,5,6}
    nodo.numeros.clear();
    nodo.numerosubconjunto = 3;
    nodo.cumplen = 0;
    nodo.numeros.push_back(3);
    nodo.numeros.push_back(5);
    nodo.numeros.push_back(6);
    subconjuntos.push_back(nodo);

    // S4 = {6,7}
    nodo.numeros.clear();
    nodo.numerosubconjunto = 4;
    nodo.cumplen = 0;
    nodo.numeros.push_back(6);
    nodo.numeros.push_back(7);
    subconjuntos.push_back(nodo);

    while (true) {

        // Verificar si ya todo U está cubierto
        int mm = 0;
        for (int i = 0; i < 7; i++) {
            if (arre[i] == -1) {
                mm++;
            }
        }

        if (mm == 7) {
            break;
        }

        // Recalcular cumplen para cada subconjunto
        for (int k = 0; k < subconjuntos.size(); k++) {
            subconjuntos[k].cumplen = 0;

            for (int p = 0; p < subconjuntos[k].numeros.size(); p++) {
                int num = subconjuntos[k].numeros[p];

                // Si ese número todavía no fue cubierto
                if (arre[num - 1] != -1) {
                    subconjuntos[k].cumplen++;
                }
            }
        }

        // Ordenamos para que el mejor quede al inicio
        sort(subconjuntos.begin(), subconjuntos.end(), comparacion);

        // Si el mejor no cubre nada nuevo, ya no se puede avanzar
        if (subconjuntos[0].cumplen == 0) {
            cout << "NUNCA SE LLENA LA WBDA" << endl;
            return 0;
        }

        // Elegimos el mejor subconjunto
        subconjunto nodo1 = subconjuntos[0];

        // Guardamos la respuesta
        rpta nodorespuesta;
        nodorespuesta.numerosubconjunto = nodo1.numerosubconjunto;
        rptas.push_back(nodorespuesta);

        // Marcamos como cubiertos los elementos del subconjunto elegido
        for (int i = 0; i < nodo1.numeros.size(); i++) {
            int num = nodo1.numeros[i];

            if (arre[num - 1] != -1) {
                arre[num - 1] = -1;
            }
        }

        // Eliminamos el subconjunto usado
        subconjuntos.erase(subconjuntos.begin());
    }

    cout << "Unas respuestas serian: ";
    for (int i = 0; i < rptas.size(); i++) {
        cout << "S" << rptas[i].numerosubconjunto << " ";
    }

    return 0;
}