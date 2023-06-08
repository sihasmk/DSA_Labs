#include <bits/stdc++.h>

using namespace std;

#define V 6

int minKey(int key[], bool MST[]) {
    int min_index;
    int min = INT_MAX;

    for (int v=0; v<V; v++) {
        if (!MST[v] && key[v]<min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V], int start) {
    cout << "Edge\tWeight\n";

    for (int i=0; i<V; i++) {
        if (i!=start) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        }
    }
}

void Prims(int graph[V][V], int start) {
    int parent[V];

    int key[V];

    bool MST[V];

    for (int j=0; j<V; j++) {
        key[j] = INT_MAX;
        MST[j] = false;
    }

    key[start] = 0; 

    parent[start] = -1;

    for (int k=0; k<V-1; k++) {
        int u = minKey(key, MST);

        MST[u] = true;

        for (int v=0; v<V; v++) {
            if (graph[u][v] && !MST[v] && graph[u][v]<key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, start);
}

int main() {
    int graph[V][V] = {
                        {0, 3, 0, 0, 0, 1},
                        {3, 0, 2, 1, 10, 0},
                        {0, 2, 0, 3, 0, 5},
                        {0, 1, 3, 0, 5, 0},
                        {0, 10, 0, 5, 0, 4},
                        {1, 0, 5, 0, 4, 0}
    };

    Prims(graph, 0);

    return 0;
}
