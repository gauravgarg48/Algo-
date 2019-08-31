#include<bits/stdc++.h>
using namespace std;
int main() {
	int t, n, i, x;
	long sum, count;
	cin >> t;
	while(t--) {
		cin >> n;
		int arr[n];
		count = sum = 0;
		memset(arr, 0, sizeof arr);
		arr[0] = 1;
		for(i = 0; i < n; ++i) {
			cin >> x;
			sum = (sum+x)%n;
			while(sum < 0)
				sum += n*n;
			arr[sum%n]++;
		}
		for(i = 0; i < n; ++i)
			count += arr[i]*(arr[i]-1)/2;
		cout << count << endl;
	}
	return 0;
}