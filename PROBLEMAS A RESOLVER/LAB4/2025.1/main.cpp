#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <climits>

struct botellas {
    int idorden;
    int cantidadbotellas;
    int tiempo;
    int prioridad;
};

struct lineas {
    int idlinea;
    int tiempolinea;
};

struct respuestas {
    int idlinea;
    int idorden;
};

using namespace std;

bool comparar(botellas a, botellas b) {
    return a.cantidadbotellas > b.cantidadbotellas;
}

bool compararlinea(lineas a, lineas b) {
    return a.tiempolinea < b.tiempolinea;
}


int buscarind(vector<botellas> vbotellas, double maxrcl) {
    int cont = 0;
    for (int i = 0; i < vbotellas.size(); i++) {
        if (vbotellas[i].tiempo >= maxrcl) {
            cont++;
        }
    }
    return cont;
}

int buscarindtabla(vector<lineas> vlineas, double maxrcl) {
    int cont = 0;
    for (int i = 0; i < vlineas.size(); i++) {
        if (vlineas[i].tiempolinea <= maxrcl) {
            cont++;
        }
    }
    return cont;
}

void metaeuristica(botellas ordenes[], int tamanioorden) {
    int mejor =  INT_MAX;

    vector<respuestas> mejorrespuesta;
    srand(time(NULL));

    for (int i = 0; i < 10000; i++) {
        vector<respuestas> respuesta;
        vector<botellas> vbotellas;
        vector<lineas> vlineas;
        int residual;
        vbotellas.insert(vbotellas.begin(), ordenes, ordenes + tamanioorden);
        for (int j = 0; j < 5; j++) {
            lineas nodo;
            nodo.idlinea = j + 1;
            nodo.tiempolinea = 0;
            vlineas.push_back(nodo);
        }
        sort(vlineas.begin(), vlineas.end(), compararlinea);
        sort(vbotellas.begin(), vbotellas.end(), comparar);
        while (!vbotellas.empty()) {
            int betab = vbotellas[0].tiempo;
            int taut = vbotellas[vbotellas.size() - 1].tiempo;
            double rclt = betab - 0.4 * (betab - taut);
            int indt = buscarind(vbotellas, rclt);
            int indat = rand() % indt;

            int betatab = vlineas[0].tiempolinea;
            int tautab = vlineas[vlineas.size() - 1].tiempolinea;
            double rcltab = betatab + 0.4 * (tautab-betatab);
            int indtab = buscarindtabla(vlineas, rcltab);
            int indatab = rand() % indtab;


            respuesta.push_back({vlineas[indatab].idlinea,vbotellas[indat].idorden});
            vlineas[indatab].tiempolinea += vbotellas[indat].tiempo;

            vbotellas.erase(vbotellas.begin() + indat);
        }
        sort(vlineas.begin(), vlineas.end(), compararlinea);
        residual = vlineas[vlineas.size()-1].tiempolinea;
        if (residual < mejor) {
            mejor = residual;
            mejorrespuesta.clear();
            mejorrespuesta.insert(mejorrespuesta.begin(), respuesta.begin(), respuesta.end());
        }
    }
    cout << "Mejor Makespan: " << mejor << " minutos" << endl;

    for (int linea = 1; linea <= 5; linea++) {

        cout << "Linea " << linea << ": ";

        for (int j = 0; j < mejorrespuesta.size(); j++) {

            if (mejorrespuesta[j].idlinea == linea) {
                cout << mejorrespuesta[j].idorden << " ";
            }

        }

        cout << endl;
    }
}


int main() {
    botellas ordenes[20] = {
        {1, 103, 0, 2},
        {2, 58, 0, 1},
        {3, 88, 0, 3},
        {4, 126, 0, 1},
        {5, 195, 0, 2},
        {6, 90, 0, 2},
        {7, 54, 0, 3},
        {8, 195, 0, 1},
        {9, 124, 0, 2},
        {10, 113, 0, 3},
        {11, 193, 0, 2},
        {12, 55, 0, 1},
        {13, 97, 0, 1},
        {14, 97, 0, 2},
        {15, 169, 0, 2},
        {16, 50, 0, 2},
        {17, 167, 0, 3},
        {18, 74, 0, 1},
        {19, 79, 0, 2},
        {20, 109, 0, 1}
    };

    int tamanioorden = sizeof(ordenes) / sizeof(ordenes[0]);

    for (int i = 0; i < tamanioorden; i++) {
        ordenes[i].tiempo = ordenes[i].cantidadbotellas * 6;
    }
    return 0;
}
