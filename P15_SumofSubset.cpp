#include<iostream>
using namespace std;

int c = 0;
void sumOfSubset(int* a, int i, int end, int sum) {
	if(i == end){
		if(sum == 0)
			c++;
		return;
	}

	sumOfSubset(a, i+1, end, sum + a[i]);
	sumOfSubset(a, i+1, end, sum);
	return;
}

int main() {
	int t, n, i;
	cin >> t;
	while(t-- > 0) {
		cin >> n;
		int a[n];
		for(i = 0; i < n; ++i)
			cin >> a[i];
		sumOfSubset(a, 0, n, 0);
		if(c >= 2)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}