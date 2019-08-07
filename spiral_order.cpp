#include <bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX = 30;

vector<int> spiral_order(const vector<vector<int> > &A) {
	int r1 = 0, c1 = 0, rn = A.size()-1, cn = A[0].size()-1, dir = 0, i, j;
	vector<int> ans;
	while(r1 <= rn && c1 <= cn) {
		if(dir == 0) {
			for(i = r1, j = c1; j <= cn; ++j)
				ans.push_back(A[i][j]);
			r1++;
		}
		else if(dir == 1) {
			for(i = r1, j = cn; i <= rn; ++i)
				ans.push_back(A[i][j]);
			cn--;
		}
		else if(dir == 2) {
			for(i = rn, j = cn; j >= c1; --j)
				ans.push_back(A[i][j]);
			rn--;
		}
		else {
			for(i = rn, j = c1; i >= r1; --i)
				ans.push_back(A[i][j]);
			c1++;
		}
		dir = (dir+1)%4;
	}
	return ans;
}

int main() {
	const vector<vector<int> > A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> ans = spiral_order(A);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
	return 0;
}