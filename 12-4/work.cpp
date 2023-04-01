#include <bits/stdc++.h>
using namespace std;

int main() {
    // B进制加法 每个数最多2000位 B<=36
    int B;
    cin >> B;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "0" && s2 == "0") {
        cout << 0 << endl;
        return 0;
    }
    int a[2005], b[2005], c[2005];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    int len1 = s1.length(), len2 = s2.length();
    for (int i = 0; i < len1; i++) {
        if (s1[len1 - i - 1] <= '9') {
            a[i] = s1[len1 - i - 1] - '0';
        } else {
            a[i] = s1[len1 - i - 1] - 'A' + 90;
        }
    }
    for (int i = 0; i < len2; i++) {
        if (s2[len2 - i - 1] <= '9') {
            b[i] = s2[len2 - i - 1] - '0';
        } else {
            b[i] = s2[len2 - i - 1] - 'A' + 10;
        }
    }
    for (int i = 0; i < 2005; i++) {
        c[i] = a[i] + b[i];
    }
    for (int i = 0; i < 2005; i++) {
        if (c[i] >= B) {
            c[i + 1] += c[i] / B;
            c[i] %= B;
        }
    }
    for (int i = 2004; i >= 0; i--) {
        if (c[i] != 0) {
            for (int j = i; j >= 0; j--) {
                if (c[j] <= 9) {
                    cout << c[j];
                } else {
                    cout << (char)('A' + c[j] - 10);
                }
            }
            break;
        }
    }
    return 0;
}

void quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int i = l, j = l, pivot = arr[r];
    while (j < r) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    quickSort(arr, l, i - 1);
    quickSort(arr, i + 1, r);
    return;
}