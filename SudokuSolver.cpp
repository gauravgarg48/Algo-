#include<iostream>
#include<cmath>
using namespace std;

bool solveSudoku(int mat[][9], int i, int j, int n) {
	if(i == n) {
		for(i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cout << mat[i][j] << ", ";
			cout << endl;
		}
		cout << endl << endl;
		return true;
	}

	if(j == n)
		return solveSudoku(mat, i+1, 0, n);

	if(mat[i][j] != 0)
		return solveSudoku(mat, i, j+1, n);

	bool flag;
	int x, y, sx, sy, rn = sqrt(n);
	for(int num = 1; num <= n; ++num) {
		flag = true;
		for(x = 0; x < n; ++x)
			if(mat[x][j] == num || mat[i][x] == num)
				flag = false;
		sx = (i/rn)*rn;
		sy = (j/rn)*rn;
		for(x = sx; x < sx+rn; ++x)
			for(y = sy; y < sy+rn; ++y)
				if(mat[x][y] == num)
					flag = false;
		if(flag) {
			mat[i][j] = num;
			flag = solveSudoku(mat, i, j+1, n);
			if(flag)
				return true;
		}
	}
	mat[i][j] = 0;
	return false;
}

int main() {
	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9},
	};
	int n = 9;
	solveSudoku(mat, 0, 0, n);
	return 0;
}