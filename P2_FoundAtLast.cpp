#include<iostream>
using namespace std;

int findLastInd(int arr[], int n, int m) {
	if(n < 0)
		return -1;

	if(arr[n] == m)
		return n;
	else
		return findLastInd(arr, n-1, m);
}

int main() {
	int n, i, m, arr[1000];
	cin >> n; 
	for(i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> m;
	cout << findLastInd(arr, n-1, m);
	return 0;
}