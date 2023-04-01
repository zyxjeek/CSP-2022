#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100, maxm = 300100;

int n, m, head[maxn], len;
int times, dfn[maxn], low[maxn], scc_id[maxn], cnt;
int ind[maxn], outd[maxn];
vector<int> scc[maxn];
stack<int> st;
struct edge {
    int to, next;
} edges[maxm];

void add_edge(int u, int v) {
    edges[++len].to = v;
    edges[len].next = head[u];
    head[u] = len;
}

void dfs(int u) {
    dfn[u] = low[u] = ++times;
    st.push(u);
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc_id[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++cnt;
        while (true) {
            int x = st.top();
            st.pop();
            scc_id[x] = cnt;
            scc[cnt].push_back(x);
            if (x == u) {
                break;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        n = max(n, max(u, v));
        add_edge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            dfs(i);
        }
    }
    
    int ans1 = 0;
    for (int i = 1; i <= cnt; ++i) {
        ans1 = max(ans1, (int) scc[i].size());
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = head[u]; i; i = edges[i].next) {
            int v = edges[i].to;
            int x = scc_id[u], y = scc_id[v];
            if (x != y) {
                ++outd[x];
                ++ind[y];
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (!ind[i]) {
            ++cnt1;
        }
        if (!outd[i]) {
            ++cnt2;
        }
    }
    cout << ans1 << endl << max(cnt1, cnt2) << endl;
    return 0;
}