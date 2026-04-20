#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int programaciondinamica(int robots,int arreglo[],int cantidades) {
    int F[cantidades+1];
    int dp[robots+1][cantidades+1];
    F[0] = 0;


    //caso que es solo 1 robot
    for (int i=1; i<=cantidades; i++) {
        F[i]=F[i-1]+arreglo[i];
    }

    //llenamos el dp
    for (int i=0;i<=robots;i++) {
        for (int j=0; j<=cantidades; j++) {
            dp[i][j]=0;
        }
    }

    for (int i=1;i<=cantidades;i++) {
        dp[1][i]=F[i];
    }

    for (int i=2;i<=robots;i++) {
        for (int j=2;j<=cantidades;j++) {
            dp[i][j]=999;
            for (int k=i-1;k<=j-1;k++) {
                int costoultimorobot=F[j]-F[k];
                int costotoal=max(dp[i-1][k],costoultimorobot);
                if (costotoal<dp[i][j]) {
                    dp[i][j]=costotoal;
                }

            }

        }
    }
    // Imprimir matriz DP
    cout << "Matriz DP:\n\n";
    cout << setw(10) << " ";
    for (int j = 1; j <= cantidades; j++) {
        cout << setw(8) << j;
    }
    cout << endl;

    for (int i = 1; i <= robots; i++) {
        cout << setw(10) << ("Robot" + to_string(i));
        for (int j = 1; j <= cantidades; j++) {
            cout << setw(8) << dp[i][j];
        }
        cout << endl;
    }

    cout << "\nTiempo minimo del maximo para " << robots
         << " robots y " << cantidades << " tareas: "
         << dp[robots][cantidades] << " min" << endl;

    return 1;

}


int main() {
    int Ntareas[6]={0,15,30,60,45,10};
    int Rrobots=2;
programaciondinamica(Rrobots,Ntareas,6);




    return 0;
}