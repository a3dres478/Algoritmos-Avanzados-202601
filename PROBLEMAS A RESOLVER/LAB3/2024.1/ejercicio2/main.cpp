#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct paquete {
    int ganancia;
    int peso;
    double relatividad;
};

bool comparar(paquete p1, paquete p2) {
    return p1.relatividad > p2.relatividad;
}

void euristico(paquete matriz[], int n, int maximo) {
    int copiafinal = maximo;
    int totalidad = 0;
    vector<paquete> paquetes2;
    for (int i = 0; i < n; i++) {
        paquete copia = matriz[i];
        if (copia.peso != 0) {
            paquetes2.push_back(copia);
        }
    }
    while (1) {
        if (copiafinal == 0) {
            cout << "SE ENCONTRO UNA SOLUCION QUE LLENE COMPLETAMENTE TODO" << endl;
            break;
        }
        paquete nodo;
        sort(paquetes2.begin(), paquetes2.end(), comparar);

        if (paquetes2[0].peso==0) {
            cout << "no se encontro la mayoria" << endl;
            break;
        }

        //sacamos al mayor y mejor prospecto
        nodo = paquetes2[0];
        int data = nodo.peso;
        if (copiafinal - data >= 0) {
            copiafinal -= data;
            totalidad += nodo.ganancia;
            paquetes2.erase(paquetes2.begin());
        } else {
            cout << "no se puede, sobrepasa por " << data - copiafinal << endl;
            break;
        }
    }
    cout << endl;
    cout << "La ganancia es: " << totalidad << endl;
}

int main() {
    paquete matriz[5] = {
        {10, 2, 10 / 2,}, {15, 3, 15 / 3},
        {10, 5, 10 / 5}, {24, 12, 24 / 12},
        {8, 2, 8 / 2}
    };
    int n = 5;
    int pesomaximo = 16;

    euristico(matriz, n, pesomaximo);


    return 0;
}
