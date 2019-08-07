#include <iostream>
using namespace std;

bool isSafe(int *arr[], int n, int m, int r, int c) {
    if(r > 0 && c > 1 && arr[r][c] != -1)
        return false;
    if(r > 1 && c > 0 && arr[r][c] != -1)
        return false;
    if(r > 1 && c+1 < n && arr[r][c] != -1)
        return false;
    if(r > 0 && c+2 < n && arr[r][c] != -1)
        return false;
    return true;
}

long knights(int *arr[], int n, int m, int i, int j, int k) {
    if(j == n)
    	return knights(arr, n, m, i+1, 0, k);
    if(i == n)
    	return 0;
    if(k == 0)
    	return 0;
    bool safe = isSafe(arr, n, m, i, j);
    long c;
    if(safe){
    	arr[i][j] = k;
    	c = knights(arr, n, m, i, j+1, k-1);
    }
}

int main() {
	int t, n, m, i, j;
	cin >> t;
	while(t-- > 0) {
	    cin >> n >> m;
	    int arr[n][m];
	    for(i = 0; i < n; ++i)
	        for(j = 0; j < m; ++j)
	            arr[i][j] = -1;
	    cout << knights(n, m, 0, 0, 2);
	}
	return 0;
}