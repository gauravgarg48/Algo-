#include<iostream>
using namespace std;

int maxCoins(int *a, int i, int j, int t) {
	if(i == j) {
		if(t == 1)
			return a[i];
		else
			return 0;
	}

	if(t == 1) {
		if(a[i] >= a[j])
			return a[i] + maxCoins(a, i+1, j, 2);
		else
			return a[j] + maxCoins(a, i, j-1, 2);
	} else {
		if(a[i] >= a[j])
			return maxCoins(a, i+1, j, 1);
		else
			return maxCoins(a, i, j-1, 1);
	}
}

int main() {
	int i, n;
	cin >> n;
	int arr[n];
	for(i = 0; i < n; ++i)
		cin >> arr[i];
	cout << maxCoins(arr, 0, n-1, 1);
	return 0;
}