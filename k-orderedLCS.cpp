#include<bits/stdc++.h>
using namespace std;
int n, m;
long s1[2005], s2[2005];
long dp[2005][2005][8];

long kLCS(int i, int j, int k) {
	if(i >= n || j >= m)
		return 0;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	long ans = 0;
	if(s1[i] == s2[j])
		ans = 1+kLCS(i+1, j+1, k);
	else {
		if(k > 0)
			ans = 1 + kLCS(i+1, j+1, k-1);
		ans = max(ans, kLCS(i, j+1, k));
		ans = max(ans, kLCS(i+1, j, k));
	}
	dp[i][j][k] = ans;
	return ans;
}

int main() {
	int i, k;
	cin >> n >> m >> k;
	for(i = 0; i < n; ++i)
		cin >> s1[i];
	for(i = 0; i < m; ++i)
		cin >> s2[i];
	memset(dp, -1, sizeof(dp));
	cout << kLCS(0, 0, k);
	return 0;
}