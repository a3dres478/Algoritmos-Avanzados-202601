#include <iostream>
#include <iomanip>
using namespace  std;

int main() {
    int barraprecios[5]={0,2,5,7,8};
    int n=4;

    int dp[n+1]={0};
    dp[1]=barraprecios[0];

    for (int i=1; i<=n; i++) {
        int mejor=0;

        for (int j=1; j<=i; j++) {
            int data1=barraprecios[j];
            int data2=dp[i-j];
            int data3=data1+data2;
            mejor=max(mejor,data3);


        }
        dp[i]=mejor;
    }
    cout << "Tabla DP:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    cout << "\nLa maxima ganancia para una barra de longitud "
         << n << " es: " << dp[n] << endl;



    return 0;
}