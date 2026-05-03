#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;

struct nodo {
    int punto;
    int distancia;
};

bool compara(nodo nodo1, nodo nodo2) {
    return nodo1.distancia < nodo2.distancia;
}

int ruta(int ini, int fin, int matriz[][8]) {
    int ciudad = ini;
    int destino = fin;
    int total = 0;

    while (1) {
        vector<nodo> vecinos;
        nodo paso;
        for (int i = 0; i < 8; i++) {
            if (matriz[ciudad][i] != 0) {
                paso.punto = i;
                paso.distancia = matriz[ciudad][i];
                vecinos.push_back(paso);
            }
        }
        if (!vecinos.empty()) {
            sort(vecinos.begin(), vecinos.end(), compara);
            ciudad = vecinos[0].punto;
            total += vecinos[0].distancia;
        }
        if (ciudad==destino) {
            cout<<"SI HAY SOLUCION "<<endl;
            break;
        }

        if (vecinos.empty()) {
            cout << "no existe solucion" << endl;
            total = 0;
            break;
        }
    }
    return total;
}

int main() {
    int matriz[8][8] = {
        {0, 4, 5, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
        cout<<"-------"<<endl;
        cout << ruta(3, 6, matriz);


    return 0;
}
