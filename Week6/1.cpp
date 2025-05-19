#include <iostream>
#include <vector>
using namespace std;

bool dfs(int current, int dest, const vector<vector<int>>& graph, vector<bool>& visited) {
    if (current == dest) return true;
    visited[current] = true;
    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, dest, graph, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int source, destination;
    cin >> source >> destination;
    vector<bool> visited(n, false);
    if (dfs(source, destination, graph, visited))
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Such Path Exists" << endl;
    return 0;
}
