#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int src, int dest, const vector<vector<pii>>& graph) {
    int n = graph.size();
    vector<int> dist(n, 1e9);
    vector<int> parent(n, -1);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curDist > dist[u]) continue;
        if (u == dest) break;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == 1e9) {
        cout << "No path from " << src << " to " << dest << endl;
        return;
    }

    cout << "Shortest distance from " << src << " to " << dest << " is: " << dist[dest] << "\n";
    cout << "Path: ";

    stack<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.push(v);
    }
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // Assuming undirected graph; remove this if directed
    }

    int akshayHouse;
    cin >> akshayHouse;

    int t; // number of friends
    cin >> t;
    vector<int> friends(t);
    for (int i = 0; i < t; i++) {
        cin >> friends[i];
    }

    for (int f : friends) {
        dijkstra(f, akshayHouse, graph);
    }

    return 0;
}
