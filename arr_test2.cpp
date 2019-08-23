#include<iostream>
using namespace std;

// Multiply a matrix with its transpose
void matrixMul() {
	int i, j, n, m, k = 1, x;
	cin >> n >> m;
	int arr[n][m];
	for(i = 0; i < n; ++i)
		for(j = 0; j < m; ++j)
			arr[i][j] = k++;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			x = 0;
			for(k = 0; k < m; ++k)
				x += arr[i][k]*arr[j][k];
			cout << x << " ";
		}
		cout << endl;
	}
	return;
}

void printPat() {
	int i, j, n, m, k = 1, x;
	cin >> n;
	int arr[n][n];
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			arr[i][j] = k++;
	for(i = 0; i < n; i+=2) {
		for(j = 0; j < n-1; ++j)
			cout << arr[i][j] << "*";
		cout << arr[i][j] << endl;
	}
	i = n-2;
	if(n%2 == 0)
		i++;
	for(; i >= 1; i-=2) {
		for(j = 0; j < n-1; ++j)
			cout << arr[i][j] << "*";
		cout << arr[i][j] << endl;
	}
	return;
}

int main() {
	//matrixMul();
	printPat();
	return 0;
}