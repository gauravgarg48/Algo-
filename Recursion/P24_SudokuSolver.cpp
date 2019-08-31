#include<bits/stdc++.h>
using namespace std;

bool solveSudoku(int **arr, int r, int c, int n) {
	int i, j, k, n1, n2, sq = sqrt(n);
	if(r == n) {
		for(i = 0; i < n; ++i) {
			for(j = 0; j < n; ++j)
				cout << arr[i][j] << " ";
			cout << endl;
		}
		return true;
	}
	if(c == n)
		return solveSudoku(arr, r+1, 0, n);
	if(arr[r][c] != 0)
		return solveSudoku(arr, r, c+1, n);

	bool flag;
	for(k = 1; k <= n; ++k) {
		flag = true;
		for(i = 0; i < n; ++i)
			if(arr[r][i] == k || arr[i][c] == k)
				flag = false;
		i = r-r%r;
		j = c-c%r;
		n1 = i+r;
		n2 = j+r;
		for(; i < n1; ++i)
			for(; j < n2; ++j)
				if(arr[i][j] == k)
					flag = false;
		if(flag) {
			arr[r][c] = k;
			if(solveSudoku(arr, r, c+1, n))
				return true;
		}
		arr[r][c] = 0;
	}
	return false;
}

int main() {
	int n, i, j;
	cin >> n;
	int **arr = new int*[n];
	for(i = 0; i < n; ++i)
		arr[i] = new int[n];
	for(i = 0; i < n; i++)
		for(j = 0; j < n; ++j)
			cin >> arr[i][j];
	solveSudoku(arr, 0, 0, n);
	return 0;
}