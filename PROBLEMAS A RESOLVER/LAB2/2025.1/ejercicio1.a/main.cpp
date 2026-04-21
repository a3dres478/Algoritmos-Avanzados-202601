#include <iostream>
#include <iomanip>
using namespace  std;

int main() {
    int tareatiempos[5]={1,3,6,10,16};
    int n=5;
    int turnos=1;

    int maximodetiempo=turnos*8;


    int dp[100]={0};

    for (int i=0;i<n;i++) {
        int maximo=999;
        //          8                       6
        for (int j=maximodetiempo;j>=tareatiempos[i];j--) {

            int data1=tareatiempos[i];

            if (dp[j-tareatiempos[i]]+data1>dp[j]) {
                dp[j]=dp[j-tareatiempos[i]]+data1;

            }
            cout<<"para J: "<<j<<" || e i "<<i<<" ---- ";
            for (int k=0;k<maximodetiempo;k++) {
                cout<<dp[k]<<" ";
            }
            cout<<endl;


        }

    }
    cout<<dp[maximodetiempo];
    return 0;
}