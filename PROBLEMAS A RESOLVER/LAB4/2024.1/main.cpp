#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
#define iteraciones 10000
#define alfa 0.3

struct tablas {
    int id;
    int capacidad;
    int velocidad;
};

struct discos {
    int id;
    int capacidad;
    int velocidad;
};

struct respuesta {
    int idtabla;
    int iddisco;
};

bool comparartablas(tablas a, tablas b) {
    if (a.velocidad == b.velocidad) {
        return a.capacidad > b.capacidad;
    } else {
        return a.velocidad > b.velocidad;
    }
}

bool comparardiscos(discos a, discos b) {
    if (a.velocidad == b.velocidad) {
        return a.capacidad > b.capacidad;
    } else {
        return a.velocidad > b.velocidad;
    }
}

bool comparardisco2(discos a, discos b) {
    return a.velocidad < b.velocidad;
}

int buscarindicetabla(double RCLTabla, vector<tablas> vtablas) {
    int cont = 0;
    for (int i = 0; i < vtablas.size(); i++) {
        if (vtablas[i].velocidad >= RCLTabla) {
            cont++;
        }
    }
    return cont;
}


int buscarindicedisco(double RCLTabla, vector<discos> vtablas) {
    int cont = 0;
    for (int i = 0; i < vtablas.size(); i++) {
        if (vtablas[i].velocidad >= RCLTabla) {
            cont++;
        }
    }
    return cont;
}

// Devuelve solo los discos donde la tabla sí puede entrar.
vector<discos> obtenerdiscosfactibles(vector<discos> vdiscos, tablas tabla) {
    vector<discos> factibles;

    for (int i = 0; i < vdiscos.size(); i++) {
        if (vdiscos[i].capacidad >= tabla.capacidad &&
            vdiscos[i].velocidad >= tabla.velocidad) {
            factibles.push_back(vdiscos[i]);
        }
    }

    return factibles;
}

int buscarPosicionDisco(vector<discos> vdiscos, int iddisco) {
    for (int i = 0; i < vdiscos.size(); i++) {
        if (vdiscos[i].id == iddisco) {
            return i;
        }
    }

    return -1;
}

void metaeuristica(tablas listatabla[], int cantidatabla, discos listadiscos[], int cantidadiscos) {
    int mejorcaso = -1;
    srand(time(NULL));
    vector<respuesta> mejor_respuesta;
    vector<discos> mejores_discos;
    for (int i = 0; i < iteraciones; i++) {
        vector<tablas> vtablas;
        for (int j = 0; j < 6; j++) {
            vtablas.push_back(listatabla[j]);
        }
        vector<discos> vdicos;
        for (int j = 0; j < 3; j++) {
            vdicos.push_back(listadiscos[j]);
        }
        sort(vtablas.begin(), vtablas.end(), comparartablas);

        vector<respuesta> respuestaitera;
        bool solucioncompleta = true;
        while (!vtablas.empty()) {
            int betatabla = vtablas[0].velocidad;
            int taux = vtablas[vtablas.size() - 1].velocidad;
            double RCLTabla = betatabla - alfa * (betatabla - taux);
            int indectabla = buscarindicetabla(RCLTabla, vtablas);
            int indatabla = rand() % indectabla;
            tablas nodotabla = vtablas[indatabla];
            vector<discos> discosfactibles = obtenerdiscosfactibles(vdicos, nodotabla);
            if (discosfactibles.empty()) {
                solucioncompleta = false;
                break;
            }
            sort(discosfactibles.begin(), discosfactibles.end(), comparardiscos);
            int betadisco = discosfactibles[0].velocidad;
            int tauxdisco = discosfactibles[discosfactibles.size() - 1].velocidad;
            double RCLDisco = betadisco - alfa * (betadisco - tauxdisco);
            int indecdisco = buscarindicedisco(RCLDisco, discosfactibles);
            int indadisco = rand() % indecdisco;


            discos nododiscos = discosfactibles[indadisco];
            int posicionDisco = buscarPosicionDisco(vdicos, nododiscos.id);

            vdicos[posicionDisco].capacidad -= nodotabla.capacidad;
            vdicos[posicionDisco].velocidad -= nodotabla.velocidad;

            // Guardamos la asignación tabla-disco.
            respuesta nodorespuesta;
            nodorespuesta.iddisco = nododiscos.id;
            nodorespuesta.idtabla = nodotabla.id;
            respuestaitera.push_back(nodorespuesta);

            // Eliminamos la tabla porque ya fue asignada.
            vtablas.erase(vtablas.begin() + indatabla);
        }
        //cout << "salio " << endl;
        if (solucioncompleta) {
            sort(vdicos.begin(), vdicos.end(), comparardisco2);

            if (vdicos[0].velocidad > mejorcaso) {
                mejor_respuesta = respuestaitera;
                mejorcaso = vdicos[0].velocidad;
                mejores_discos=vdicos;
            }
        }
    }

    /*cout << "RESPUESTAS FINALES" << endl;

    for (int k = 0; k < 3; k++) {
        int idk = k;
        cout << "para el disco: " << idk + 1 << ": ";
        for (int j = 0; j < mejor_respuesta.size(); j++) {
            respuesta nodo = mejor_respuesta[j];
            if (nodo.iddisco == idk) {
                cout << nodo.idtabla << " ";
            }
        }
        cout << endl;
    }*/
    cout << "RESPUESTAS FINALES" << endl;
    cout << "Mejor velocidad minima restante: " << mejorcaso << endl;
    cout << endl;

    for (int k = 0; k < cantidadiscos; k++) {
        int idk = k + 1;

        cout << "Para el disco " << idk << ": ";

        for (int j = 0; j < mejor_respuesta.size(); j++) {
            respuesta nodo = mejor_respuesta[j];

            if (nodo.iddisco == idk) {
                cout << "Tabla " << nodo.idtabla << " ";
            }
        }

        cout << endl;
    }

    cout << endl;
    cout << "Estado final de discos:" << endl;

    for (int i = 0; i < mejores_discos.size(); i++) {
        cout << "Disco " << mejores_discos[i].id
             << " | Capacidad restante: " << mejores_discos[i].capacidad
             << " | Velocidad restante: " << mejores_discos[i].velocidad
             << endl;
    }
}


int main() {
    tablas listatablas[6] = {
        {1, 20, 150},
        {2, 10, 100},
        {3, 15, 80},
        {4, 100, 50},
        {5, 50, 120},
        {6, 100, 10}
    };

    discos discosa[3] = {
        {1, 800, 250},
        {2, 750, 200},
        {3, 850, 200}
    };

    metaeuristica(listatablas, 6, discosa, 3);

    return 0;
}
