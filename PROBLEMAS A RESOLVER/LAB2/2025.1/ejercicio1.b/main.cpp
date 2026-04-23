#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    int pesos[5]={2,5,5,7,10};
    int M=5;
    int W=25;

    int total=0;
    for(int i=0;i<M;i++) {
        total+=pesos[i];
    }

    bool DP[6][total+1];

    for (int i=0;i<=M;i++) {
        for (int j=0;j<=total;j++) {
            DP[i][j]=false;
        }

    }

    for (int i=0;i<=M;i++) {
        DP[i][0]=true;
    }

    for (int i=1;i<=M;i++) {
        for (int j=0;j<=total;j++) {
            if (pesos[i-1]<=j) {
                DP[i][j]= DP[i-1][j]||DP[i-1][j-pesos[i-1]];


            }else {
                DP[i][j]= DP[i-1][j];
            }
        }
    }


    if (DP[M][W-1]==true) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }

    return 0;
}