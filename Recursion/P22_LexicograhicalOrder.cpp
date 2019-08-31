#include<bits/stdc++.h>
using namespace std;

void printNum(int n, int x) {
	if (x > n)
		return;
	if (x == n){
		cout << n << " ";
		return;
	}
	
	cout << x << " ";
	for (int i = (x == 0) ? 1 : 0; i <= 9; i++)
		printNum(n, x*10+i);
}

int main() {
	int n;
	cin >> n;
	printNum(n, 0);
	return 0;
}