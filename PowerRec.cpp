#include<iostream>
using namespace std;

// Time - O(n)
long power(int a, int b) {
	if(b == 0) return 1;
	return a*power(a, b-1);
}

// Time - O(log n)
long fastPower(int a, int b) {
	if(b == 1) return a;
	long x = fastPower(a, b/2);
	if(b%2 == 0)
		return x*x;
	else
		return a*x*x;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << power(a, b) << endl;
	cout << fastPower(a, b);
	return 0;
}