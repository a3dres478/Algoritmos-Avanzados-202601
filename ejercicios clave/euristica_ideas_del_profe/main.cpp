#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para guardar:
// - id del vértice
// - grado (cantidad de vecinos)
struct Vertice {
    int id;
    int grado;
};

// Ordenar de MAYOR grado a MENOR grado
bool compararPorGrado(Vertice a, Vertice b) {
    return a.grado > b.grado;
}

int main() {

    // =========================================
    // CANTIDAD DE VERTICES
    // =========================================
    int V = 6;

    // =========================================
    // MATRIZ DE ADYACENCIA
    //
    //      A B C D E F
    // =========================================
    int ady[6][6] = {

        //A B C D E F
        {0,1,1,1,0,0}, // A
        {1,0,1,0,1,0}, // B
        {1,1,0,1,0,1}, // C
        {1,0,1,0,0,1}, // D
        {0,1,0,0,0,1}, // E
        {0,0,1,1,1,0}  // F
    };

    // =========================================
    // color[i]
    // Guarda el color del vértice i
    //
    // -1 = sin color todavía
    // =========================================
    vector<int> color(V, -1);

    // =========================================
    // CALCULAR GRADO DE CADA VERTICE
    // =========================================
    vector<Vertice> vertices;

    for (int i = 0; i < V; i++) {

        int grado = 0;

        for (int j = 0; j < V; j++) {

            if (ady[i][j] == 1) {
                grado++;
            }
        }

        vertices.push_back({i, grado});
    }

    // =========================================
    // ORDENAR POR GRADO DESCENDENTE
    // =========================================
    sort(vertices.begin(), vertices.end(), compararPorGrado);

    cout << "Orden de vertices:\n";

    for (auto v : vertices) {

        char letra = 'A' + v.id;

        cout << letra
             << "("
             << v.grado
             << ") ";
    }

    cout << "\n\n";

    // =========================================
    // ALGORITMO VORAZ DE COLOREADO
    // =========================================
    for (int k = 0; k < V; k++) {

        // Vértice actual
        int v = vertices[k].id;

        // =====================================
        // Colores prohibidos
        //
        // Si un vecino ya tiene ese color,
        // entonces no podemos usarlo
        // =====================================
        vector<bool> coloresProhibidos(V, false);

        // Revisar vecinos
        for (int u = 0; u < V; u++) {

            // Si son vecinos
            // y el vecino ya tiene color
            if (ady[v][u] == 1 && color[u] != -1) {

                coloresProhibidos[color[u]] = true;
            }
        }

        // =====================================
        // Buscar el menor color disponible
        // =====================================
        int c = 0;

        while (coloresProhibidos[c] == true) {
            c++;
        }

        // Asignar color
        color[v] = c;
    }

    // =========================================
    // IMPRIMIR RESULTADOS
    // =========================================
    cout << "Colores asignados:\n\n";

    for (int i = 0; i < V; i++) {

        char letra = 'A' + i;

        cout << "Vertice "
             << letra
             << " -> Color "
             << color[i]
             << endl;
    }

    // =========================================
    // CALCULAR NUMERO TOTAL DE COLORES
    // =========================================
    int numColores = 0;

    for (int i = 0; i < V; i++) {

        numColores = max(numColores, color[i] + 1);
    }

    cout << "\nCantidad de colores utilizados: "
         << numColores
         << endl;

    return 0;
}