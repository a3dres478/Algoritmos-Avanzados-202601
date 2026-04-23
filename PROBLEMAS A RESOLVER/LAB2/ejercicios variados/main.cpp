#include <iostream>
#include <iomanip>

using namespace std;

void test1() {
    //problema de cambio de moneda
    int billete[6]={20,20,50,50,50,100};
    int n=6;
    int total=0;
    for (int i=0;i<n;i++) {
        total+=billete[i];
    }
    bool dp[n+1][total+1];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=total;j++) {
            dp[i][j]=false;
        }
    }
    for ( int i=0;i<=n;i++) {
        dp[i][0]=true;
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=total;j++) {
            if (billete[i-1]<=j) {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-billete[i-1]];
            }else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    bool rpta=dp[n][230];

    if (rpta==true) {
        cout<<"RPTA"<<endl;
    }else {
        cout<<"NO RPTA"<<endl;
    }
cout<<"endl";


}
void test2() {

    int N=5;
    int datos[5]={15,30,60,45,10};

    int robots=2;

    int dp[robots+1][N+1]={0};

    int flujo[N];

    flujo[0]=0;

    for (int i=1;i<robots;i++) {
        flujo[i]=datos[i]+flujo[i-1];
    }

    for (int i=0;i<=robots;i++) {
        for (int j=0;j<=robots;j++) {
            dp[i][j]=0;
        }
    }

    for (int i=1;i<=N;i++) {
        dp[1][i]=flujo[i];
    }

        for (int i=2;i<=robots;i++) {
            for (int j=2;j<=N;j++) {
                dp[i][j]=999;
                for (int k=i-1;k<=j-1;k++) {
                    int datodelultimorobot=flujo[j]-flujo[k];
                    int costototal=min(dp[i-1][k],datodelultimorobot);
                    if (costototal<dp[i][j]) {
                        dp[i][j]=costototal;
                    }
                }

            }
        }





}



int main() {
    //pregunta 1 del 2024.1
    //test1();
    test2();


    return 0;
}