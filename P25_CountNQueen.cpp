#include<bits/stdc++.h>
using namespace std;

bool isSafe(int arr[][100], int r, int c, int n) {
	int i, j;
	for(i = 0; i < r; ++i)
		if(arr[i][c] == 1)
			return false;
	for(i = r, j = c; i >= 0 && j >= 0; --i, --j)
		if(arr[i][j] == 1)
			return false;
	for(i = r, j = c; i >= 0 && j < n; --i, ++j)
		if(arr[i][j] == 1)
			return false;
	return true;
}

int cnt = 0;
bool print(int arr[][100], int row, int n) {
	int i, j;
	if(row == n) {
		cnt++;
		return false;
	}

	for(i = 0; i < n; ++i) {
		if(isSafe(arr, row, i, n)) {
			arr[row][i] = 1;
			if(print(arr, row+1, n))
				return true;
			arr[row][i] = 0;
		}
	}
	return false;
}

int main() {
	int n, i;
	cin >> n;
	int arr[100][100];
	memset(arr, 0, n*n*sizeof(int));
	print(arr, 0, n);
	cout << cnt;
	return 0;
}