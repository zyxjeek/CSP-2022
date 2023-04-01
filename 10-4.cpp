#include <iostream>
using namespace std;
int main() {
	char c;
	int cnt = 0;
	while ((c = cin.get()) != '.')
		if ((c >= 'a') && (c <= 'z')) cnt++;
	cout << cnt;
	return 0;
}
