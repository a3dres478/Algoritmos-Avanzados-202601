#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    int n = 6;

    // Matriz de costos
    int costo[6][6] = {
        {0,3,5,0,0,0},
        {0,0,3,2,1,0},
        {0,0,0,2,3,0},
        {0,0,0,0,1,6},
        {0,0,0,0,0,3},
        {0,0,0,0,0,0}
    };

    int dp[n];//<-va a ser usado como guia bandera
    for(int i=0;i<n;i++) {
        dp[i]=9999;
    }

    int respuestas[n];
    for(int i=0;i<n;i++) {
        respuestas[i]=-1;
    }

    dp[0]=0;

    for (int j=1;j<n;j++) {
        for (int i=0;i<j;i++) {
            int numerito=costo[i][j];
            if (costo[i][j]!=0) {
                if (dp[i]+costo[i][j]<dp[j]) {
                    dp[j]=dp[i]+costo[i][j];
                    respuestas[j]=i;
                }
            }
        }
    }

    cout << dp[5] << endl;

    for (int i=0;i<n;i++) {
        cout << respuestas[i] << " ";
    }


    return 0;
}