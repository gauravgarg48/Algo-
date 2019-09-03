#include<bits/stdc++.h>
using namespace std;
#define N 1000

void print90A(int arr[][N], int n) {
    // 90 deg Anti-Clockwise
    // Take transpose and then inverse columns
    int i, j, k;
    for(i = 0; i < n; ++i)
        for(j = i+1; j < n; ++j)
            swap(arr[i][j], arr[j][i]);
    for(j = 0; j < n; ++j)
        for(i = 0, k = n-1; i < k; ++i, --k)
            swap(arr[i][j], arr[k][j]);
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return;
}

int main() {
    int n, i, j;
    cin >> n;
    int arr[N][N];
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            cin >> arr[i][j];
    print90A(arr, n);
    return 0;
}