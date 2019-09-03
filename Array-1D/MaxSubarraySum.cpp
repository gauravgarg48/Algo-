#include<iostream>
using namespace std;
// Kadane's Algorithm
int main() {
	int arr[100], n, i, csum, msum, l, r, x;
	csum = msum = 0;
	l = r = -1;
	cin >> n;
	for(i = 0; i < n; ++i) {
		cin >> arr[i];
		csum += arr[i];
		if(csum < 0) {
			csum = 0;
			x = i+1;
		}
		if(csum > msum) {
			msum = csum;
			l = x;
			r = i;
		}
	}
	cout << msum << endl;
	if(l == -1 && r != -1)
		l = 0;
	for(i = l; i <= r; ++i)
		cout << arr[i] << " ";
	return 0;
}