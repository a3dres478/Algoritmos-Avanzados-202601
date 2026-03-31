#include <iostream>
#include <iomanip>
using namespace  std;


void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {           // filas
        for (int j = 0; j < n; j++) {       // columnas
            if (arr[j] == i)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool analisis1(int arr[],int fila,int n,int columna) {
 /*   bool filtro1=true;
    bool filtro2=true;
    for (int i=0;i<n;i++) {
        int data=arr[i];
        if (data==fila) {
            filtro1=false;
        }else {
            if (data==-1) {
                break;
            }
        }
    }
    for (int i=0;i<columna;i++) {
        int data=arr[i];
        int columnas=abs(data-columna);
        int filas=abs(i-fila);
        if (columnas==filas) {
            filtro2=false;
        }

    }
    if (!filtro1 || !filtro2) {
        return false;
    }else {
        return true;
    }

*/
    for (int i = 0; i < columna; i++) {

        // misma fila
        if (arr[i] == fila)
            return false;

        // diagonal
        if (abs(arr[i] - fila) == abs(i - columna))
            return false;
    }
    return true;


}

bool esposible(int arr[],int limitemax,int limiteactual) {
    if (limitemax==limiteactual) {
        cout<<"VAMOO"<<endl;
        return true;
    }
    for (int i=0;i<limitemax;i++) {
        bool analisis=analisis1(arr,i,limitemax,limiteactual);
        int copialimiteactual=limiteactual;

        if (analisis) {
            arr[limiteactual]=i;
            limiteactual++;
            bool next1=esposible(arr,limitemax,limiteactual);

            if (next1) {
                return true;
            }
                arr[copialimiteactual]=-1;
                limiteactual=copialimiteactual;

        }else {
            limiteactual=copialimiteactual;
        }


    }
    return false;
}

int main() {
    int n=9;
    int arr[n];
    //llenado de arreglo
    for (int i=0;i<n;i++) {
        arr[i]=-1;
    }
    int limitemax=n;
    bool confirmacion=esposible(arr,limitemax,0);

if (confirmacion==true) {
    cout<<"Si existe una combinación"<<endl;
    imprimir(arr,n);
}else {
    cout<<"No existe una combinación"<<endl;
}

    return 0;
}