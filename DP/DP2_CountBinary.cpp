#include <bits/stdc++.h> 
using namespace std; 
int countBin(int n) {
	int dp[n+1], i;
	dp[0] = 0;
	dp[1] = 2;
	dp[2] = 3;
	for(i = 3; i <= n; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}
int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n == 1)
			cout << 2;
		if(n == 2)
			cout << 3;
		else
			cout << countBin(n);
		cout << endl;
	}
}