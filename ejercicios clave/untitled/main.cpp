#include <iostream>
#include <iomanip>
using namespace  std;

void imprimirDP(bool dp[][100], int arreglo[], int cantidad, int total) {
    int objetivo = total;

    cout << "\nTabla DP (1 = se puede, 0 = no se puede)\n\n";

    // Encabezado de columnas (sumas j)
    cout << setw(10) << " ";
    for (int j = 0; j <= objetivo; j++) {
        cout << setw(3) << j;
    }
    cout << endl;

    // Filas (i)
    for (int i = 0; i <= cantidad; i++) {

        if (i == 0) {
            cout << setw(10) << "ninguno";
        } else {
            cout << setw(10) << arreglo[i - 1];
        }

        for (int j = 0; j <= objetivo; j++) {
            cout << setw(3) << (dp[i][j] ? 1 : 0);
        }

        cout << endl;
    }

    cout << endl;
}

int diferenciaminima(int arreglo[],int cantidad) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += arreglo[i];
    }

    bool dp[100][100];
    for (int i = 0; i <=cantidad; i++) {
        for (int j = 0; j <= total; j++) {
            dp[i][j] = false;
        }
    }
    for (int i = 0; i <= cantidad; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= cantidad; i++) {
        for (int j = 1; j <= total; j++) {
            if (arreglo[i-1]<=j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arreglo[i-1]];
            }else {
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    imprimirDP(dp, arreglo, cantidad, total);

    int mejor=0;

        for (int j = total/2; j>=0; j--) {
            if (dp[cantidad][j]) {
                mejor=j;
                break;
            }
        }

    return total-2*mejor;



}

int main() {
    int arreglo[4]={1,6,11,5};
    int cantidad=4;
    cout<<"totalidad "<<diferenciaminima(arreglo, cantidad)<<endl;


    return 0;
}