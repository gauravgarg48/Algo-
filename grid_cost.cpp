#include<bits/stdc++.h>
using namespace std;
#define N 1000
int grid_cost(vector<vector<int>> arr, int r, int c) {
	int i, j;
	for(i = 1; i < r; ++i)
		arr[i][0] += arr[i-1][0];
	for(i = 1; i < c; ++i)
		arr[0][i] += arr[0][i-1];
	for(i = 1; i < r; ++i) {
		for(j = 1; j < c; ++j) {
			arr[i][j] += min(arr[i][j-1], arr[i-1][j]);
		}
	}
	return arr[i-1][j-1];
}

int main() {
	int i, j, n, m, x;
	cin >> n >> m;
	vector<vector<int>> grid;
	for(i = 0; i < n; ++i) {
		vector<int> v;
		for(j = 0; j < m; ++j) {
			cin >> x;
			v.push_back(x);
		}
		grid.push_back(v);
	}
	int ans = grid_cost(grid, n, m);
	cout << ans;
	return 0;
}