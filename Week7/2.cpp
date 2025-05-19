#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

struct Edge {
    int u, v, w;
};

bool bellmanFord(int src, int dest, int n, const vector<Edge>& edges, vector<int>& dist, vector<int>& parent) {
    dist.assign(n, INT_MAX);
    parent.assign(n, -1);
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;
        for (const Edge& e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                updated = true;
            }
        }
        if (!updated) break;
    }

    // Check for negative weight cycles (optional)
    for (const Edge& e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            return false; // Negative cycle detected
        }
    }

    return true;
}

void printPath(int dest, const vector<int>& parent) {
    if (parent[dest] == -1) {
        cout << dest;
        return;
    }
    printPath(parent[dest], parent);
    cout << " -> " << dest;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src, dest;
    cin >> src >> dest;

    vector<int> dist, parent;

    bool noNegativeCycle = bellmanFord(src, dest, n, edges, dist, parent);

    if (!noNegativeCycle) {
        cout << "Graph contains a negative weight cycle\n";
        return 0;
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path from " << src << " to " << dest << endl;
    } else {
        cout << "Shortest distance from " << src << " to " << dest << " is: " << dist[dest] << "\n";
        cout << "Path: ";
        printPath(dest, parent);
        cout << "\n";
    }

    return 0;
}
