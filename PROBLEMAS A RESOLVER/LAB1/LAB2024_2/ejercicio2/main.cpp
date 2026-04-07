#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int capacidadesori[5] = {3, 2, 5, 1, 3};
int cantidadesori[4] = {2, 3, 1, 4};

void imprimirarreglo(int arr[],int tamanio) {
    for (int i = 0; i < 15; i++) {
        cout<<"____";
    }
    cout<<endl;
    for (int i = 0; i < tamanio; i++) {
        cout << arr[i] << " ";

    }
    cout << endl;
    for (int i = 0; i < 15; i++) {
        cout<<"____";
    }
    cout<<endl;
}

void backtraking(int capa[], int canti[], int ubicap, int ubican,int usados[]) {
    if (ubican == 4) {

            for (int j = 0; j < 5; j++) {
                cout << usados[j] << " ";
            }
            cout << endl;


        return;
    }

    int cantidades = canti[ubican];

    for (int i = 0; i < 5; i++) {
        int numero = capa[i];
        if (numero >= cantidades) {
            capa[i] -= cantidades;
            usados[i] += cantidades;
            //imprimirarreglo(capa,5);
            //imprimirarreglo(usados,5);
            backtraking(capa, canti, ubicap, ubican + 1,usados);
            capa[i] += cantidades;
            usados[i] -= cantidades;
            //imprimirarreglo(capa,5);
            //imprimirarreglo(usados,5);
        }
    }
}


int main() {
    int N = 4;
    int M = 5;

    int ubi = 0;

    int capa[5] = {3, 2, 5, 1, 3};
    int canti[4] = {2, 3, 1, 4};
int usados[5]={};
    backtraking(capa, canti, ubi, ubi,usados);


    return 0;
}
