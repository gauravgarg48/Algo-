#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int n, x, y, z;
long compute() {
	long *dp = new long[n+1];
	dp[0] = 0;
	dp[1] = 0;
	for(int i = 2; i <= n; ++i) {
		if(i%2 == 0)
			dp[i] = min(dp[i/2]+x, dp[i-1]+y);
		else
			dp[i] = min(dp[(i+1)/2]+x+z, dp[i-1]+y);
	}
	return dp[n];
}

int main() {
	cin >> n >> x >> y >> z;
	cout << compute();
	return 0;
}