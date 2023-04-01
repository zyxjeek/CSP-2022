#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5];
    for (int& i : arr) cin >> i;
    bool found;
    for (int i = 0; i < 5; i++) {
        found = false;
        for (int j = 0; j < 4; j++) {
            if (arr[j] > arr[j+1]) {
                found = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if (!found) break;
    }
    for (int i : arr) cout << i << " ";
    return 0;
}