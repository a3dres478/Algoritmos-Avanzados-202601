#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <iostream>
#include <iomanip>
using namespace std;

void imprimirDP(bool dp[][1005], int arreglo[], int cantidad, int total) {
    int objetivo = total / 2;
    cout << "\nMatriz DP:\n\n";
    cout << setw(12) << " ";
    for (int j = 0; j <= objetivo; j++) {
        cout << setw(3) << j;
    }
    cout << endl;
    for (int i = 0; i <= cantidad; i++) {
        if (i == 0) {
            cout << setw(12) << "sin elem";
        } else {
            cout << setw(12) << arreglo[i - 1];
        }
        for (int j = 0; j <= objetivo; j++) {
            cout << setw(3) << (dp[i][j] ? 1 : 0);
        }

        cout << endl;
    }

    cout << endl;
}

void subconjuntos(int arreglo[], int total, int cantidad) {
    bool dp[100][1005];
    for (int i = 0; i <= cantidad; i++) {
        for (int j = 0; j <= total / 2; j++) {
            dp[i][j] = false;
        }
    }
    for (int i = 0; i <= cantidad; i++) {
        dp[i][0] = true;
    }


    for (int i = 1; i <= cantidad; i++) {
        for (int j = 1; j <= total / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (arreglo[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arreglo[i - 1]];
            }
        }
    }
    if (dp[cantidad][total / 2] == true) {
        cout << "si se halló" << endl;
        imprimirDP(dp, arreglo, cantidad, total);
    }
}


int main() {
    int arreglo[4] = {1, 5, 11, 5};
    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += arreglo[i];
    }
    if (total % 2 != 0) {
        cout << "no se puede hacer xde" << endl;
    } else {
        subconjuntos(arreglo, total, 4);
    }


    return 0;
}
