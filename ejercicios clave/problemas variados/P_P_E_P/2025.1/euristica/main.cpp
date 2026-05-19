#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct ordenes {
    int idorden;
    int cantidad;
    int tiempo;
};

struct maquinas {
    int id;
    int tiempototal;
};

struct respuestas {
    int idlinea;
    int idorden;
};

int main() {
    int lineasdeproduccion = 5;
    int ordenesdeproduccion = 20;

    ordenes listaordenes[20] = {
        {1, 103, 0},
        {2, 58, 0},
        {3, 88, 0},
        {4, 126, 0},
        {5, 195, 0},
        {6, 90, 0},
        {7, 54, 0},
        {8, 195, 0},
        {9, 124, 0},
        {10, 113, 0},
        {11, 193, 0},
        {12, 55, 0},
        {13, 97, 0},
        {14, 97, 0},
        {15, 169, 0},
        {16, 50, 0},
        {17, 167, 0},
        {18, 74, 0},
        {19, 79, 0},
        {20, 109, 0}
    };

	for(int i = 0; i < lineasdeproduccion; i++) {
		ordenes nodo= listaordenes[i];
		nodo.tiempo = nodo.cantidad*6;


	}


	cout<<"xd"<<endl;


    return 0;
}
