#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct aparatos {
    int id;
    int numero;
    vector<int> numerosunidos;
    vector<int> numerosprohibidos;
};

bool esvalido(int matriz[9][9], int ruta[], int posicion, int etiqueta) {
    for (int i = 0; i < 9; i++) {
        if (i == posicion) {
            continue;
        }

        // Si el valor no es 0 ni 1 significa que
        // existe envio de paquetes entre los activos
        //
        // 0 = no hay conexion
        // 1 = diagonal (activo habilitado)
        // 2-9 = cantidad de paquetes enviados

        if (matriz[i][posicion] != 1 && matriz[i][posicion] != 0) {
            // Si el vecino ya tiene la misma etiqueta
            // entonces no es valido
            int data=ruta[i];
            if (ruta[i] == etiqueta) {
                return false;
            }
        }
    }
    return true;
}

bool backtraking(int matriz[9][9], int N, int posicion,  int ruta[]) {
    if (posicion >= N) {
        for (int i = 0; i < 9; i++) {
            if (ruta[i] != -1) {
                cout << ruta[i] << " ";
            }
        }
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (esvalido(matriz, ruta, posicion, i)) {
            ruta[posicion] = i;
            if (backtraking(matriz, N, posicion + 1, ruta)) {
                return true;
            }
            ruta[posicion] = -1;
        }
    }

    return false;
}

int main() {
    int ruta[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int posicion;
    //int arreglo[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};


    int matriz[9][9] = {
        {1, 2, 0, 6, 0, 0, 0, 0, 2},
        {7, 1, 5, 2, 0, 0, 0, 0, 7},
        {0, 3, 1, 2, 3, 8, 9, 7, 5},
        {2, 7, 5, 1, 2, 0, 0, 0, 0},
        {0, 0, 5, 3, 1, 4, 0, 0, 0},
        {0, 0, 9, 0, 6, 1, 2, 0, 0},
        {0, 0, 3, 0, 0, 7, 1, 4, 0},
        {0, 0, 4, 0, 0, 0, 9, 1, 9},
        {5, 3, 6, 0, 0, 0, 0, 4, 1}
    };


    backtraking(matriz, 9, 0, ruta);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    vector<aparatos> vaparatos;
    for (int i = 0; i < 9; i++) {
        aparatos nodo;
        nodo.id = i;
        nodo.numero = -1;
        for (int j = 0; j < 9; j++) {
            int numero = matriz[i][j];
            if (numero != 0 && numero != 1) {
                nodo.numerosunidos.push_back(j);
            }
        }
        vaparatos.push_back(nodo);
    }

    for (int i = 0; i < vaparatos.size(); i++) {
        aparatos nodo = vaparatos[i];
        int numerouniones = nodo.numerosunidos.size();
        for (int j = 0; j < numerouniones; j++) {
            int numerodelasignado = nodo.numerosunidos[j];
            int num = vaparatos[numerodelasignado].numero;
            if (num != -1) {
                nodo.numerosprohibidos.push_back(num);
            }
        }
        int numeroposible = 0;

        while (true) {
            bool bandera = false;
            int cantidades = nodo.numerosprohibidos.size();
            for (int j = 0; j < cantidades; j++) {
                int num = nodo.numerosprohibidos[j];
                if (num == numeroposible) {
                    bandera = true;
                }
            }

            if (bandera == false) {
                break;
            }
            numeroposible++;
        }
        nodo.numero = numeroposible;
        vaparatos[i] = nodo;
    }

    for (int k = 0; k < vaparatos.size(); k++) {
        cout << vaparatos[k].numero + 1 << " ";
    }


    return 0;
}
