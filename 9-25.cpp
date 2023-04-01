#include <bits/stdc++.h>
using namespace std;

int main() {
	int i = 0, a, m;
	m = 0;
	while (i < 4) {
		cin >> a;
		if (m < a)
			m = a;
		i++;
	}
	cout << m;
	return 0;
}

