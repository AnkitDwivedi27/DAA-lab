#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source, destination, k;
    cin >> source >> destination >> k;

    const int INF = INT_MAX / 2;
    vector<vector<int>> dp(V, vector<int>(k + 1, INF));
    dp[source][0] = 0;

    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < V; u++) {
            if (dp[u][e - 1] != INF) {
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] != 0) { // edge exists
                        dp[v][e] = min(dp[v][e], dp[u][e - 1] + graph[u][v]);
                    }
                }
            }
        }
    }

    if (dp[destination][k] == INF) {
        cout << "no path of length k is available\n";
    } else {
        cout << dp[destination][k] << "\n";
    }

    return 0;
}
