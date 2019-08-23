#include<bits/stdc++.h>
using namespace std;

int LISRec(int arr[], int i, int n) {
	if(i == 0)
		return 1;
	int len, ans = 1, j;
	for(j = 0; j < i; ++j) {
		if(arr[j] < arr[i])
			len = 1+LISRec(arr, j, n);
		if(len > ans)
			ans = len;
	}
	return ans;
}

int LIS(int arr[], int n) {
	int i, ans = -1, j, dp[n+1];
	for(i = 0; i < n; ++i)
		dp[i] = 1;
	for(i = 1; i < n; ++i) {
		for(j = 0; j < i; ++j) {
			if(arr[j] <= arr[i]) {
				int cur = 1+dp[j];
				dp[i] = max(dp[i], cur);
			}
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	int i, n, len;
	cin >> n;
	int arr[n];
	for(i = 0; i < n; ++i)
		cin >> arr[i];
	len = LIS(arr, n);
	cout << len;
}