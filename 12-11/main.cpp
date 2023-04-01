//#include <bits/stdc++.h>
//using namespace std;
//
//const int SIZE = 10086;
//char s1[SIZE], s2[SIZE];
//int a[SIZE], b[SIZE], c[SIZE];
//
//int main() {
//    cin >> s1 >> s2;
//    int len1 = strlen(s1), len2 = strlen(s2);
//    if (strcmp(s1, s2) == 0) {
//        cout << 0;
//        return 0;
//    }
//    if ((strcmp(s1, s2) < 0 && len1 == len2) || len1 < len2) {
//        cout << '-';
//        swap(s1, s2);
//        swap(len1, len2);
//    }
//    memset(a, 0, sizeof(a));
//    memset(b, 0, sizeof(b));
//    memset(c, 0, sizeof(c));
//    for (int i = 0; i < len1; i++)
//        a[i] = s1[len1 - i - 1] - '0';
//    for (int i = 0; i < len2; i++)
//        b[i] = s2[len2 - i - 1] - '0';
//    for (int i = 0; i < SIZE; i++) {
//        if (a[i] < b[i]) {
//            a[i] += 10;
//            a[i+1] -= 1;
//        }
//        c[i] = a[i] - b[i];
//    }
//    for (int i = SIZE; i >= 0; i--) {
//        if (c[i] != 0) {
//            for (int j = i; j >= 0; j--)
//                cout << c[j];
//            break;
//        }
//    }
//    return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int SIZE = 2000;
//char s1[SIZE], s2[SIZE];
//int a[SIZE], b[SIZE], c[SIZE*2];
//
//int main() {
//    cin >> s1 >> s2;
//    int len1 = strlen(s1), len2 = strlen(s2);
//    if (!strcmp(s1, "0") || !strcmp(s2, "0")) {
//        cout << 0;
//        return 0;
//    }
//    memset(a, 0, sizeof(a));
//    memset(b, 0, sizeof(b));
//    memset(c, 0, sizeof(c));
//    for (int i = 0; i < len1; i++)
//        a[i] = s1[len1 - i - 1] - '0';
//    for (int i = 0; i < len2; i++)
//        b[i] = s2[len2 - i - 1] - '0';
//    for (int i = 0; i < len2; i++) {
//        int k = b[i];
//        for (int j = i; j < len1 + i; j++)
//            c[j] += a[j-i] * k;
//    }
//    for (int i = 0; i < len1 + len2; i++) {
//        if (c[i] >= 10) {
//            c[i+1] += c[i] / 10;
//            c[i] %= 10;
//        }
//    }
//    int len = len1 + len2;
//    while (c[len] == 0 && len > 0) len--;
//    for (int i = len; i >= 0; i--) cout << c[i];
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, min = INT_MAX, h, now, i, j;
    cin >> n;
    for (i = 1; i <= n / 3; i++)
        for (j = i; j <= n / 3; j++)
            if (n % (i * j) == 0) {
                h = n / (i * j);
                now = i * j * 2 + i * h * 2 + j * h * 2;
                if (now < min)
                    min = now;
            }
    cout << min;
    return 0;
}