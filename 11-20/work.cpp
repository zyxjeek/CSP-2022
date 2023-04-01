#include <bits/stdc++.h>
using namespace std;

int main() {
    double arr[4];
    for (double & i : arr) {
        cin >> i;
    }
    for (int i = 1; i < 4; i++) {
        double num = arr[i];
        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] > num) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        for (int j = i - 1; j >= l; j--) {
            arr[j + 1] = arr[j];
        }
        arr[l] = num;
    }
    for (double i : arr) {
        cout << i << " ";
    }
    return 0;
}