#include <bits/stdc++.h>
using namespace std;

char puzzle[1002][1002];
int n, m;
int ans[100001];
int fn[1002][1002];

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int sx, int sy, bool k, int q) {
    stack<pair<int, int>> st;
    st.emplace(sx, sy);

    while (!st.empty()) {
        int x = st.top().first;
        int y = st.top().second;
        st.pop();

        if (!check(x, y) || puzzle[x][y] - '0' != k || fn[x][y] != -1)
            continue;

        fn[x][y] = q;
        ans[q]++;

        st.emplace(x, y+1);
        st.emplace(x, y-1);
        st.emplace(x+1, y);
        st.emplace(x-1, y);

        k = !k;
    }
}


int main() {
    cin >> n >> m;
    memset(fn, -1, sizeof(fn));
    for (int i=0;i<n;i++)
        scanf("%s",puzzle[i]);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        if (fn[x][y] == -1) {
            dfs(x, y, puzzle[x][y] - '0', i);
        }
        else ans[i] = ans[fn[x][y]];
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
    return 0;
}