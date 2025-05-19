#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int primMST(const vector<vector<int>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, minKey = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        totalCost += key[i];
    }

    return totalCost;
}

int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int cost = primMST(graph, V);
    cout << cost << "\n";

    return 0;
}
