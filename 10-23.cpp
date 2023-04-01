#include <bits/stdc++.h>
using namespace std;

int main()
{
    int apples[10];
    int height;
    cin >> height;
    for (int & apple : apples)
        cin >> apple;
    height += 30;
    int c = 0;
    for (int apple : apples)
        if (height >= apple)
            c++;
    cout << c;
    return 0;
}