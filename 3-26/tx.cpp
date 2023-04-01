#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int n;
int W[MAXN];
int P[MAXN][MAXN];

int prim() {
    vector<bool> visited(n, false);
    vector<int> min_cost(n, INF);

    min_cost[0] = 0;
    int res = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < n; u++) {
            if (!visited[u] && (v == -1 || min_cost[u] < min_cost[v])) {
                v = u;
            }
        }

        if (v == -1) {
            break;
        }

        visited[v] = true;
        res += min_cost[v];

        for (int u = 0; u < n; u++) {
            min_cost[u] = min(min_cost[u], min(P[v][u], W[u]));
        }
    }

    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> P[i][j];
        }
    }

    cout << prim() << endl;
    return 0;
}
