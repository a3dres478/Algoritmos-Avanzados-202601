#include <iostream>
#include <iostream>
using namespace std;

int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={1,1,1,0,-1,-1,-1,0};


bool verificar(int filas,int columnas,int matrix[][8],int newx,int newy) {
    if (newx<0 || newx>=filas || newy<0 || newy>=columnas) {
        return false;
    }
    int copia=matrix[newx][newy];
    if (copia!=0) {
        return false;
    }
    return true;
}

bool verificar2(int matrix[][8],int filas,int columnas) {
    int sumaRef = 0;
    for (int j = 0; j < columnas; j++) {
        sumaRef += matrix[0][j];
    }

    // Verificar filas
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += matrix[i][j];
        }
        if (suma != sumaRef) return false;
    }

    // Verificar columnas
    for (int j = 0; j < columnas; j++) {
        int suma = 0;
        for (int i = 0; i < filas; i++) {
            suma += matrix[i][j]; // ✔ correcto
        }
        if (suma != sumaRef) return false;
    }

    // Diagonal principal
    int diag1 = 0;
    for (int i = 0; i < filas; i++) {
        diag1 += matrix[i][i];
    }
    if (diag1 != sumaRef) return false;

    // Diagonal secundaria
    int diag2 = 0;
    for (int i = 0; i < filas; i++) {
        diag2 += matrix[i][columnas - 1 - i];
    }
    if (diag2 != sumaRef) {
        return false;
    }
}

bool backing2(int matrix[][8],int filas,int columnas,int ubix,int ubiy,int posi) {
    if (filas*columnas==posi-1) {
        cout<<endl;

        bool veri2=verificar2(matrix,filas,columnas);
        if (veri2) {
            for (int i=0;i<filas;i++) {
                for (int j=0;j<columnas;j++) {
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
            return true;
        }else {
            return false;
        }



    }
    for (int i=0;i<8;i++) {
        int newx=dx[i]+ubix;
        int newy=dy[i]+ubiy;
        if (verificar(filas,columnas,matrix,newx,newy)) {
            int copia=matrix[newx][newy];
            matrix[newx][newy]=posi;
            if (backing2(matrix,filas,columnas,newx,newy,posi+1)) {
                return true;
            }
            matrix[newx][newy]=copia;
        }
    }
    return false;
}




bool backing(int matrix[][8],int filas,int columnas,int ubix,int ubiy,int posi) {
    if (filas*columnas==posi-1) {
        cout<<endl;
        for (int i=0;i<filas;i++) {
            for (int j=0;j<columnas;j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for (int i=0;i<8;i++) {
        int newx=dx[i]+ubix;
        int newy=dy[i]+ubiy;
        if (verificar(filas,columnas,matrix,newx,newy)) {
            int copia=matrix[newx][newy];
            matrix[newx][newy]=posi;
            if (backing(matrix,filas,columnas,newx,newy,posi+1)) {
                return true;
            }
            matrix[newx][newy]=copia;
        }
    }
    return false;
}

int main() {

    int filas=8;
    int columnas=8;
    int ubix=4;
    int ubiy=4;
    int matriz[8][8];
    for (int i=0;i<filas;i++) {
        for (int j=0;j<columnas;j++) {
            matriz[i][j]=0;
        }
    }

    //bool verifica=backing(matriz,filas,columnas,ubix,ubiy,1);
    bool verifica2=backing(matriz,filas,columnas,ubix,ubiy,1);


    return 0;
}