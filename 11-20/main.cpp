#include <iostream>
using namespace std;
const int n = 4;
int main() {
    double arr[n];
    for (double & i : arr)
    	cin >> i;
    /*
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    */
    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int l = 0, r = i-1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (key < arr[mid])
                r = mid - 1;
            else l = mid + 1;
        }
        for (int j = i - 1; j >= l; j--)
            arr[j+1] = arr[j];
        arr[l] = key;
    }
    for (double i : arr)
    	cout << i << ' ';
    return 0;
}
