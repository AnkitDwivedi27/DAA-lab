#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (int v : graph[u]) {
        if (!visited[v] && dfs(v, graph, visited, recStack))
            return true;
        else if (recStack[v])
            return true;
    }

    recStack[u] = false;
    return false;
}

bool isCyclic(const vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack))
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

    if (isCyclic(graph, n))
        cout << "Yes Cycle Exists" << endl;
    else
        cout << "No Cycle Exists" << endl;

    return 0;
}
