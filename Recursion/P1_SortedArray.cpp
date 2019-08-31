#include<iostream>
using namespace std;

bool isSorted(int arr[], int n) {
	if(n == 0)
		return true;

	if(arr[n] >= arr[n-1] && isSorted(arr, n-1))
		return true;
	return false;
}

int main() {
	int n, i, arr[1000];
	cin >> n; 
	for(i = 0; i < n; ++i)
		cin >> arr[i];
	if(isSorted(arr, n-1))
		cout << "true";
	else
		cout << "false";
	return 0;
}