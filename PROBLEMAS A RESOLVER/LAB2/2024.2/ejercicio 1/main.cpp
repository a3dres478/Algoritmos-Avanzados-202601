#include <iostream>
#include <iomanip>

using namespace std;


int max1(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void hijosdeputa(int *ciudades, int n) {
    int maximo;
    int DP[n]{0};
    DP[1] = 1;

    for (int i = 2; i < n; i++) {
        maximo = 9999;
        int borrador1=DP[i-1];
        DP[i] = DP[i - 1];
        for (int j = i; j >= 0; j--) {
            int numerodeciudades = ciudades[j];
            if ((i - j) <= numerodeciudades) {
                int borrador2 = DP[j];
                int borrador3;
                int borrador4 = DP[j]+1;
                borrador3 = max1(maximo, borrador4);
                maximo=borrador3;
            }
        }
        DP[i] = maximo;
    }

    for (int i = 0; i < n; i++) {
        cout << DP[i] << "  ";
    }

    cout << endl << "El avion realizo " << DP[n - 1] << " aterrizajes" << endl;
}

int main() {
    int n = 5;
    int ciudades[n] = {5, 2, 1, 4, 1};
    int n2=6;
    int ciudades2[n2]={1,2,1,4,2,3};



    hijosdeputa(ciudades2, n2);

    return 0;
}
