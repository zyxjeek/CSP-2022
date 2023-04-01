#include <bits/stdc++.h>

inline int read() {
    int x = 0, fh = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') fh = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * fh;
}

typedef double db;
const db eps = 1e-8;
const int maxn = 1e6 + 5;
const int maxk = 105;
const int maxm = 1e4 + 5;
int head[maxn], tot = 1;
struct asd {
    int to, next;
} b[maxn], b2[maxn];

void ad(int aa, int bb) {
    b[tot].to = bb;
    b[tot].next = head[aa];
    head[aa] = tot++;
}

int h2[maxn], t2 = 1;

void ad2(int aa, int bb) {
    b2[t2].to = bb;
    b2[t2].next = h2[aa];
    h2[aa] = t2++;
}

int rd[maxn];
db mp[maxk][maxk];
int jl[maxk][maxk];
int low[maxn], dfn[maxn], dfnc, js, shuyu[maxn], sta[maxn], top, siz[maxn];

void tar(int now) {
    dfn[now] = low[now] = ++dfnc;
    sta[++top] = now;
    for (int i = head[now]; i != -1; i = b[i].next) {
        int u = b[i].to;
        if (!dfn[u]) {
            tar(u);
            low[now] = std::min(low[now], low[u]);
        } else if (!shuyu[u]) {
            low[now] = std::min(low[now], dfn[u]);
        }
    }
    if (dfn[now] == low[now]) {
        js++;
        while (true) {
            int y = sta[top--];
            shuyu[y] = js;
            siz[js]++;
            if (y == now) break;
        }
    }
}

int n, m, s, t, rk[maxm], du[maxm], xh[maxm];
std::vector<int> g[maxn];
db dp[maxn];
bool jud;

void gsxy(int id) {
    memset(rk, 0, sizeof(rk));
    memset(xh, 0, sizeof(xh));
    int ncnt = 0;
    for (int i = 1; i <= n; i++) {
        if (shuyu[i] == id) {
            rk[i] = ++ncnt;
            xh[ncnt] = i;
            g[id].push_back(i);
            if (i == t) jud = true;
        }
    }
    if (jud == 0) {
        return;
    } else {
        memset(mp, 0, sizeof(mp));
        memset(jl, 0, sizeof(jl));
        for (int i = 1; i <= ncnt; i++) {
            mp[i][ncnt + 1] = 1;
        }
        for (int now : g[id]) {
            for (int i = head[now]; i != -1; i = b[i].next) {
                int u = b[i].to;
                if (shuyu[u] == shuyu[now]) {
                    jl[rk[now]][rk[u]]++;
                } else {
                    mp[rk[now]][ncnt + 1] += (double) dp[u] / du[now];
                }
            }
        }
        for (int i = 0; i < g[id].size(); i++) {
            for (int j = 0; j < g[id].size(); j++) {
                int aa = g[id][i], bb = g[id][j];
                if (i == j) {
                    mp[rk[aa]][rk[aa]] = (db) (du[aa] - jl[rk[aa]][rk[aa]]) / du[aa];
                } else {
                    mp[rk[aa]][rk[bb]] = (db) (-1.0) * jl[rk[aa]][rk[bb]] / du[aa];
                }
            }
        }
        for (int i : g[id]) {
            if (i == t) {
                int now = rk[i];
                for (int j = 1; j <= ncnt + 1; j++) {
                    mp[now][j] = 0;
                }
                mp[now][now] = 1;
            }
        }
        int now = 1;
        for (int i = 1; i <= ncnt; i++) {
            double mmax = 0;
            int jl = 0;
            for (int j = now; j <= ncnt; j++) {
                if (std::fabs(mp[j][i]) > std::fabs(mmax)) {
                    mmax = mp[j][i];
                    jl = j;
                }
            }
            if (std::fabs(mmax) < eps) continue;
            if (jl != now) std::swap(mp[jl], mp[now]);
            for (int j = i + 1; j <= ncnt + 1; j++) {
                mp[now][j] /= mp[now][i];
            }
            mp[now][i] = 1.0;
            for (int j = now + 1; j <= ncnt; j++) {
                db cs = mp[j][i];
                for (int k = i; k <= ncnt + 1; k++) {
                    mp[j][k] -= cs * mp[now][k];
                }
            }
            now++;
        }
        dp[xh[ncnt]] = mp[ncnt][ncnt + 1];
        for (int i = ncnt - 1; i >= 1; i--) {
            dp[xh[i]] = mp[i][ncnt + 1];
            for (int j = i + 1; j <= n; j++) {
                dp[xh[i]] -= mp[i][j] * dp[xh[j]];
            }
        }
    }
}

std::queue<int> q;
int huan[maxn];

void tp() {
    for (int i = 1; i <= js; i++) {
        if (rd[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        gsxy(now);
        q.pop();
        for (int i = h2[now]; i != -1; i = b2[i].next) {
            int u = b2[i].to;
            rd[u]--;
            if (rd[u] == 0) q.push(u);
        }
    }
}

bool vis[maxn];

void dfs(int now) {
    vis[now] = true;
    for (int i = head[now]; i != -1; i = b[i].next) {
        int u = b[i].to;
        if (!vis[u]) dfs(u);
    }
}

int main() {
    memset(h2, -1, sizeof(h2));
    memset(head, -1, sizeof(head));
    n = read(), m = read(), s = read(), t = read();
    for (int i = 1; i <= m; i++) {
        int aa, bb;
        aa = read(), bb = read();
        ad(aa, bb);
        du[aa]++;
        if (aa == bb) huan[aa]++;
    }
    dfs(s);
    if (vis[t] == 0) {
        printf("INF\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (i == t) continue;
        if (vis[i] && du[i] - huan[i] == 0) {
            printf("INF\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tar(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j != -1; j = b[j].next) {
            int u = b[j].to;
            if (shuyu[i] != shuyu[u]) {
                ad2(shuyu[u], shuyu[i]);
                rd[shuyu[i]]++;
            }
        }
    }
    tp();
    printf("%.3f\n", dp[s]);
    return 0;
}
