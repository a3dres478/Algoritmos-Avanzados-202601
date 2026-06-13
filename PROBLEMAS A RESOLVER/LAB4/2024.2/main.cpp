#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct cajas {
    int cantidad;
    int pesoactual;
    vector<int>lista;
};

bool comparar(int a,int b) {
    return a>b;
}

int buscarindice(vector<int>peso_vector,int rclt) {
    int cont=0;
    for(int i=0;i<peso_vector.size();i++) {
        if (peso_vector[i]>=rclt) {
            cont++;
        }
    }
    return cont;
}

vector<cajas> metaeuristica(int pesos[],int maximo) {
    vector<cajas> mejor_respuesta;
    srand(time(NULL));
    for (int i=0;i<10000;i++) {
        vector<int> pesos_vector;
        pesos_vector.insert(pesos_vector.begin(),pesos,pesos+6);
        sort(pesos_vector.begin(),pesos_vector.end(),comparar);
        vector<cajas> cajas_vector;
        while (!pesos_vector.empty()) {
            int beta=pesos_vector[0];
            int taut=pesos_vector[pesos_vector.size()-1];
            double rclt=beta-0.4 *(beta-taut);
            int indicet=buscarindice(pesos_vector,rclt);
            int indicerand= rand()% indicet;
            int numero=pesos_vector[indicerand];
            if (!cajas_vector.empty()) {
                bool bandeera=false;
                for (int j=0;j<cajas_vector.size();j++) {
                    if (bandeera==true) {
                        break;
                    }
                    cajas nodo=cajas_vector[j];
                    int pesocondata=nodo.pesoactual+numero;
                    if (pesocondata<=maximo) {
                        bandeera=true;
                        nodo.cantidad++;
                        nodo.pesoactual=pesocondata;
                        nodo.lista.push_back(numero);
                        cajas_vector[j]=nodo;
                    }
                }

                if (!bandeera) {
                    cajas nodo;
                    nodo.cantidad=1;
                    nodo.pesoactual=numero;
                    nodo.lista.push_back(numero);
                    cajas_vector.push_back(nodo);
                }
            }else {

                cajas nodo;
                nodo.cantidad=1;
                nodo.pesoactual=numero;
                nodo.lista.push_back(numero);
                cajas_vector.push_back(nodo);
            }
            pesos_vector.erase(pesos_vector.begin()+indicerand);


        }
        if (mejor_respuesta.empty() || cajas_vector.size() < mejor_respuesta.size()) {
            mejor_respuesta = cajas_vector;
        }


    }
    return mejor_respuesta;

}

int main() {
    int pesos[6]={4, 8, 1, 4, 2, 1};
    int maximo=10;

    vector<cajas> respuesta = metaeuristica(pesos, maximo);

    cout << "Cantidad de cajas utilizadas: " << respuesta.size() << endl;

    for (int i = 0; i < respuesta.size(); i++) {
        cout << "Caja " << i + 1 << ": ";

        for (int j = 0; j < respuesta[i].lista.size(); j++) {
            cout << respuesta[i].lista[j] << " ";
        }

        cout << "| Peso usado: " << respuesta[i].pesoactual << "/" << 6;
        cout << endl;
    }


    return 0;
}