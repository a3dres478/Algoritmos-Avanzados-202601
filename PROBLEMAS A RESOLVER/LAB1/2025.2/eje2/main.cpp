#include <iostream>
#include <iomanip>
using namespace std;

void backin(int S,int puntero,int sumita,int rpta[],bool usado[]);
void simulacion(int S,int puntero,int sumita,int rpta[],bool usado[],int num);

void simulacion(int S,int puntero,int sumita,int rpta[],bool usado[],int num) {
    if (num>9) {
        return;
    }

    bool infousado=usado[num];
    if (infousado==false) {
        usado[num]=true;
        rpta[puntero]=num;
        backin(S,puntero+1,sumita+num,rpta,usado);
        usado[num]=false;
    }
    simulacion(S,puntero,sumita,rpta,usado,num+1);

}

void backin(int S,int puntero,int sumita,int rpta[],bool usado[]) {
    if (sumita>S) {
        return;
    }

    if (puntero==3) {
        if (S==sumita) {
            int dat1=rpta[0];
            int dat2=rpta[1];
            int dat3=rpta[2];
            if (dat1+dat2+dat3==S && dat1 != dat2 && dat1 != dat3 && dat2 != dat3 ) {
                cout << dat1 << " " << dat2 << " " << dat3 << endl;
            }
            return ;
        }
    }
    simulacion(S,puntero,sumita,rpta,usado,1);

}

int main() {
    int rpta[3]={0,0,0};
    int S=8;
    int rpta1[3] = {0, 0, 0};
    bool usado[10] = {false};

    backin(S, 0, 0, rpta1, usado);

    return 0;
}

