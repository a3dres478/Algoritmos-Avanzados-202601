#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct lavadora {
    int numero;
    int enuso;
    int tiempofaltante;
};

struct rpta {
    int numero;
    int totaltiempo;
};

struct ropa {
    int tipo;
    int peso;
    int tiempo;
};


int main() {
    ropa arregloropa[20] = {
        {1, 10, 0},
        {1, 10, 0},
        {2, 8, 0},
        {1, 15, 0},
        {2, 9, 0},
        {2, 11, 0},
        {1, 12, 0},
        {2, 15, 0},
        {1, 6, 0},
        {2, 10, 0},
        {1, 8, 0},
        {2, 15, 0},
        {1, 11, 0},
        {1, 7, 0},
        {1, 7, 0},
        {2, 8, 0},
        {2, 9, 0},
        {1, 11, 0},
        {2, 12, 0},
        {1, 15, 0}
    };

    lavadora arrelavadoras[5] = {
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 0},
        {4, 0, 0},
        {5, 0, 0}
    };




    return 0;
}
