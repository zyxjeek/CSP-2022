#include <bits/stdc++.h>
using namespace std;

int main() {
    char s1[505], s2[505];
    cin >> s1 >> s2;
    if (strcmp(s1, "0") == 0 && strcmp(s2, "0") == 0) {
        cout << 0 << endl;
        return 0;
    }
    int a[505], b[505], c[505];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - i - 1] - '0';
    }
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - i - 1] - '0';
    }
    for (int i = 0; i < 505; i++) {
        c[i] = a[i] + b[i];
    }
    for (int i = 0; i < 505; i++) {
        if (c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    for (int i = 504; i >= 0; i--) {
        if (c[i] != 0) {
            for (int j = i; j >= 0; j--) {
                cout << c[j];
            }
            break;
        }
    }
    return 0;
}
