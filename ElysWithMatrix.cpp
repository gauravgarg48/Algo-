#include<iostream>
#include<vector>
using namespace std;

void func(vector<vector<int>> a, int r, int c) {
	
}

int main() {
	int r, c, i, j, x;
	vector<vector<int>> a;
	cin >> r >> c;
	for(i = 0; i < r; ++i)
		for(j = 0; j < c; ++j) {
			cin >> x;
			a[i].push_back(x);
		}
	func(a, r, c);
	return 0;
}