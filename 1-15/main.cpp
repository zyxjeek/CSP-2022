#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int get_index(int x) {
    return a * x * x + b * x + c;
}

int main() {
    cin >> a >> b >> c;
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << s[get_index(i) - 1];
    }
    return 0;
}