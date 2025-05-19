#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[py] < rank[px]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main() {
    int V;
    cin >> V;
    vector<Edge> edges;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            int w; cin >> w;
            if(j > i && w != 0) {
                edges.push_back({i, j, w});
            }
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(V);
    int mst_weight = 0, edges_used = 0;

    for(auto &e : edges) {
        if(dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            edges_used++;
            if(edges_used == V - 1) break;
        }
    }

    cout << mst_weight << "\n";

    return 0;
}
