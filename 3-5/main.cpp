#include <bits/stdc++.h>
using namespace std;

int a[35][35], b[35][35], n;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] != 0) return;
    a[x][y] = 1;
    dfs(x, y+1);
    dfs(x, y-1);
    dfs(x+1, y);
    dfs(x-1, y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
            a[i][j] = (b[i][j] == 0 ? 0 : 2);
        }
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) cout << 2 << " ";
            else cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}