#include<bits/stdc++.h>
using namespace std;

int count1(vector<int> arr, int n, int k, int len) {

	int x = 0;
	if(arr[n-1] == 1)
		return 1+count1(arr, n-1, k);
	else {
		if(k > 0)
			x = 1+count(arr, n-1, k-1);
		x = max(x, count())
	}
}

int main() {
	int i, n, k, x;
	vector<int> arr;
	cin >> n >> k;
	for(i = 0; i < n; ++i) {
		cin >> x;
		arr.push_back(x);
	}
	cout << count1(arr, n-1, k, 0);
	return 0;
}