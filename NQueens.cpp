#include<iostream>
using namespace std;

bool nQueens(int sol[][30], int i, int n) {
	if(i == n) {
		for(i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				cout << sol[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		return false;
	}

	bool flag;
	for(int j = 0; j < n; ++j) {
		flag = true;
		for(int k = 0; k <= i; ++k) {
			if(sol[i-k][j-k] == 1 || sol[i-k][j] == 1
				|| sol[i-k][j+k] == 1)
				flag = false;
		}
		if(flag) {
			sol[i][j] = 1;
			flag = nQueens(sol, i+1, n);
			if(flag)
				return true;
			sol[i][j] = 0;
		}
	}
	return false;
}

int main() {
	int sol[30][30] = {0};
	int n;
	cin >> n;
	nQueens(sol, 0, n);
	return 0;
}