#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(const vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipartite(graph, n))
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;

    return 0;
}
