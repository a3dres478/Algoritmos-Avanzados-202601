#include <iostream>
#include <iomanip>
#include <fstream>

using namespace  std;

int dx[8]={-2,-1,1,2, 2, 1,-1,-2};
int dy[8]={ 1, 2,2,1,-1,-2,-2,-1};

bool verificar(int nx,int ny,int tablero[][8]) {
    if (nx>=8 || ny>=8) {
        return false;
    }
    if (nx<0 || ny<0) {
        return false;
    }
    if (tablero[nx][ny]!=0) {
        return false;
    }
    return true;


}

bool caballo(int tablero[][8], int x, int y, int piso) {
    if (piso==64) {
        return true;
    }

    for (int i=0;i<8;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        int copia=tablero[nx][ny];


        bool verificacion=verificar(nx,ny,tablero);
        if (verificacion) {
            tablero[nx][ny]=piso;
            if (caballo(tablero,nx,ny,piso+1)) {
                return true;
            }
            tablero[nx][ny]=copia;
        }

    }
return false;

}

int main() {
    int piso=2;
    int tablero[8][8];
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            tablero[i][j]=0;
        }
    }
    int x=0;
    int y=0;
    tablero[x][y]=1;
    if (caballo(tablero,x,y,piso)) {
        cout<<"Caballo tablero"<<endl;
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                cout<<tablero[i][j]<<" ";
            }
            cout<<endl;
        }
    }else {
        cout<<"Caballo no tablero"<<endl;
    }

    return 0;
}