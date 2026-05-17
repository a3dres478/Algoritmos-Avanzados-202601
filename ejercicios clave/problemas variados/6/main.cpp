#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct barra {
    int longitud;
};

struct pedido {
    int id;
    int dimension;
    int cantidad;
    int ganancia;
    double rinha;
};

bool comparacionbarra(barra a, barra b) {
    return a.longitud < b.longitud;
}

bool comparacionratio(pedido p1, pedido p2) {
    return p1.rinha > p2.rinha;
}

bool comparaciondimen(pedido p1, pedido p2) {
    return p1.dimension > p2.dimension;
}

int main() {
    pedido pedidos[5] = {
        {1, 10, 5, 10, 0},
        {2, 20, 10, 20, 0},
        {3, 1, 18, 15, 0},
        {4, 3, 1, 5, 0},
        {5, 1, 1, 2, 0}
    };
    vector<pedido> peds;
    for (int i = 0; i < 5; i++) {
        int ganan = pedidos[i].ganancia;
        int canti = pedidos[i].cantidad;
        pedidos[i].rinha = (double) ganan / canti;
        peds.push_back(pedidos[i]);
    }
    sort(peds.begin(), peds.end(), comparaciondimen);
    vector<pedido> vpedidos;

    for (int i = 0; i < peds.size(); i++) {
        if (peds[i].dimension <= 10) {
            vpedidos.push_back(peds[i]);
        }
    }
    sort(vpedidos.begin(), vpedidos.end(), comparacionratio);

    peds.erase(peds.begin(), peds.end());


    barra b;
    b.longitud = 10;
    vector<barra> vectorbarra;

    vectorbarra.push_back(b);
    int barrasusadas = 1;
    bool pedidocompleto = true;
    int gananciatotal = 0;
    for (int i = 0; i < vpedidos.size(); i++) {
        int cantidadpedidos = vpedidos[i].cantidad;
        int dimensionpedidos = vpedidos[i].dimension;

        for (int j = 0; j < cantidadpedidos; j++) {
            int mejorbarra = -1;
            int menorsobrante = 9999;

            for (int k = 0; k < vectorbarra.size(); k++) {
                if (vectorbarra[k].longitud >= dimensionpedidos) {
                    int sobrante = vectorbarra[k].longitud - dimensionpedidos;
                    if (sobrante < menorsobrante) {
                        menorsobrante = sobrante;
                        mejorbarra = k;
                    }
                }
            }
            if (mejorbarra == -1) {
                if (barrasusadas < 20) {
                    barra nueva;
                    nueva.longitud = 10 - dimensionpedidos;
                    vectorbarra.push_back(nueva);
                    barrasusadas++;
                } else {
                    pedidocompleto = false;
                    break;
                }
            }
        }


        if (pedidocompleto) {
            gananciatotal += pedidos[0].ganancia;
            cout << "pedido atendido " << vpedidos[i].id << endl;
        } else {
            cout << "pedido no atendido" << vpedidos[i].id << endl;
        }
    }

    cout << "gnaancia total: " << gananciatotal << endl;

    return 0;
}
