#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct ciudad {
    int id;
    int costobase;
};

struct motorizado {
    int id;
    vector<int> costosindi;
    int costofinal;
};

struct respuesta {
    int idciudad;
    int idmoto;
};

bool compararmoto(motorizado m1, motorizado m2) {
    return m1.costofinal<m2.costofinal;
}

vector<motorizado> filtrarmotorizados(vector<motorizado>vmotos,int costomax,ciudad nodo) {
    vector<motorizado>posibles;
    int iddeciudad=nodo.id;
    int costobase=nodo.costobase;
    for(int i=0;i<vmotos.size();i++) {
        motorizado nodo1=vmotos[i];
        for (int j=0;j<nodo1.costosindi.size();j++) {
            int precio=nodo1.costosindi[j];
            if (j==iddeciudad-1) {
                if (costobase+precio<=costomax) {
                    nodo1.costofinal=costobase+precio;
                    posibles.push_back(nodo1);
                }
            }
        }
    }

    return posibles;


}


int buscarindice(double RCL,vector<motorizado>vmotorizadosposibles) {
    int cont=0;
    for (int i=0;i<vmotorizadosposibles.size();i++) {
        if (vmotorizadosposibles[i].costofinal<=RCL) {
            cont++;
        }
    }
    return cont;

}

void metaeurisica(ciudad ciu[4],int canticiu,motorizado moto[],int cantimoto,int costomax) {
    vector<respuesta>mejor_respueta;
    srand(time(NULL));
    int mejorcosto=9999;
    for (int i=0;i<10000;i++) {
        vector<ciudad>vciudad;
        vector<motorizado>vmotor;
        for (int j=0;j<cantimoto;j++) {
            vmotor.push_back(moto[j]);
        }
        for (int j=0;j<canticiu;j++) {
            vciudad.push_back(ciu[j]);
        }
        bool bandera=true;
        int sumamenor=00;
        vector<respuesta>respuestas;;
        while (!vciudad.empty()) {
            ciudad nodo =vciudad[0];
            vector<motorizado>vmotorizadosposibles=filtrarmotorizados(vmotor,costomax,nodo);
            if (vmotorizadosposibles.empty()) {
                bandera=false;
                break;
            }
            sort(vmotorizadosposibles.begin(),vmotorizadosposibles.end(),compararmoto);
            int beta=vmotorizadosposibles[0].costofinal;
            int tau=vmotorizadosposibles[vmotorizadosposibles.size()-1].costofinal;
            int RCL=beta+0.3*(tau-beta);
            int indic=buscarindice(RCL,vmotorizadosposibles);
            int indac=rand()%indic;

            motorizado nodo1=vmotorizadosposibles[indac];
            int idfinal=nodo1.id;
            sumamenor+=nodo1.costofinal;
            int idciudad=nodo.id;
            respuesta nodorpta;
            nodorpta.idciudad=idciudad;
            nodorpta.idmoto=idfinal;
            respuestas.push_back(nodorpta);
            vciudad.erase(vciudad.begin(),vciudad.begin()+1);
        }
        if (bandera) {
            if (sumamenor<mejorcosto) {
                mejor_respueta=respuestas;
                mejorcosto=sumamenor;

            }


        }



    }
    cout<<"el mejor costo es de: "<<mejorcosto<<endl;
    for (int k=0;k<mejor_respueta.size();k++) {
        cout<<"Para la ciudad: "<<mejor_respueta[k].idciudad<<"se tiene al motorizado: "<<mejor_respueta[k].idmoto<<endl;
    }



}

int main() {
    ciudad ciu[4]={
        {1,16},
        {2,15},
        {3,12},
        {4,18}
    };

    motorizado moto[5]={
        {1, {3, 4, 5, 6},0}, // Motorizado 1: A=3, B=4, C=5, D=6
        {2, {5, 2, 3, 4},0}, // Motorizado 2: A=5, B=2, C=3, D=4
        {3, {7, 5, 4, 2},0}, // Motorizado 3: A=7, B=5, C=4, D=2
        {4, {8, 7, 5, 1},0}, // Motorizado 4: A=8, B=7, C=5, D=1
        {5, {4, 3, 7, 5},0}
    };
    int costomaximo=20;

    metaeurisica(ciu,4,moto,5,costomaximo);


    return 0;
}