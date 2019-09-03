#include<iostream>
using namespace std;

int main() {
    int i, j, n, m, x;
    cin >> n >> m;
    int arr[n][m];
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            cin >> arr[i][j];
    cin >> x;
    i = n-1;
    j = 0;
    while(i >= 0 && j < m) {
        if(arr[i][j] == x)
            break;
        else if(arr[i][j] > x)
            i--;
        else
            j++;
    }
    if(i >= 0 && j < m)
        cout << 1;
    else
        cout << 0;
    return 0;
}