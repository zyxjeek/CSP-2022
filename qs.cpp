#include <bits/stdc++.h>
using namespace std;

void quick_sort(int nums[], int q, int r) {
    if (q >= r) return;
    int i = q, j = q, pivot = nums[r];
    while (j < r) {
        if (nums[j] < pivot) {
            swap(nums[i++], nums[j]);
        }
        j++;
    }
    swap(nums[i], nums[r]);
    quick_sort(nums, q, i-1);
    quick_sort(nums, i+1, r);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int& i : arr) cin >> i;
    quick_sort(arr, 0, n-1);
    for (int i : arr) cout << i << ' ';
    return 0;
}