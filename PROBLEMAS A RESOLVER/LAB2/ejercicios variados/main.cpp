#include <iostream>
#include <iomanip>

using namespace std;

void test1() {
    //problema de cambio de moneda
    int billete[6] = {20, 20, 50, 50, 50, 100};
    int n = 6;
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += billete[i];
    }
    bool dp[n + 1][total + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= total; j++) {
            dp[i][j] = false;
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total; j++) {
            if (billete[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - billete[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    bool rpta = dp[n][230];

    if (rpta == true) {
        cout << "RPTA" << endl;
    } else {
        cout << "NO RPTA" << endl;
    }
    cout << "endl";
}

void test2() {
    int N = 5;
    int datos[5] = {15, 30, 60, 45, 10};

    int robots = 2;

    int dp[robots + 1][N + 1] = {0};

    int flujo[N];

    flujo[0] = 0;

    for (int i = 1; i < N; i++) {
        flujo[i] = datos[i] + flujo[i - 1];
    }

    for (int i = 0; i <= robots; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        dp[1][i] = flujo[i];
    }

    for (int i = 2; i <= robots; i++) {
        for (int j = 2; j <= N; j++) {
            dp[i][j] = 999;
            for (int k = i - 1; k <= j - 1; k++) {
                int datodelultimorobot = flujo[j] - flujo[k];
                int costototal = min(dp[i - 1][k], datodelultimorobot);
                if (costototal < dp[i][j]) {
                    dp[i][j] = costototal;
                }
            }
        }
    }
}


void test3() {
    int N = 11;
    int vuelos[N] = {1, 2, 1, 4, 2, 3, 5, 2, 4, 2, 6};

    int dp[N];
    dp[0] = 0;
    dp[1] = 1;
    int maximo = 999;
    for (int i = 2; i <= N; i++) {
        maximo = 999;
        dp[i] = dp[i - 1];
        for (int j = i; j >= 0; j--) {
            int numerodevuelo = vuelos[j];
            int bajoneado=i-j;
            if (bajoneado <=numerodevuelo) {
                maximo = min(maximo, dp[j]+1);
            }
        }
        dp[i] = maximo;
    }

    for (int i=0;i<N;i++) {
        cout << dp[i] << " ";
    }
}

void test4() {
    int valorbarras[5]={0,2,5,7,8};
    int n=4;
    int dp[n+1]={0};
    dp[1]=valorbarras[0];

    for (int i = 1; i <= n; i++) {
        int maximo=0;
        for (int j = i; j>=1; j--) {
            int data1=valorbarras[j];
            int data2=dp[i-j];
            maximo = max(maximo, data1+data2);


        }
        dp[i] = maximo;

    }


    for (int i = 1; i <= n; i++) {

        cout << dp[i] << " ";
    }


}

void test5() {
    int tiempos[5]={1,3,6,10,16};
    int n=5;
    int turnos =1;
    int maximodeltiempo = turnos*8;

    int dp[100]={0};

    for (int i = 0; i < n; i++) {
        for (int j = maximodeltiempo; j >= tiempos[i]; j--) {
            int data=tiempos[i];
            int data2=dp[j-tiempos[i]];
            if (j==7 and i==2 ) {
                cout<<endl;
            }
            int data3=data+data2;
            if (dp[j-tiempos[i]]+data > dp[j]) {
                dp[j]=dp[j-tiempos[i]]+data;

            }

        }
        for (int l=0;l<maximodeltiempo;l++) {
            cout << dp[l] << " ";
        }
        cout<<endl;

    }



}

void test6() {
    int data[5]={7,2,5,5,10};
    int n=5;

    int suma=0;
    for (int i = 0; i < n; i++) {
        suma = suma + data[i];
    }

    bool dp[n+1][suma+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= suma; j++) {
            dp[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= suma; j++) {
            if (data[i-1]<=j) {

                dp[i][j] = dp[i-1][j] || dp[i-1][j-data[i-1]];
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    bool rpta=dp[n+1][24];
    if (rpta) {
        cout<<"RPTA"<<endl;
    }else {
        cout<<"NO RPTA"<<endl;
    }

}


void test7() {
    int matriz[6][6]={
        /*0*/{ 0,3,5,0,0,0},
        /*1*/{ 0,0,3,2,1,0},
        /*2*/{ 0,0,0,2,3,0},
        /*3*/{ 0,0,0,0,1,6},
        /*4*/{ 0,0,0,0,0,3},
        /*5*/{ 0,0,0,0,0,0}
    };

    int dp[6]={0};
    for (int i=0; i<6; i++) {
        dp[i] =999;
    }
    dp[0]=0;
    int rpta[6]={};
    for (int i = 0; i < 6; i++) {
        rpta[i] = -1;
    }


    int minimo = 999;
    for (int i = 1; i < 6; i++) {
        minimo=999;
        for (int j = 0; j < i; j++) {
            int numeromatriz = matriz[j][i];
            if (numeromatriz!=0) {
                int data3=dp[j]+numeromatriz;
                int data4=dp[i];
                if (dp[j]+numeromatriz < dp[i]) {
                    dp[i]=dp[j]+numeromatriz;
                    rpta[i] = j;
                }

            }

        }


    }

    cout<<dp[5]<<endl;
    for (int i = 0; i < 6; i++) {
        cout << rpta[i] << " ";
    }


}

int main() {
    //pregunta 1 del 2024.1
    //test1();
    //pregunta 2 del 2024.1
    test2();
    //pregunta 1 del 2024.2
    //test3();
    //pregunta 2 del 2024.2
    //test4();
    //pergunta 1a del 2025.1
    //test5();
    //pregunta 1b del 2025.2
    //test6();
    //pregunta 2 del 2025.2
    //test7();

    return 0;
}
