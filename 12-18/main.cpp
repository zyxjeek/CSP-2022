//#include <bits/stdc++.h>
//using namespace std;
//
//const int SIZE = 5000;
//char s[SIZE];
//int b;
//int a[SIZE], c[SIZE];
//
//int main() {
//    cin >> s >> b;
//    if (strcmp(s, "0") == 0) {
//        cout << 0;
//        return 0;
//    }
//    memset(a, 0, sizeof(a));
//    memset(c, 0, sizeof(c));
//    for (int i = 0; i < strlen(s); i++)
//        a[i] = s[i] - '0';
//    int d = 0;
//    for (int i = 0; i < strlen(s); i++) {
//        d = d * 10 + a[i];
//        c[i] = d / b;
//        d %= b;
//    }
//    int i = 0;
//    while (c[i] == 0)
//        i++;
//    for (; i < strlen(s); i++)
//        cout << c[i];
//    cout << " " << d;
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

struct hahaha {
    int price, number;
};
bool cmp(hahaha a, hahaha b) {
    if (a.price != b.price)
        return a.price < b.price;
    else
        return a.number > b.number;
}

int main() {
    int total, n;
    cin >> total >> n;
    hahaha a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].price >> a[i].number;
    sort(a, a + n, cmp);
    int sum = 0, i = 0;
    while (total > 0) {
        if (total >= a[i].number) {
            sum += a[i].price * a[i].number;
            total -= a[i].number;
        } else {
            sum += a[i].price * total;
            total = 0;
        }
        i++;
    }
    cout << sum;
    return 0;
}
// 400107342