#include <iostream>
#include <iomanip>
#include <fstream>
using namespace  std;
int equipos[4]={4,5,9,2};
int cortes[4];

void imprimir() {
    cout << equipos[0];

    for (int i = 1; i < 4; i++) {
        if (cortes[i - 1] == 1) {
            cout << " "; // nuevo grupo
        }
        cout << equipos[i];
    }

    cout << endl;
}

void backtraking(int pos) {
    if (pos==3) {
        imprimir();
        return;
    }
    cortes[pos]=0;
    backtraking(pos+1);
    cortes[pos]=1;
    backtraking(pos+1);

}

int main() {

backtraking(0);


    return 0;
}