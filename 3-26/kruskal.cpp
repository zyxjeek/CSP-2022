#include <bits/stdc++.h>
using namespace std;

int gragh[100][100];
int n;

struct edge {
    int u, v, w;
    bool operator<(const edge &a) const {
        return w < a.w;
    }
};

vector<int> parent, rk;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}
void make(int v) {
    parent[v] = v;
    rk[v] = 0;
}
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (rk[u] < rk[v]) {
        swap(u, v);
    }
    parent[v] = u;
    if (rk[u] == rk[v]) {
        rk[u]++;
    }
}

// 最小生成树 Kruskal算法
int kruskal() {
    vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, j, gragh[i][j]});
        }
    }
    parent.resize(n);
    rk.resize(n);
    for (int i = 0; i < n; i++) {   
        make(i);
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    
    for (edge e : edges) {
        if (find(e.u) != find(e.v)) {
            edges.push_back(e);
            join(e.u, e.v);
            ans += e.w;
        }
    }
    return ans;
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gragh[i][j];
        }
    }
    cout << kruskal() << endl;
    return 0;
}