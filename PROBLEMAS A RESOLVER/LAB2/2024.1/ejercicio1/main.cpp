#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void dinamico(int arreglo[],int cantidad,int totalaentregar) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += arreglo[i];
    }
    bool dp[cantidad+1][total+1];

    for (int i = 0; i <=cantidad; i++) {
        for (int j = 0; j < total+1; j++) {
            dp[i][j] = false;
        }
    }

    for (int i = 0; i <=cantidad; i++) {
        dp[i][0]= true;
    }

    for (int i = 1; i <= cantidad; i++) {
        for (int j = 1; j <= total; j++) {
            if (arreglo[i-1]<=j) {

                dp[i][j]=dp[i-1][j]||dp[i-1][j-arreglo[i-1]];
            }else {
                dp[i][j] = dp[i-1][j];
            }

        }
    }

    if (dp[cantidad][totalaentregar]) {
        cout << "si se puede csmr"<<endl;
    }else {
        cout << "no se puede "<<endl;
    }



}



int main() {
    int dineros[6]={20,20,50,50,50,100};
    int cantidad=6;
    dinamico(dineros,cantidad,270);

    return 0;
}