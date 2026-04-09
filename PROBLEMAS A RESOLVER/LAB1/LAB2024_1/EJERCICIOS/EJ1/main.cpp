#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void backtraking(int tablas[], int respuesta[], int kmax, int Peso, int pesoanterior, int puntero, int usado) {
    if (Peso == 0) {
        cout << "{ ";
        for (int i = 0; i < usado; i++) {
            if (respuesta[i] != 0) {
                cout << respuesta[i] << " ";
            }
        }
        cout << " }" << endl;
        return;
    }


    if (Peso < 0) {
        return;
    }

    for (int i = puntero; i < 6; i++) {
        int numero = tablas[i];
        tablas[i] = 0;
        bool valido = (usado == 0);

        for (int j = 0; j < usado; j++) {
            if (abs(numero - respuesta[j]) <= kmax && numero !=0) {
                valido = true;
                break;
            }
        }

        if (!valido) {
            continue;
        }
        respuesta[usado] = numero;
        backtraking(tablas, respuesta, kmax, Peso - numero, numero, i + 1, usado + 1);
        respuesta[usado] = 0;
        tablas[i] = numero;
    }
}


int main() {
    int p = 15;
    int k = 4;
    int tablas[6] = {2, 8, 9, 6, 7, 6};
    int respuestas[6] = {};
    backtraking(tablas, respuestas, k, p, 0, 0,0);
    cout << "endl" << endl;

    return 0;
}
