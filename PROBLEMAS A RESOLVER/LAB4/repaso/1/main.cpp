#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

struct botellas {
    int idorden;
    int cantidadbotellas;
    int tiempo;
    int prioridad;
};

struct linea {
    int idlinea;
    int tiempo;
};

struct respuesta {
    int idorden;
    int idlinea;
};

bool compararbotellas(botellas a, botellas b) {
    return a.tiempo > b.tiempo;
}

bool compararlineas(linea a, linea b) {
    return a.tiempo < b.tiempo;
}

int buscarindiceorden(double RCLLINEA, vector<botellas> vbotellas) {
    int cont = 0;
    for (int i = 0; i < vbotellas.size(); i++) {
        if (vbotellas[i].tiempo >= RCLLINEA) {
            cont++;
        }
    }
    return cont;
}


int buscarindice(double RCLLINEA, vector<linea> vlineas) {
    int cont = 0;
    for (int i = 0; i < vlineas.size(); i++) {
        if (vlineas[i].tiempo <= RCLLINEA) {
            cont++;
        }
    }
    return cont;
}


void metaeuristica(linea lineas[], int cantidadlineas, botellas botella[], int cantidadbotellas) {
    int mejormakespan = 99999;
    vector<respuesta> mejor_respuesta;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        vector<botellas> vbotellas;
        vector<linea> vlineas;
        vector<respuesta> respuestaparcial;
        for (int j = 0; j < cantidadbotellas; j++) {
            botellas nodo = botella[j];
            int cantidad = nodo.cantidadbotellas;
            nodo.tiempo = cantidad * (2 + 1 + 3);
            vbotellas.push_back(nodo);
        }
        for (int j = 0; j < cantidadlineas; j++) {
            linea nodo = lineas[j];
            vlineas.push_back(nodo);
        }
        sort(vbotellas.begin(), vbotellas.end(), compararbotellas);

        while (!vbotellas.empty()) {
            sort(vlineas.begin(), vlineas.end(), compararlineas);
            int betalinea = vlineas[0].tiempo;
            int taulinea = vlineas[vlineas.size() - 1].tiempo;
            double RCLLINEA = betalinea + 0.3 * (taulinea - betalinea);
            int indicelinea = buscarindice(RCLLINEA, vlineas);
            int indiceraan = rand() % indicelinea;
            /*-------------------------------------*/

            int betaorden = vbotellas[0].tiempo;
            int tauorden = vbotellas[vbotellas.size() - 1].tiempo;
            double RCLorden = betaorden - 0.3 * (betaorden - tauorden);
            int indiceorden = buscarindiceorden(RCLorden, vbotellas);
            int indicedadoroden = rand() % indiceorden;

            botellas nodobotella = vbotellas[indicedadoroden];
            linea nodolinea = vlineas[indiceraan];

            nodolinea.tiempo += nodobotella.tiempo;

            vlineas[indiceraan]=nodolinea;

            respuesta nodorespuesta;
            nodorespuesta.idorden = nodobotella.idorden;
            nodorespuesta.idlinea = nodolinea.idlinea;
            respuestaparcial.push_back(nodorespuesta);
            vbotellas.erase(vbotellas.begin() + indicedadoroden);
        }
        sort(vlineas.begin(), vlineas.end(), compararlineas);
        if (vlineas[0].tiempo < mejormakespan) {
            mejormakespan = vlineas[0].tiempo;
            mejor_respuesta = respuestaparcial;
        }
    }
    int buscador = 1;
    cout<<"con makespam de: "<<mejormakespan<<endl;
    for (int j = 0; j < 5; j++) {
        cout<<endl;
        cout << "para la opcion de linea " << buscador<<" : ";
        for (int i = 0; i < mejor_respuesta.size(); i++) {
            int info = mejor_respuesta[i].idlinea;

            if (info == buscador) {
                cout << " " << mejor_respuesta[i].idorden;
            }
            //cout << endl;
        }
        buscador++;
    }
}


int main() {
    botellas bot[20] = {
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

    linea linea[5] = {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0}
    };
    metaeuristica(linea, 5, bot, 20);

    return 0;
}
