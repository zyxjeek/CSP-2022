#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    srand(time(0));
    return l + rand() % (r - l + 1);
}

void quicksort(int arr[], int l, int r) {
    if (l >= r) return;
    int pivot = arr[rand(l, r)];
    int i = l, j = r;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quicksort(arr, l, j);
    quicksort(arr, i, r);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}