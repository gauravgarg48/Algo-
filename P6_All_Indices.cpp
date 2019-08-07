#include<iostream>
#include<vector>
using namespace std;

void allIndices(int in[], int n, int x) {
	if(n == 0)
		return;
	allIndices(in, n-1, x);
	if(in[n-1] == x)
		cout << n-1 << " ";
	return;
	
}

int main() { 
	int n, i, x;
	int in[1000];
	cin >> n;
	for(i = 0; i < n; ++i)
		cin >> in[i];
	cin >> x;
	allIndices(in, n, x);
	return 0;
}