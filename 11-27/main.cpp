#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (arr[mid] >= arr[right])
                right = mid;
            else if (arr[left] <= arr[mid])
                left = mid;
        }
        return left;
    }
};

int main() {
    vector<int> arr = {18,29,38,59,98,100,99,98,90};
    cout << Solution::peakIndexInMountainArray(arr) << endl;
    return 0;
}
