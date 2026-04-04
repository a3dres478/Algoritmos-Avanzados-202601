#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Matriz general
int mejor=0;
int matrizfinal[3][6];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,-1,-1,-1,0,1,1,1};


bool analisis(int nuevox,int nuevoy,int matriz[][6],int filas,int columnas) {
    if (nuevoy==0 && nuevox==0) {
        return false;
    }
    if (matriz[nuevox][nuevoy]==1) {
        return false;
    }
    for (int i=0;i<8;i++) {
        int newx=nuevox+dx[i];
        int newy=nuevoy+dy[i];
        if (newx>=0 && newx<filas && newy>=0 && newy<columnas) {
            //ya existe una respuesta
            if (matriz[newx][newy]==1) {
                return false;
            }
        }
    }
    return true;
}


void backtracking(int matriz[][6],int ubix,int ubiy,int casillascontadas,int filas,int columnas) {
    //analisamos el fin del tablero
    if (ubix==filas ) {
        // se reemplaza el encontrado con la variable global del mejor
        if (casillascontadas>mejor) {
            mejor=casillascontadas;
            /*Copiamos la matriz que fue necesaria para que se haga el cambio*/
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }

            //se reemplaza en su totalidad los datos obtenidos
            for (int i=0;i<filas;i++) {
                for (int j=0;j<columnas;j++) {
                    matrizfinal[i][j]=matriz[i][j];
                }
            }

        }
        return;
    }

    //movemos el apartado base, recordando que x es filas y Y columnas
    int dx1=ubix;
    int dy1=ubiy+1;

    if (dy1==columnas) {
        dx1++;
        dy1=0;
    }

    //se hace el recorrrido denuevo con los datos, esto parece que no hace cambios pero si lo hace
    //porque si se agregan datos nuevos se van a ir reemplazando
    backtracking(matriz,dx1,dy1,casillascontadas,filas,columnas);
    //se analiza la informacion
    if (analisis(ubix,ubiy,matriz,filas,columnas)) {
        matriz[ubix][ubiy]=1;

        backtracking( matriz, dx1, dy1, casillascontadas+1, filas, columnas);

        matriz[ubix][ubiy]=0;
    }
}

int main() {
    //llamado de funciones necesarias
    int filas=3,columnas=6;
    int ubix=0;
    int ubiy=0;
    int cantidades=0;
    int matriz[3][6];
    for(int i=0;i<3;i++) {
        for(int j=0;j<6;j++) {
            matriz[i][j]=0;
        }
    }
    //el problema es sencillo pero es complicado de comprender en un primer momento
    //no nos pide encontrar el primero sino el mejor, entonces se necesita un void, no un bool
    backtracking( matriz, ubix, ubiy, cantidades, filas, columnas);
    cout<<"casillas colocadas "<<mejor<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matrizfinal[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


