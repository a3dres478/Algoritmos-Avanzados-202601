#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct paises {
    int id;
    int colorasignado;
    vector<int> coloresprohibidos;
    vector<int> vecinos;
};

bool comparacionid(struct paises p1, struct paises p2) {
    return p1.id < p2.id;
}

int main() {
    int mapa[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    //el pais inicial es el pais 0

    vector<paises> vpaises;
    for (int i = 0; i < 6; i++) {
        paises nodo;
        nodo.colorasignado = -1;
        nodo.id = i;
        for (int j = 0; j < 6; j++) {
            int numero = mapa[i][j];
            if (numero != 0) {
                // cout<<j<<" ";
                nodo.vecinos.push_back(j);
            }
        }
        vpaises.push_back(nodo);
    }

    //ahora se inicia el apartado para ver q tiene

    sort(vpaises.begin(), vpaises.end(), comparacionid);

    for (int i = 0; i < vpaises.size(); i++) {
        paises nodo = vpaises[i];
        int posiblecolor = 0;
        //analizamos los vecinos
        int canticolores = nodo.coloresprohibidos.size();
        //vecinos del pais actual;
        for (int j = 0; j < nodo.vecinos.size(); j++) {
            int numerodelpais = nodo.vecinos[j];
            paises nodoanalisis = vpaises[numerodelpais];
            int iddelpaiesanalisis = nodoanalisis.id;
            int colorasignado= nodoanalisis.colorasignado;
            if (nodoanalisis.colorasignado != -1) {
                nodo.coloresprohibidos.push_back(colorasignado);
            }
        }


        while (true) {
            bool prohibido = false;

            for (int j=0;j<nodo.coloresprohibidos.size();j++) {
                if (nodo.coloresprohibidos[j] == posiblecolor) {
                    prohibido = true;
                }
            }
            if (prohibido ==false) {
                break;
            }
            posiblecolor++;

        }

        nodo.colorasignado = posiblecolor;
        vpaises[i] = nodo;


    }

    for (int h = 0; h < vpaises.size(); h++) {
        paises nodonuevo = vpaises[h];
        cout << nodonuevo.id << " con el color: " << nodonuevo.colorasignado << endl;
    }


    return 0;
}
