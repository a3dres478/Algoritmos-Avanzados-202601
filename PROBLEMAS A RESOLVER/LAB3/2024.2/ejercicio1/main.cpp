#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

struct proyectos {
    int numero;
    int costo;
    int ganancia;
    double valor;
    int beneficio;
    int predece[3];
};

using namespace std;

bool comparacion(proyectos a, proyectos b) {
    return a.valor > b.valor;
}

bool pruebas(vector<proyectos> respuestas, proyectos nodo) {
    if (respuestas.size() == 0) {
        return true;
    }

    int numeroproyecto = nodo.numero;
    int arre[3] = {0};
    bool tieneante = true;
    for (int i = 0; i < 3; i++) {
        arre[i] = nodo.predece[i];
        if (arre[0] == 0) {
            tieneante = false;
            break;
        }
    }
    int numproy[respuestas.size()];
    for (int i = 0; i < respuestas.size(); i++) {
        numproy[i] = respuestas[i].numero;
    }

    int numero1 = arre[0];
    int numero2 = arre[1];
    bool bandera1 = false;
    bool bandera2 = false;
    if (numero1 == 0) {
        return true;
    }
    if (numero2 == 0) {
        bandera2 = true;
    }

    for (int i = 0; i < respuestas.size(); i++) {
        if (numproy[i] == numero1) {
            bandera1 = true;
        }
        if (numproy[i] == numero2) {
            bandera2 = true;
        }
    }

    return bandera1 && bandera2;
}


void euristica(proyectos proyect[8], int N, int maximo) {
    int presupuesto = maximo;
    int ganancia = 0;
    vector<proyectos> matriz;
    for (int i = 0; i < N; i++) {
        matriz.push_back(proyect[i]);
    }
    vector<proyectos> respuetas;

    while (1) {
        if (matriz.empty()) {
            break;
        }
        sort(matriz.begin(), matriz.end(), comparacion);
        //vamos a tener que agarrar 1 de estos
        proyectos nodo;
        int ubicacion = -1;
        for (int i = 0; i < matriz.size(); i++) {
            nodo = matriz[i];
            if (pruebas(respuetas, nodo) && nodo.costo <= presupuesto) {
                ubicacion = i;
                break;
            }
        }
        if (ubicacion == -1) {
            break;
        }

        //revisamos si alcanza aun espacio
        int costo1 = nodo.costo;
        presupuesto -= costo1;
        ganancia += nodo.ganancia;
        //eliminamos al dato que hemos colocado
        matriz.erase(matriz.begin() + ubicacion);
        respuetas.push_back(nodo);
    }

    cout << "SI HAY GANANCIA " << ganancia << endl;
}

int main() {
    proyectos matriz[8] = {
        {1, 80, 150, (150.0 * 2) / 80, 2, {0, 0, 0}},
        {2, 20, 80, (80.0 * 5) / 20, 5, {4, 0, 0}},
        {3, 100, 300, (300.0 * 1) / 100, 1, {1, 2, 0}},
        {4, 100, 150, (150.0 * 4) / 100, 4, {0, 0, 0}},
        {5, 50, 80, (80.0 * 2) / 50, 2, {0, 0, 0}},
        {6, 10, 50, (50.0 * 1) / 10, 1, {2, 0, 0}},
        {7, 50, 120, (120.0 * 2) / 50, 2, {6, 0, 0}},
        {8, 50, 150, (150.0 * 4) / 50, 4, {6, 0, 0}}
    };

    int N = 8;
    int maximo = 250;

    euristica(matriz, N, maximo);

    return 0;
}
