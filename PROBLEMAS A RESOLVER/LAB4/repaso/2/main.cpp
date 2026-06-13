#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct tabla {
    int id;
    int capacidad;
    int velocidad;
};

struct disco {
    int id;
    int capacidad;
    int velocidad;
};

struct respuesta {
    int idtabla;
    int iddisco;
};

bool comparartabla(tabla a, tabla b) {
    if (a.velocidad == b.velocidad) {
        return a.capacidad > b.capacidad;
    } else {
        return a.velocidad > b.velocidad;
    }
}
bool comparardisco(disco a, disco b) {
    if (a.velocidad == b.velocidad) {
        return a.capacidad > b.capacidad;
    } else {
        return a.velocidad > b.velocidad;
    }
}
bool comparardisco1(disco a, disco b) {
    return a.velocidad < b.velocidad;
}


int buscarindice(vector<tabla>tabla,double RCL) {
    int cont=0;
    for (int i=0;i<tabla.size();i++) {
        if (tabla[i].velocidad>=RCL) {
            cont++;
        }
    }
    return cont;

}

int buscarindice1(vector<disco>tabla,double RCL) {
    int cont=0;
    for (int i=0;i<tabla.size();i++) {
        if (tabla[i].velocidad>=RCL) {
            cont++;
        }
    }
    return cont;

}


vector<disco> obtenerdiscofac(vector<disco>vdisco,int velo,int capa) {
    vector<disco> vdisco1;
    for (int i=0;i<vdisco.size();i++) {
        if (vdisco[i].capacidad>=capa && vdisco[i].velocidad>=velo) {
            vdisco1.push_back(vdisco[i]);
        }
    }
    return vdisco1;
}

void metaeuristica(tabla tab[],int totaltabla,disco dis[],int totaldisco) {
    vector<respuesta>mejor_respuesta;
    int velocidadminima=-1;
    srand(time(NULL));
    for (int i=0;i<10000;i++) {
        vector<respuesta>rptas;
        vector<tabla>vtablas;
        vector<disco>vdisco;
        for (int j=0;j<totaltabla;j++) {
            vtablas.push_back(tab[j]);
        }
        for (int j=0;j<totaldisco;j++) {
            vdisco.push_back(dis[j]);
        }

        sort(vtablas.begin(),vtablas.end(),comparartabla);
        bool sepuedecumplir=true;
        while (!vtablas.empty()) {
            int betatab=vtablas[0].velocidad;
            int tauttabla=vtablas[vtablas.size()-1].velocidad;
            double RCLTabla=betatab-0.3*(betatab-tauttabla);
            int indicetab1=buscarindice(vtablas,RCLTabla);
            int indice=rand()%indicetab1;
            tabla nodo1=vtablas[indice];


            int velo=nodo1.velocidad;
            int capa=nodo1.capacidad;
            int indicetabla=nodo1.id;

            vector<disco>vdiscofati=obtenerdiscofac(vdisco,velo,capa);
            if (vdiscofati.size()==0) {
                sepuedecumplir=false;
                break;
            }
            sort(vdiscofati.begin(),vdiscofati.end(),comparardisco);

            int betadis=vdiscofati[0].velocidad;
            int tautdis=vdiscofati[vdiscofati.size()-1].velocidad;
            double RCLDisco=betadis-0.3*(betadis-tautdis);
            int indicedisc=buscarindice1(vdiscofati,RCLDisco);
            int indice1=rand()%indicedisc;


            int idborrador=vdiscofati[indice1].id;
            int indicexd=idborrador-1;

            vdisco[indicexd].velocidad-=velo;
            vdisco[indicexd].capacidad-=capa;


            respuesta nodo_respuesta;
            nodo_respuesta.iddisco=idborrador;
            nodo_respuesta.idtabla=indicetabla;
            rptas.push_back(nodo_respuesta);

            vtablas.erase(vtablas.begin()+indice);



        }

        if (sepuedecumplir) {
            sort(vdisco.begin(),vdisco.end(),comparardisco1);
            int velocidaddelmenor=vdisco[0].velocidad;
            if (velocidaddelmenor>velocidadminima) {
                velocidadminima=velocidaddelmenor;
                mejor_respuesta=rptas;
            }


        }


    }

    cout<<"con el mejor makespan: "<<velocidadminima<<endl;
    for (int i=1;i<=3;i++) {
        cout<<"Para el disco "<<i<<"  ";
        for (int j=0;j<mejor_respuesta.size();j++) {
            if (mejor_respuesta[j].iddisco==i) {
                cout<<mejor_respuesta[j].idtabla<<"  ";
            }
        }
        cout<<endl;
    }



}


int main() {

    tabla tabs[6]={
        {1,20,150},
        {2,10,100},
        {3,15,80},
        {4,100,50},
        {5,50,120},
        {6,100,10}
    };

    disco disc[3]={
        {1,800,250},
        {2,750,200},
        {3,850,200}
    };
    int totaltablas=6;
    int totaldisco=3;

    metaeuristica(tabs,totaltablas,disc,totaldisco);
    return 0;
}