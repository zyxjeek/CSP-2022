#include <bits/stdc++.h>
using namespace std;

const int primes[7] = {0, 2, 3, 5, 7, 11, 13};
vector<int> a, b, c;

int main() {
    string s;
    cin >> s;
    int pos = s.find('+');
    string s1 = s.substr(0, pos);
    string s2 = s.substr(pos + 1);
    int i = 0, count = 0;
    while (i < s1.size()) {
        string str;
        while (i < s1.size() && s1[i] != ',') {
            str += s1[i];
            i++;
        }
        i++;
        int num = stoi(str);
        a.push_back(num);
        count++;
    }
    i = 0, count = 0;
    while (i < s2.size()) {
        string str;
        while (i < s2.size() && s2[i] != ',') {
            str += s2[i];
            i++;
        }
        i++;
        int num = stoi(str);
        b.push_back(num);
        count++;
    }
    std::reverse(a.begin(), a.end());
    if (a.size() < 5) {
        for (int k = a.size(); k < 5; k++) {
            a.push_back(0);
        }
    }
    std::reverse(b.begin(), b.end());
    if (b.size() < 5) {
        for (int k = b.size(); k < 5; k++) {
            b.push_back(0);
        }
    }
    c = vector<int>(6, 0);
    for (int j = 0; j < 5; j++) {
        int jinzhi = primes[j+1];
        c[j] += a[j] + b[j];
        if (c[j] >= jinzhi) {
            int n = c[j];
            c[j] %= jinzhi;
            c[j+1] += n / jinzhi;
        }
    }
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    std::reverse(c.begin(), c.end());
    for (int j = 0; j < c.size(); j++) {
        if (j != 0) {
            cout << ",";
        }
        cout << c[j];
    }
    return 0;
}
