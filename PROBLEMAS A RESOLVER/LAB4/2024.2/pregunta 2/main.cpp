#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define alfa 0.4

struct puntos {
    int punto;
    int precio;
    vector<puntos>lista_de_puntos;
};

// Crea un punto con su código y su precio
puntos crearPunto(int punto, int precio) {
    puntos p;
    p.punto = punto;
    p.precio = precio;
    return p;
}

vector<puntos> generarDatos() {
    vector<puntos> grafo;

    // Creamos los puntos principales
    // A no tiene precio porque es el punto de partida
    puntos A = crearPunto(0, 0);
    puntos B = crearPunto(1, 20);
    puntos C = crearPunto(2, 30);
    puntos D = crearPunto(3, 40);
    puntos E = crearPunto(4, 40);
    puntos F = crearPunto(5, 40);
    puntos G = crearPunto(6, 10);
    puntos H = crearPunto(7, 50);

    // A -> B C D E H
    A.lista_de_puntos.push_back(B);
    A.lista_de_puntos.push_back(C);
    A.lista_de_puntos.push_back(D);
    A.lista_de_puntos.push_back(E);
    A.lista_de_puntos.push_back(H);

    // B -> C D F H
    B.lista_de_puntos.push_back(C);
    B.lista_de_puntos.push_back(D);
    B.lista_de_puntos.push_back(F);
    B.lista_de_puntos.push_back(H);

    // C -> F
    C.lista_de_puntos.push_back(F);

    // D -> no tiene destinos

    // E -> C F G
    E.lista_de_puntos.push_back(C);
    E.lista_de_puntos.push_back(F);
    E.lista_de_puntos.push_back(G);

    // F -> no tiene destinos
    // G -> no tiene destinos
    // H -> no tiene destinos

    // Guardamos todos los puntos en el grafo
    grafo.push_back(A);
    grafo.push_back(B);
    grafo.push_back(C);
    grafo.push_back(D);
    grafo.push_back(E);
    grafo.push_back(F);
    grafo.push_back(G);
    grafo.push_back(H);

    return grafo;
}

bool comparaciondezonas(puntos A, puntos B) {
    return A.precio > B.precio;
}

int buscarindice(vector<puntos>zonas,double RCL) {
    int cont = 0;
    for (int i = 0; i < zonas.size(); i++) {
        if (zonas[i].precio>=RCL) {
            cont++;
        }
    }
    return cont;
}

void metaeuristica(vector<puntos>grafos) {
    vector<puntos>mejor_respuesta;
    int mejorganancia=0;
    srand(time(NULL));
    for (int i=0;i<10000;i++) {
        vector<puntos>respuesta;
        bool haypuntomuerto=false;
        int ubiactual=0;
        int gananciaparcial=0;
        while (!haypuntomuerto) {
            puntos nodos= grafos[ubiactual];
            int cantidadevisitantes=nodos.lista_de_puntos.size();
            if (cantidadevisitantes==0) {
                haypuntomuerto=true;
                break;
            }
            vector<puntos>zonas=nodos.lista_de_puntos;
            sort(zonas.begin(),zonas.end(),comparaciondezonas);
            int beta=zonas[0].precio;
            int taut=zonas[zonas.size()-1].precio;
            double RCL=beta-alfa*(beta-taut);
            int indice=buscarindice(zonas,RCL);
            int indat=rand()%indice;

            int indicequesemovera=zonas[indat].punto;
            ubiactual=indicequesemovera;
            gananciaparcial+=zonas[indat].precio;
            respuesta.push_back(zonas[indat]);
        }
        if (gananciaparcial>=mejorganancia) {
            mejorganancia=gananciaparcial;
            mejor_respuesta=respuesta;

        }


    }
    cout<<endl;
    for (int i=0;i<mejor_respuesta.size();i++) {
        char info='A'+mejor_respuesta[i].punto;
        cout<<info<<" ";
    }
    cout<<"con la mejor ganancia de: "<<mejorganancia<<endl;

}

int main() {
    int data[8]={0,20,30,40,40,40,10,50};

    vector<puntos> grafo = generarDatos();
    metaeuristica(grafo);


    //cout<<alfa<<endl;
    return 0;
}