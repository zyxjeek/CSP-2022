#include <bits/stdc++.h>
using namespace std;

int gragh[100][100];
int n;

// 最小生成树 Prim算法
int prim() {
    bool vis[n];
    memset(vis, false, sizeof(vis));
    vector<pair<int, int>> tree;
    int ans = 0;
    vis[0] = true;
    for (int i = 1; i < n; i++) {
        int minn = INT_MAX;
        int minn_index = 0;
        for (int j = 0; j < n; j++) {
            if (vis[j]) {
                for (int k = 0; k < n; k++) {
                    if (!vis[k] && gragh[j][k] < minn) {
                        minn = gragh[j][k];
                        minn_index = k;
                    }
                }
            }
            cout << minn << " " << minn_index << endl;
        }
        vis[minn_index] = true;
        ans += minn;
        tree.push_back(make_pair(minn_index, minn));
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
    cout << prim() << endl;
    return 0;
}