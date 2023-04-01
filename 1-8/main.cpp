#include <bits/stdc++.h>
using namespace std;

int result[9];
void print() {
    for (int row = 1; row <= 8; row++) {
        for (int col = 1; col <= 8; col++) {
            if (result[row] == col) {
                cout << "Q";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}
bool isOk(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (result[i] == col || abs(i - row) == abs(result[i] - col)) {
            return false;
        }
    }
    return true;
}
void dfs(int row) {
    if (row == 9) {
        print();
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (isOk(row, i)) {
            result[row] = i;
            dfs(row + 1);
            result[row] = 0;
        }
    }
}

int main() {
    dfs(1);
    return 0;
}