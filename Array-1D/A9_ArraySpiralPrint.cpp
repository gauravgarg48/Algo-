#include<bits/stdc++.h>
using namespace std;
#define N 1000
void spiralC(int arr[][N], int n, int m){
    // Clockwise
    int i, j, si = 0, sj = 0, ni = n-1, nj = m-1;
    while(si <= ni && sj <= nj) {
        for(i = sj; i <= nj; ++i)
            cout << arr[si][i] << ", ";
        si++;
        for(i = si; i <= ni; ++i)
            cout << arr[i][nj] << ", ";
        nj--;
        for(i = nj; i >= sj; --i)
            cout << arr[ni][i] << ", ";
        ni--;
        for(i = ni; i >= si; --i)
            cout << arr[i][sj] << ", ";
        sj++;
    }
    cout << "END";
    return;
}

void spiralA(int arr[][N], int n, int m){
    // Anti-Clockwise
    int i, j, si = 0, sj = 0, ni = n-1, nj = m-1;
    while(si <= ni && sj <= nj) {
        for(i = si; i <= ni; ++i)
            cout << arr[i][sj] << ", ";
        sj++;
        for(i = sj; i <= nj; ++i)
            cout << arr[ni][i] << ", ";
        ni--;
        for(i = ni; i >= si; --i)
            cout << arr[i][nj] << ", ";
        nj--;
        for(i = nj; i >= sj; --i)
            cout << arr[si][i] << ", ";
        si++;
    }
    cout << "END";
    return;
}

int main() {
    int n, m, i, j;
    cin >> n >> m;
    int arr[N][N];
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            cin >> arr[i][j];
    spiralA(arr, n, m);
    return 0;
}