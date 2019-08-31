#include<bits/stdc++.h>
#define N 1000
using namespace std;
bool ratInMaze(char arr[][N], int sol[][N],
				int r, int c, int n, int m) {
	if(r == n-1 && c == m-1) {
		sol[r][c] = 1;
		for(r = 0; r < n; ++r) {
			for(c = 0; c < m; ++c)
				cout << sol[r][c] << " ";
			cout << endl;
		}
		return true;
	}
	sol[r][c] = 1;
	if(c+1 < m && arr[r][c+1] == 'O' && 
		ratInMaze(arr, sol, r, c+1, n, m))
		return true;
	else if(r+1 < n && arr[r+1][c] == 'O' && 
		ratInMaze(arr, sol, r+1, c, n, m))
		return true;
	sol[r][c] = 0;
	return false;
}

int main() {
	int n, m, i, j;
	cin >> n >> m;
	char arr[N][N];
	int sol[N][N];
	memset(sol, 0, n*m*sizeof(int));
	for(i = 0; i < n; ++i)
		cin >> arr[i];
	ratInMaze(arr, sol, 0, 0, n, m);
	return 0;
}