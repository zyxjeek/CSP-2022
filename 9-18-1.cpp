#include <bits/stdc++.h>
using namespace std;

int main() {
    double p, a, b, c, rs;
    cin >> a >> b >> c;
    p = (a+b+c)/2;
    rs = p * (p-a) * (p-b) * (p-c);
	cout << sqrt(rs); 
    return 0;
}
